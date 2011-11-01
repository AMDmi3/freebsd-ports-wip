--- makepanda/makepanda.py.orig	2011-04-14 13:38:28.000000000 +0400
+++ makepanda/makepanda.py	2011-11-01 03:03:59.000000000 +0400
@@ -352,6 +352,9 @@
 ##
 ########################################################################
 
+IncDirectory("ALWAYS", GetOutputDir()+"/tmp")
+IncDirectory("ALWAYS", GetOutputDir()+"/include")
+
 if (COMPILER=="MSVC"):
     PkgDisable("X11")
     PkgDisable("XRANDR")
@@ -646,8 +649,6 @@
 
 DefSymbol("ALWAYS", "MAKEPANDA", "")
 DefSymbol("WITHINPANDA", "WITHIN_PANDA", "1")
-IncDirectory("ALWAYS", GetOutputDir()+"/tmp")
-IncDirectory("ALWAYS", GetOutputDir()+"/include")
 if GetLinkAllStatic():
     DefSymbol("ALWAYS", "LINK_ALL_STATIC", "")
 
