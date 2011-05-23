--- src/socket.c.orig	2009-08-04 15:31:46.000000000 +0400
+++ src/socket.c	2009-08-12 19:43:02.000000000 +0400
@@ -33,8 +33,6 @@
   side, and the server is half cone and the client is symmetric.
 */
 
-#define _XOPEN_SOURCE 500
-
 #include "grapple_configure_substitute.h"
 
 #include <stdio.h>
