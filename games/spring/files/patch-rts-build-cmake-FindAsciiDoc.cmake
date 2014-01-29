--- rts/build/cmake/FindAsciiDoc.cmake.orig	2014-01-21 04:14:14.565653965 +0400
+++ rts/build/cmake/FindAsciiDoc.cmake	2014-01-21 04:19:12.087634189 +0400
@@ -41,6 +41,7 @@
 	PATH_SUFFIXES
 		xml/docbook/stylesheet/nwalsh/manpages
 		sgml/docbook/xsl-stylesheets/manpages
+		xsl/docbook/manpages
 	DOC "DocBook XSL Style-Sheet"
 	)
 
