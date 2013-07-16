--- src/misc.cpp.orig	2012-11-29 10:25:15.000000000 +0400
+++ src/misc.cpp	2013-07-16 23:44:59.492227410 +0400
@@ -283,7 +283,7 @@
 	}
 	strcpy(path_home, path_app);
 	
-#elif defined(__linux__)
+#elif defined(__linux__) || defined (__FreeBSD__)
 #if defined(IICHANTRA_INSTALL)
 	strcpy(path_app, DEFAULT_LINUX_APPLICATION_DATA_PATH);
 	strcpy(path_home, getenv("HOME"));
