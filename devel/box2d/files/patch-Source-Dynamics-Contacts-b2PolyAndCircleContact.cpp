--- Source/Dynamics/Contacts/b2PolyAndCircleContact.cpp.orig	2008-04-12 14:29:14.000000000 +0400
+++ Source/Dynamics/Contacts/b2PolyAndCircleContact.cpp	2010-02-10 20:55:29.000000000 +0300
@@ -21,6 +21,7 @@
 #include "../b2WorldCallbacks.h"
 #include "../../Common/b2BlockAllocator.h"
 
+#include <cstring>
 #include <new>
 
 b2Contact* b2PolyAndCircleContact::Create(b2Shape* shape1, b2Shape* shape2, b2BlockAllocator* allocator)
