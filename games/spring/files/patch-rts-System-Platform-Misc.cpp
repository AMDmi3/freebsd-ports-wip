--- rts/System/Platform/Misc.cpp.orig	2014-01-25 06:12:23.940347681 +0400
+++ rts/System/Platform/Misc.cpp	2014-01-25 06:16:21.018809302 +0400
@@ -29,6 +29,7 @@
 #include <dlfcn.h> // for dladdr(), dlopen()
 #include <sys/types.h>
 #include <sys/sysctl.h>
+#include <sys/syslimits.h> // for PATH_MAX
 
 #else
 
