--- lib/libnids-1.21_patched/configure.gnu.orig	2011-10-16 20:59:40.000000000 +0400
+++ lib/libnids-1.21_patched/configure.gnu	2013-12-17 22:23:00.114949266 +0400
@@ -1,3 +1,3 @@
 #!/bin/sh
 
-./configure --disable-libnet --disable-libglib $@
\ No newline at end of file
+./configure --disable-libnet --disable-libglib "$@"
