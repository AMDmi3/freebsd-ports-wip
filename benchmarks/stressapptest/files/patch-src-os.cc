--- src/os.cc	(revision 24)
+++ src/os.cc	(working copy)
@@ -22,8 +22,6 @@
 
 #include <errno.h>
 #include <fcntl.h>
-#include <linux/types.h>
-#include <malloc.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -170,7 +168,7 @@
 }
 
 // Report which cores are associated with a given region.
-cpu_set_t *OsLayer::FindCoreMask(int32 region) {
+cpuset_t *OsLayer::FindCoreMask(int32 region) {
   sat_assert(region >= 0);
   region %= num_nodes_;
   if (!cpu_sets_valid_[region]) {
@@ -232,7 +230,7 @@
     return totalmemsize_;
 
   int64 pages = sysconf(_SC_PHYS_PAGES);
-  int64 avpages = sysconf(_SC_AVPHYS_PAGES);
+  int64 avpages = 0; // sysconf(_SC_AVPHYS_PAGES) not supported on FreeBSD
   int64 pagesize = sysconf(_SC_PAGESIZE);
   int64 physsize = pages * pagesize;
   int64 avphyssize = avpages * pagesize;
@@ -341,11 +339,10 @@
 
   if (!use_hugepages_) {
     // Use memalign to ensure that blocks are aligned enough for disk direct IO.
-    buf = static_cast<char*>(memalign(4096, length));
-    if (buf)
+    if (posix_memalign(&buf, 4096, length) == 0)
       logprintf(0, "Log: Using memaligned allocation at %p.\n", buf);
     else
-      logprintf(0, "Process Error: memalign returned 0\n");
+      logprintf(0, "Process Error: posix_memalign failed\n");
   }
 
   testmem_ = buf;
Index: src/os.h
===================================================================
