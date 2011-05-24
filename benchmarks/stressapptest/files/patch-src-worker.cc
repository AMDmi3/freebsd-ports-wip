--- src/worker.cc	(revision 24)
+++ src/worker.cc	(working copy)
@@ -30,6 +30,9 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/times.h>
+#include <sys/param.h>
+#include <sys/cpuset.h>
+#include <sys/disk.h>
 
 // These are necessary, but on by default
 // #define __USE_GNU
@@ -38,13 +41,12 @@
 #include <sys/socket.h>
 #include <netdb.h>
 #include <arpa/inet.h>
-#include <linux/unistd.h>  // for gettid
+#include <netinet/in.h>
 
 // For size of block device
 #include <sys/ioctl.h>
-#include <linux/fs.h>
 // For asynchronous I/O
-#include <linux/aio_abi.h>
+#include <aio.h>
 
 #include <sys/syscall.h>
 
@@ -410,9 +412,9 @@
 //   mask = 3  (11b):   cpu0, 1
 //   mask = 13 (1101b): cpu0, 2, 3
 uint32 WorkerThread::AvailableCpus() {
-  cpu_set_t curr_cpus;
+  cpuset_t curr_cpus;
   CPU_ZERO(&curr_cpus);
-  sched_getaffinity(getppid(), sizeof(curr_cpus), &curr_cpus);
+  cpuset_getaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID, getppid(), sizeof(curr_cpus), &curr_cpus);
   return cpuset_to_uint32(&curr_cpus);
 }
 
@@ -422,9 +424,9 @@
 //   mask = 3  (11b):   cpu0, 1
 //   mask = 13 (1101b): cpu0, 2, 3
 uint32 WorkerThread::CurrentCpus() {
-  cpu_set_t curr_cpus;
+  cpuset_t curr_cpus;
   CPU_ZERO(&curr_cpus);
-  sched_getaffinity(0, sizeof(curr_cpus), &curr_cpus);
+  cpuset_getaffinity(CPU_LEVEL_WHICH, CPU_WHICH_TID, -1, sizeof(curr_cpus), &curr_cpus);
   return cpuset_to_uint32(&curr_cpus);
 }
 
@@ -449,9 +451,9 @@
               thread_mask, process_mask);
     return false;
   }
-  cpu_set_t cpuset;
+  cpuset_t cpuset;
   cpuset_from_uint32(thread_mask, &cpuset);
-  return (sched_setaffinity(gettid(), sizeof(cpuset), &cpuset) == 0);
+  return (cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_TID, gettid(), sizeof(cpuset), &cpuset) == 0);
 }
 
 
@@ -2484,7 +2486,7 @@
   device_sectors_ = 0;
   non_destructive_ = 0;
 
-  aio_ctx_ = 0;
+  //aio_ctx_ = 0;
   block_table_ = block_table;
   update_block_table_ = 1;
 
@@ -2618,7 +2620,7 @@
 
 bool DiskThread::OpenDevice(int *pfile) {
   int fd = open(device_name_.c_str(),
-                O_RDWR | O_SYNC | O_DIRECT | O_LARGEFILE,
+                O_RDWR | O_SYNC | O_DIRECT,
                 0);
   if (fd < 0) {
     logprintf(0, "Process Error: Failed to open device %s (thread %d)!!\n",
@@ -2644,7 +2646,7 @@
   if (S_ISBLK(device_stat.st_mode)) {
     uint64 block_size = 0;
 
-    if (ioctl(fd, BLKGETSIZE64, &block_size) == -1) {
+    if (ioctl(fd, DIOCGMEDIASIZE, &block_size) == -1) {
       logprintf(0, "Process Error: Unable to ioctl disk %s (thread %d).\n",
                 device_name_.c_str(), thread_num_);
       return false;
@@ -2797,12 +2799,13 @@
 // Do an asynchronous disk I/O operation.
 bool DiskThread::AsyncDiskIO(IoOp op, int fd, void *buf, int64 size,
                             int64 offset, int64 timeout) {
+  return false;
   // Use the Linux native asynchronous I/O interface for reading/writing.
   // A read/write consists of three basic steps:
   //    1. create an io context.
   //    2. prepare and submit an io request to the context
   //    3. wait for an event on the context.
-
+/*
   struct {
     const int opcode;
     const char *op_str;
@@ -2812,7 +2815,7 @@
     { IOCB_CMD_PWRITE, "write", "disk-write-error" }
   };
 
-  struct iocb cb;
+  struct aiocb cb;
   memset(&cb, 0, sizeof(cb));
 
   cb.aio_fildes = fd;
@@ -2821,8 +2824,13 @@
   cb.aio_nbytes = size;
   cb.aio_offset = offset;
 
-  struct iocb *cbs[] = { &cb };
-  if (io_submit(aio_ctx_, 1, cbs) != 1) {
+  int aioret;
+  if (op == ASYNC_IO_READ)
+    aioret = aio_read(&cb);
+  else
+    aioret = aio_write(&cb);
+
+  if (aioret != 0) {
     logprintf(0, "Process Error: Unable to submit async %s "
                  "on disk %s (thread %d).\n",
               operations[op].op_str, device_name_.c_str(),
@@ -2856,8 +2864,8 @@
     // Since io_cancel is always failing, destroying and recreating an I/O
     // context is a workaround for canceling an in-progress I/O operation.
     // TODO(amistry): Find out why io_cancel isn't working and make it work.
-    io_cancel(aio_ctx_, &cb, &event);
-    io_destroy(aio_ctx_);
+    aio_cancel(aio_ctx_, &cb, &event);
+    aio_destroy(aio_ctx_);
     aio_ctx_ = 0;
     if (io_setup(5, &aio_ctx_)) {
       logprintf(0, "Process Error: Unable to create aio context on disk %s"
@@ -2897,7 +2905,7 @@
     return false;
   }
 
-  return true;
+  return true;*/
 }
 
 // Write a block to disk.
@@ -3053,7 +3061,8 @@
     return false;
   }
 
-  if (io_setup(5, &aio_ctx_)) {
+  //if (io_setup(5, &aio_ctx_)) {
+  if (1) {
     logprintf(0, "Process Error: Unable to create aio context for disk %s"
               " (thread %d).\n",
               device_name_.c_str(), thread_num_);
@@ -3064,7 +3073,7 @@
 
   status_ = 1;
 
-  io_destroy(aio_ctx_);
+  //io_destroy(aio_ctx_);
   CloseDevice(fd);
   free(block_buffer_);
 
Index: src/worker.h
===================================================================
