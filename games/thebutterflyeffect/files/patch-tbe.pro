--- tbe.pro.orig	2010-12-05 14:26:34.000000000 +0300
+++ tbe.pro	2011-05-24 22:19:51.000000000 +0400
@@ -1,8 +1,7 @@
 TEMPLATE = app
 LANGUAGE = C++
 CONFIG += qt \
-    warn_on \
-    debug
+    warn_on
 LIBS += -lbox2d \
     -L3rdParty/lib
 DEFINES += QT_NO_ASCII_CAST
