--- Examples/TestBed/Tests/BroadPhaseTest.cpp.orig	2010-02-10 20:57:13.000000000 +0300
+++ Examples/TestBed/Tests/BroadPhaseTest.cpp	2010-02-10 20:57:42.000000000 +0300
@@ -19,6 +19,8 @@
 #include "BroadPhaseTest.h"
 
 #include <cstdio>
+#include <cstring>
+
 const float32 k_width = 1.0f;
 
 inline void GetRandomAABB(b2AABB* aabb)
