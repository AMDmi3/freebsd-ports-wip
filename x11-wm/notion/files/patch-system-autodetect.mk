--- system-autodetect.mk.orig	2014-05-28 02:00:18.000000000 +0400
+++ system-autodetect.mk	2014-06-09 19:03:02.992638832 +0400
@@ -19,7 +19,7 @@
 # Some .lua files and ion-* shell scripts
 SHAREDIR=$(PREFIX)/share/notion
 # Manual pages
-MANDIR=$(PREFIX)/share/man
+MANDIR=$(MANPREFIX)/man
 # Some documents
 DOCDIR=$(PREFIX)/share/doc/notion
 # Nothing at the moment
@@ -63,7 +63,7 @@
 
 # Flags to link with libdl. Even if PRELOAD_MODULES=1, you may need this
 # setting (for e.g. Lua, when not instructed by pkg-config).
-DL_LIBS=-ldl
+DL_LIBS=
 
 
 ##
@@ -77,7 +77,7 @@
 ##
 
 # Paths
-X11_PREFIX ?= /usr/X11R6
+X11_PREFIX ?= ${LOCALBASE}
 # SunOS/Solaris
 #X11_PREFIX ?= /usr/openwin
 
@@ -86,7 +86,7 @@
 
 # XFree86 libraries up to 4.3.0 have a bug that can cause a segfault.
 # The following setting  should  work around that situation.
-DEFINES += -DCF_XFREE86_TEXTPROP_BUG_WORKAROUND
+#DEFINES += -DCF_XFREE86_TEXTPROP_BUG_WORKAROUND
 
 # Use the Xutf8 routines (XFree86 extension) instead of the Xmb routines
 # in an UTF-8 locale. (No, you don't need this in UTF-8 locales, and 
@@ -109,11 +109,11 @@
 #DEFINES += -DCF_NO_LOCALE -DCF_NO_GETTEXT
 
 # On some other systems you may need to explicitly link against libintl.
-#EXTRA_LIBS += -lintl
+EXTRA_LIBS += -L${LOCALBASE}/lib -lintl
 # You may also need to give the location of its headers. The following
 # should work on Mac OS X (which needs the above option as well) with
 # macports.
-#EXTRA_INCLUDES += -I/opt/local/include
+EXTRA_INCLUDES += -I${LOCALBASE}/include
 
 
 ##
@@ -128,7 +128,7 @@
 # The following setting is needed with GNU libc for clock_gettime and the
 # monotonic clock. Other systems may not need it, or may not provide a
 # monotonic clock at all (which Ion can live with, and usually detect).
-EXTRA_LIBS += -lrt
+#EXTRA_LIBS += -lrt
 
 # Cygwin needs this. Also when you disable _BSD_SOURCE you may need it.
 #DEFINES += -DCF_NO_GETLOADAVG
@@ -149,7 +149,7 @@
 
 WARN=-W -Wall -pedantic 
 
-CFLAGS += -Os $(WARN) $(DEFINES) $(INCLUDES) $(EXTRA_INCLUDES) \
+CFLAGS += $(WARN) $(DEFINES) $(INCLUDES) $(EXTRA_INCLUDES) \
           -DHAS_SYSTEM_ASPRINTF=$(HAS_SYSTEM_ASPRINTF)
 
 LDFLAGS += -Wl,--as-needed $(LIBS) $(EXTRA_LIBS)
@@ -167,7 +167,7 @@
 BSD_SOURCE?=-D_BSD_SOURCE
 
 # Most systems
-XOPEN_SOURCE=-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED
+XOPEN_SOURCE=-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED -D__XSI_VISIBLE
 # SunOS, (Irix)
 #XOPEN_SOURCE=-D__EXTENSIONS__
 
