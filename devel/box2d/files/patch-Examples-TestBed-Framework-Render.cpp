--- Examples/TestBed/Framework/Render.cpp.orig	2010-02-10 20:57:13.000000000 +0300
+++ Examples/TestBed/Framework/Render.cpp	2010-02-10 20:58:02.000000000 +0300
@@ -26,6 +26,7 @@
 
 #include <cstdio>
 #include <cstdarg>
+#include <cstring>
 
 void DebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
 {
