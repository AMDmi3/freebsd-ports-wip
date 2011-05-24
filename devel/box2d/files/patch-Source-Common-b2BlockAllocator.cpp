--- Source/Common/b2BlockAllocator.cpp.orig	2007-11-24 11:25:02.000000000 +0300
+++ Source/Common/b2BlockAllocator.cpp	2010-02-10 20:56:46.000000000 +0300
@@ -18,7 +18,7 @@
 
 #include "b2BlockAllocator.h"
 #include <cstdlib>
-#include <memory>
+#include <cstring>
 #include <climits>
 
 int32 b2BlockAllocator::s_blockSizes[b2_blockSizes] = 
