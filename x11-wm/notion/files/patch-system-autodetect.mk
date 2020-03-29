--- system-autodetect.mk.orig	2020-03-06 10:41:24 UTC
+++ system-autodetect.mk
@@ -61,7 +61,7 @@ endif
 #PRELOAD_MODULES=1
 
 # Flags to link with libdl.
-DL_LIBS=-ldl
+#DL_LIBS=-ldl
 
 
 ##
@@ -75,7 +75,7 @@ include $(TOPDIR)/build/lua-detect.mk
 ##
 
 # Paths
-X11_PREFIX ?= /usr/X11R6
+X11_PREFIX ?= ${LOCALBASE}
 # SunOS/Solaris
 #X11_PREFIX ?= /usr/openwin
 
@@ -84,7 +84,7 @@ X11_INCLUDES:=$(shell $(PKG_CONFIG) --cflags-only-I x1
 
 # XFree86 libraries up to 4.3.0 have a bug that can cause a segfault.
 # The following setting  should  work around that situation.
-DEFINES += -DCF_XFREE86_TEXTPROP_BUG_WORKAROUND
+#DEFINES += -DCF_XFREE86_TEXTPROP_BUG_WORKAROUND
 
 # Use the Xutf8 routines (XFree86 extension) instead of the Xmb routines
 # in an UTF-8 locale. (No, you don't need this in UTF-8 locales, and
@@ -142,8 +142,8 @@ HAS_SYSTEM_ASPRINTF=1
 #DEFINES += -DCF_NO_LOCALE
 
 # On some other systems you may something like this:
-#EXTRA_LIBS += -lintl
-#EXTRA_INCLUDES +=
+EXTRA_LIBS += -L${LOCALBASE}/lib -lintl
+EXTRA_INCLUDES += -isystem${LOCALBASE}/include
 
 
 ##
@@ -158,7 +158,7 @@ HAS_SYSTEM_ASPRINTF ?= 1
 # The following setting is needed with GNU libc for clock_gettime and the
 # monotonic clock. Other systems may not need it, or may not provide a
 # monotonic clock at all (which Ion can live with, and usually detect).
-EXTRA_LIBS += -lrt
+#EXTRA_LIBS += -lrt
 
 # Cygwin needs this. Also when you disable _BSD_SOURCE you may need it.
 #DEFINES += -DCF_NO_GETLOADAVG
@@ -185,7 +185,7 @@ WARN=-W -Wall -pedantic
 ifeq ($(DEBUG),1)
     CFLAGS+= -ggdb3 -O0
 else
-    CFLAGS+= -g -Os
+    #CFLAGS+= -g -Os
 endif
 CFLAGS += $(WARN) $(DEFINES) $(INCLUDES) $(EXTRA_INCLUDES) \
           -DHAS_SYSTEM_ASPRINTF=$(HAS_SYSTEM_ASPRINTF)
