--- Source/Collision/b2BroadPhase.cpp.orig	2008-03-10 21:42:36.000000000 +0300
+++ Source/Collision/b2BroadPhase.cpp	2010-02-10 20:57:11.000000000 +0300
@@ -18,6 +18,7 @@
 
 #include "b2BroadPhase.h"
 #include <algorithm>
+#include <cstring>
 
 // Notes:
 // - we use bound arrays instead of linked lists for cache coherence.
