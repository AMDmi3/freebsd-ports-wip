--- src/worker.h	(revision 24)
+++ src/worker.h	(working copy)
@@ -26,7 +26,7 @@
 #include <sys/time.h>
 #include <sys/types.h>
 
-#include <linux/aio_abi.h>
+#include <aio.h>
 
 #include <queue>
 #include <set>
@@ -727,7 +727,7 @@
                                                 // not verified.
   void *block_buffer_;        // Pointer to aligned block buffer.
 
-  aio_context_t aio_ctx_;     // Asynchronous I/O context for Linux native AIO.
+  //aio_context_t aio_ctx_;;    // Asynchronous I/O context for Linux native AIO.
 
   DiskBlockTable *block_table_;  // Disk Block Table, shared by all disk
                                  // threads that read / write at the same
Index: src/sattypes.h
===================================================================
