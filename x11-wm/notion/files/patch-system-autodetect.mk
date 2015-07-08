--- system-autodetect.mk.orig	2015-06-13 14:37:26 UTC
+++ system-autodetect.mk
@@ -22,7 +22,7 @@ BINDIR=$(PREFIX)/bin
 # Some .lua files and ion-* shell scripts
 SHAREDIR=$(PREFIX)/share/notion
 # Manual pages
-MANDIR=$(PREFIX)/share/man
+MANDIR=$(MANPREFIX)/man
 # Some documents
 DOCDIR=$(PREFIX)/share/doc/notion
 # Nothing at the moment
@@ -66,7 +66,7 @@ endif
 
 # Flags to link with libdl. Even if PRELOAD_MODULES=1, you may need this
 # setting (for e.g. Lua, when not instructed by pkg-config).
-DL_LIBS=-ldl
+DL_LIBS=
 
 
 ##
@@ -80,7 +80,7 @@ include $(TOPDIR)/build/lua-detect.mk
 ##
 
 # Paths
-X11_PREFIX ?= /usr/X11R6
+X11_PREFIX ?= ${LOCALBASE}
 # SunOS/Solaris
 #X11_PREFIX ?= /usr/openwin
 
@@ -89,7 +89,7 @@ X11_INCLUDES=-I$(X11_PREFIX)/include
 
 # XFree86 libraries up to 4.3.0 have a bug that can cause a segfault.
 # The following setting  should  work around that situation.
-DEFINES += -DCF_XFREE86_TEXTPROP_BUG_WORKAROUND
+#DEFINES += -DCF_XFREE86_TEXTPROP_BUG_WORKAROUND
 
 # Use the Xutf8 routines (XFree86 extension) instead of the Xmb routines
 # in an UTF-8 locale. (No, you don't need this in UTF-8 locales, and 
@@ -112,11 +112,11 @@ DEFINES += -DCF_XFREE86_TEXTPROP_BUG_WOR
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
@@ -131,7 +131,7 @@ HAS_SYSTEM_ASPRINTF ?= 1
 # The following setting is needed with GNU libc for clock_gettime and the
 # monotonic clock. Other systems may not need it, or may not provide a
 # monotonic clock at all (which Ion can live with, and usually detect).
-EXTRA_LIBS += -lrt
+#EXTRA_LIBS += -lrt
 
 # Cygwin needs this. Also when you disable _BSD_SOURCE you may need it.
 #DEFINES += -DCF_NO_GETLOADAVG
@@ -152,7 +152,7 @@ CC ?= gcc
 
 WARN=-W -Wall -pedantic 
 
-CFLAGS += -Os $(WARN) $(DEFINES) $(INCLUDES) $(EXTRA_INCLUDES) \
+CFLAGS += $(WARN) $(DEFINES) $(INCLUDES) $(EXTRA_INCLUDES) \
           -DHAS_SYSTEM_ASPRINTF=$(HAS_SYSTEM_ASPRINTF)
 
 LDFLAGS += -Wl,--as-needed $(LIBS) $(EXTRA_LIBS)
@@ -166,11 +166,11 @@ EXPORT_DYNAMIC=-Xlinker --export-dynamic
 
 #C89_SOURCE=-ansi
 
-POSIX_SOURCE?=-D_POSIX_C_SOURCE=200112L
-BSD_SOURCE?=-D_BSD_SOURCE
+#POSIX_SOURCE?=-D_POSIX_C_SOURCE=200112L
+#BSD_SOURCE?=-D_BSD_SOURCE
 
 # Most systems
-XOPEN_SOURCE=-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED
+#XOPEN_SOURCE=-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED
 # SunOS, (Irix)
 #XOPEN_SOURCE=-D__EXTENSIONS__
 
