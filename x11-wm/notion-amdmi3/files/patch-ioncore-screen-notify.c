Hackfixes annoying bug of notion which makes notification of started
application in bottom left corner not disapper
--- ioncore/screen-notify.c.orig	2011-09-30 22:00:51.000000000 +0400
+++ ioncore/screen-notify.c	2011-11-30 06:52:22.164501022 +0400
@@ -152,6 +152,8 @@
 
 static void screen_managed_activity(WScreen *scr)
 {
+	goto unnotify;
+
     char *notstr=NULL;
     WRegion *reg;
     ObjListIterTmp tmp;
