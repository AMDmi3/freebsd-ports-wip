--- setup.py.orig	2010-01-10 09:24:54.000000000 +0300
+++ setup.py	2010-10-29 04:31:08.000000000 +0400
@@ -150,15 +150,8 @@
 	
 	#Fix for Debian based distros
 	tcl_include_dirs = []
-	tcl_ver=''
-	if os.path.isdir('/usr/include/tcl8.5'):
-		tcl_include_dirs = ['/usr/include/tcl8.5']
-		tcl_ver ='8.5'
-		
-	if os.path.isdir('/usr/include/tcl8.6'):
-		tcl_include_dirs = ['/usr/include/tcl8.6']
-		tcl_ver ='8.6'
-
+	tcl_ver=os.environ['TCL_VER']
+	tk_ver=os.environ['TK_VER']
  
  	type1mod_src=src_path+'extentions/type1mod/'				
 	type1mod_module = Extension('sk1.app.modules._type1module',
@@ -184,7 +177,7 @@
 						('MINOR_VERSION', '9')],
 			sources = [paxtkinter_src+'paxtkinter.c'],
 			include_dirs = tcl_include_dirs,
-			libraries=['X11', 'tk'+tcl_ver, 'tcl'+tcl_ver])
+			libraries=['X11', 'tk'+tk_ver, 'tcl'+tcl_ver])
 			
  	ft2_src=src_path+'extentions/freetype2/'				
 	ft2_module = Extension('sk1.app.modules.ft2',
@@ -207,7 +200,7 @@
 					pax_src+'paxutil.c', pax_src+'pixmapobject.c', pax_src+'regionobject.c', 
 					pax_src+'tkwinobject.c'],
 			include_dirs=pax_include_dirs,
-			libraries=['X11', 'Xext', 'tk'+tcl_ver, 'tcl'+tcl_ver, 'cairo'])
+			libraries=['X11', 'Xext', 'tk'+tk_ver, 'tcl'+tcl_ver, 'cairo', 'intl'])
 			
  	skmod_src=src_path+'extentions/skmod/'	
 	skmod_module = Extension('sk1.app.modules._sketchmodule',
@@ -219,7 +212,7 @@
 					skmod_src+'skfm.c', skmod_src+'skimage.c', skmod_src+'skpoint.c', 
 					skmod_src+'skrect.c', skmod_src+'sktrafo.c'],
 			include_dirs=['/usr/include/cairo'],
-			libraries=['m', 'X11', 'Xext', 'tk'+tcl_ver, 'tcl'+tcl_ver, 'cairo'])
+			libraries=['m', 'X11', 'Xext', 'tk'+tk_ver, 'tcl'+tcl_ver, 'cairo'])
 			
  	tkpng_src=src_path+'extentions/tkpng/'
 	tkpng_module = Extension('sk1.app.modules.libtkpng',
@@ -227,7 +220,7 @@
 						('MINOR_VERSION', '9')],
 			sources = [tkpng_src+'tkImgPNG.c', tkpng_src+'tkImgPNGInit.c'],
 			include_dirs = tcl_include_dirs,
-			libraries=['tk'+tcl_ver, 'tcl'+tcl_ver, 'z'])
+			libraries=['tk'+tk_ver, 'tcl'+tcl_ver, 'z'])
 
 			
 	setup (name = 'sK1',
