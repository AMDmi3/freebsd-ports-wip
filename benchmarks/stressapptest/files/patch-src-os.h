--- src/os.h	(revision 24)
+++ src/os.h	(working copy)
@@ -74,7 +74,7 @@
   // This may mean different things on different platforms.
   virtual int32 FindRegion(uint64 paddr);
   // Find cpu cores associated with a region. Either NUMA or arbitrary.
-  virtual cpu_set_t *FindCoreMask(int32 region);
+  virtual cpuset_t *FindCoreMask(int32 region);
 
   // Returns the HD device that contains this file.
   virtual string FindFileDevice(string filename);
@@ -244,7 +244,7 @@
 
   time_t time_initialized_;  // Start time of test.
 
-  vector<cpu_set_t> cpu_sets_;   // Cache for cpu masks.
+  vector<cpuset_t> cpu_sets_;   // Cache for cpu masks.
   vector<bool> cpu_sets_valid_;  // If the cpu mask cache is valid.
 
   // Get file descriptor for dev msr.
Index: src/sat.cc
===================================================================
