--- src/defines.h.orig	2012-11-29 10:25:15.000000000 +0400
+++ src/defines.h	2013-07-16 23:43:58.877176186 +0400
@@ -72,7 +72,7 @@
 #define DEFAULT_WINDOW_HEIGHT		480
 
 // —тандартные пути после установки в Linux-системе
-#if defined(LINUX)
+#if defined(LINUX) || defined(__FreeBSD__)
 #define DEFAULT_LINUX_APPLICATION_PATH		"/usr/games/"
 #define DEFAULT_LINUX_APPLICATION_DATA_PATH	"/usr/share/games/iichantra/bin/"
 #define DEFAULT_LINUX_IICHANTRA_PATH		".iichantra/"
