--- src/game/CWorm.h.orig	2014-01-13 07:30:32.776469933 +0400
+++ src/game/CWorm.h	2014-01-13 07:52:30.427379177 +0400
@@ -261,7 +261,7 @@
 public:
 	ATTR(CWorm,	CNinjaRope,	cNinjaRope, 40, {serverside = false;})
 protected:
-	ATTR(CWorm, List<bool>, bVisibleForWorm, 41, {})
+	ATTR(CWorm, List<int>, bVisibleForWorm, 41, {})
 
 	ATTR(CWorm, bool,	bTagIT, 42, {})
 	TimeDiff	fTagTime;
