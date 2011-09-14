--- src/grapple_message.h.orig	2009-08-04 15:31:46.000000000 +0400
+++ src/grapple_message.h	2011-09-14 05:08:12.000000000 +0400
@@ -25,6 +25,8 @@
 
 #include "grapple_types.h"
 
+#include <stddef.h> /* for size_t */
+
 typedef enum
   {
     GRAPPLE_MSG_NONE                 =  0,
