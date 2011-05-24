--- Source/Dynamics/Contacts/b2PolyContact.cpp.orig	2008-04-10 23:38:38.000000000 +0400
+++ Source/Dynamics/Contacts/b2PolyContact.cpp	2010-02-10 19:29:13.000000000 +0300
@@ -21,7 +21,7 @@
 #include "../b2WorldCallbacks.h"
 #include "../../Common/b2BlockAllocator.h"
 
-#include <memory>
+#include <cstring>
 #include <new>
 
 b2Contact* b2PolygonContact::Create(b2Shape* shape1, b2Shape* shape2, b2BlockAllocator* allocator)
