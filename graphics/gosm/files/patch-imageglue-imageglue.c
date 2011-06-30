--- imageglue/imageglue.c.orig	2009-10-28 17:26:36.000000000 +0300
+++ imageglue/imageglue.c	2011-06-29 22:04:22.000000000 +0400
@@ -94,7 +94,7 @@
 	}
 	*info_ptr = png_create_info_struct(*png_ptr);
 	if (*info_ptr == NULL){
-		png_destroy_write_struct(png_ptr, png_infopp_NULL);
+		png_destroy_write_struct(png_ptr, NULL);
 		return -1;
 	}
 	if (setjmp(png_jmpbuf(*png_ptr))){
