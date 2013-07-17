--- oc3_filenative_impl.cpp.orig	2013-07-13 21:59:29.000000000 +0400
+++ oc3_filenative_impl.cpp	2013-07-16 00:25:19.203112853 +0400
@@ -20,6 +20,7 @@
 #define getline_def getline_win
 #else
 #define getline_def getline
+#include <stdio.h>
 #endif
 
 namespace io
@@ -241,4 +242,4 @@
     fflush( _file );
 }
 
-} //end namespace io
\ No newline at end of file
+} //end namespace io
