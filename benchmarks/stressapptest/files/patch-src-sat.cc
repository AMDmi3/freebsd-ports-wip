--- src/sat.cc	(revision 24)
+++ src/sat.cc	(working copy)
@@ -77,7 +77,7 @@
   // Open logfile.
   if (use_logfile_) {
     logfile_ = open(logfilename_,
-                    O_WRONLY | O_CREAT | O_DSYNC,
+                    O_WRONLY | O_CREAT | O_SYNC,
                     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
     if (logfile_ < 0) {
       printf("Fatal Error: cannot open file %s for logging\n",
@@ -1088,7 +1088,7 @@
 
     if ((region_count_ > 1) && (region_mode_)) {
       int32 region = region_find(i % region_count_);
-      cpu_set_t *cpuset = os_->FindCoreMask(region);
+      cpuset_t *cpuset = os_->FindCoreMask(region);
       sat_assert(cpuset);
       int32 cpu_mask = cpuset_to_uint32(cpuset);
       if (region_mode_ == kLocalNuma) {
@@ -1692,8 +1692,8 @@
   sigaddset(&new_blocked_signals, SIGTERM);
   sigset_t prev_blocked_signals;
   pthread_sigmask(SIG_BLOCK, &new_blocked_signals, &prev_blocked_signals);
-  sighandler_t prev_sigint_handler = signal(SIGINT, SatHandleBreak);
-  sighandler_t prev_sigterm_handler = signal(SIGTERM, SatHandleBreak);
+  sig_t prev_sigint_handler = signal(SIGINT, SatHandleBreak);
+  sig_t prev_sigterm_handler = signal(SIGTERM, SatHandleBreak);
 
   // Kick off all the worker threads.
   logprintf(12, "Log: Launching worker threads\n");
