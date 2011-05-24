--- src/sattypes.h	(revision 24)
+++ src/sattypes.h	(working copy)
@@ -20,6 +20,8 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/types.h>
+#include <sys/param.h>
+#include <sys/cpuset.h>
 #include <time.h>
 #include <string.h>
 #include <string>
@@ -95,7 +97,7 @@
 #endif
 
 // Make using CPUSET non-super-painful.
-static inline uint32 cpuset_to_uint32(cpu_set_t *cpuset) {
+static inline uint32 cpuset_to_uint32(cpuset_t *cpuset) {
   uint32 value = 0;
   for (int index = 0; index < CPU_SETSIZE; index++) {
     if (CPU_ISSET(index, cpuset)) {
@@ -110,7 +112,7 @@
   return value;
 }
 
-static inline void cpuset_from_uint32(uint32 mask, cpu_set_t *cpuset) {
+static inline void cpuset_from_uint32(uint32 mask, cpuset_t *cpuset) {
   CPU_ZERO(cpuset);
   for (int index = 0; index < 32; index++) {
     if (mask & (1 << index))
@@ -143,7 +145,8 @@
 //   error_num: an errno error code
 inline string ErrorString(int error_num) {
   char buf[256];
-  return string(strerror_r(error_num, buf, sizeof buf));
+  strerror_r(error_num, buf, sizeof buf);
+  return string(buf);
 }
 
 // Define handy constants here
Index: src/os.cc
===================================================================
