--- makepanda/installpanda.py.orig	2011-03-15 17:12:55.000000000 +0300
+++ makepanda/installpanda.py	2011-11-01 03:46:35.000000000 +0400
@@ -106,7 +106,8 @@
         PEXEC = os.path.join(os.path.dirname(sys.executable), os.readlink(sys.executable))
     else:
         PEXEC = sys.executable
-    oscmd("mkdir -p "+destdir+prefix+"/bin")
+    oscmd("mkdir -p "+destdir+prefix+"/bin/panda3d")
+    oscmd("mkdir -p "+destdir+prefix+"/etc/panda3d")
     oscmd("mkdir -p "+destdir+prefix+"/include")
     oscmd("mkdir -p "+destdir+prefix+"/share/panda3d")
     oscmd("mkdir -p "+destdir+prefix+"/share/panda3d/direct")
@@ -117,16 +118,16 @@
     oscmd("mkdir -p "+destdir+prefix+libdir+"/panda3d")
     oscmd("mkdir -p "+destdir+PPATH)
     if (sys.platform.startswith("freebsd")):
-        oscmd("mkdir -p "+destdir+prefix+"/etc")
-        oscmd("mkdir -p "+destdir+"/usr/local/libdata/ldconfig")
+        oscmd("mkdir -p "+destdir+prefix+"/etc/panda3d")
+        oscmd("mkdir -p "+destdir+prefix+"/libdata/ldconfig")
     else:
         oscmd("mkdir -p "+destdir+"/etc/ld.so.conf.d")
     WriteFile(destdir+prefix+"/share/panda3d/direct/__init__.py", "")
     Configrc = ReadFile(outputdir+"/etc/Config.prc")
     Configrc = Configrc.replace("model-path    $THIS_PRC_DIR/..", "model-path    "+prefix+"/share/panda3d")
     if (sys.platform.startswith("freebsd")):
-        WriteFile(destdir+prefix+"/etc/Config.prc", Configrc)
-        oscmd("cp "+outputdir+"/etc/Confauto.prc    "+destdir+prefix+"/etc/Confauto.prc")
+        WriteFile(destdir+prefix+"/etc/panda3d/Config.prc", Configrc)
+        oscmd("cp "+outputdir+"/etc/Confauto.prc    "+destdir+prefix+"/etc/panda3d/Confauto.prc")
     else:
         WriteFile(destdir+"/etc/Config.prc", Configrc)
         oscmd("cp "+outputdir+"/etc/Confauto.prc    "+destdir+"/etc/Confauto.prc")
@@ -143,18 +144,15 @@
     WriteMimeXMLFile(destdir+prefix+"/share/mime/packages/panda3d.xml", MIME_INFO)
     WriteApplicationsFile(destdir+prefix+"/share/application-registry/panda3d.applications", APP_INFO, MIME_INFO)
     oscmd("cp makepanda/pview.desktop           "+destdir+prefix+"/share/applications/pview.desktop")
-    oscmd("cp doc/LICENSE                       "+destdir+prefix+"/share/panda3d/LICENSE")
-    oscmd("cp doc/LICENSE                       "+destdir+prefix+"/include/panda3d/LICENSE")
-    oscmd("cp doc/ReleaseNotes                  "+destdir+prefix+"/share/panda3d/ReleaseNotes")
     oscmd("echo '"+prefix+"/share/panda3d' >    "+destdir+PPATH+"/panda3d.pth")
     oscmd("echo '"+prefix+libdir+"/panda3d'>>   "+destdir+PPATH+"/panda3d.pth")
     if (sys.platform.startswith("freebsd")):
-        oscmd("echo '"+prefix+libdir+"/panda3d'>    "+destdir+"/usr/local/libdata/ldconfig/panda3d")
+        oscmd("echo '"+prefix+libdir+"/panda3d'>    "+destdir+prefix+"/libdata/ldconfig/panda3d")
     else:
         oscmd("echo '"+prefix+libdir+"/panda3d'>    "+destdir+"/etc/ld.so.conf.d/panda3d.conf")
         oscmd("chmod +x "+destdir+"/etc/ld.so.conf.d/panda3d.conf")
-    oscmd("ln -s "+PEXEC+"                      "+destdir+prefix+"/bin/ppython")
-    oscmd("cp "+outputdir+"/bin/*               "+destdir+prefix+"/bin/")
+    oscmd("ln -s "+PEXEC+"                      "+destdir+prefix+"/bin/panda3d/ppython")
+    oscmd("cp "+outputdir+"/bin/*               "+destdir+prefix+"/bin/panda3d/")
     for base in os.listdir(outputdir+"/lib"):
         if (not base.endswith(".a")):
             # We really need to specify -R in order not to follow symlinks on non-GNU
