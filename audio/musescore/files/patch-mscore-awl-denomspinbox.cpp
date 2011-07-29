--- mscore/awl/denomspinbox.cpp.orig	2011-07-27 17:32:23.000000000 +0400
+++ mscore/awl/denomspinbox.cpp	2011-07-28 23:50:11.000000000 +0400
@@ -20,6 +20,8 @@
 
 #include "denomspinbox.h"
 
+#define log2(x) (log(x)/log(2.0))
+
 namespace Awl {
 
 //---------------------------------------------------------
