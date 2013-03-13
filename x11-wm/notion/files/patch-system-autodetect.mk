--- system-autodetect.mk.orig	2013-03-03 01:02:30.000000000 +0400
+++ system-autodetect.mk	2013-03-11 23:09:38.808933442 +0400
@@ -9,7 +9,7 @@
 # Installation path prefix. Unless you know what you're doing, the default
 # of /usr/local is likely the correct choice.
 #DIST: PREFIX=/usr/local
-PREFIX=/usr/local
+PREFIX?=/usr/local
 
 # Unless you are creating a package conforming to some OS's standards, you
 # probably do not want to modify the following directories:
@@ -21,7 +21,7 @@
 # Some .lua files and ion-* shell scripts
 SHAREDIR=$(PREFIX)/share/notion
 # Manual pages
-MANDIR=$(PREFIX)/share/man
+MANDIR=$(PREFIX)/man
 # Some documents
 DOCDIR=$(PREFIX)/share/doc/notion
 # Nothing at the moment
@@ -54,7 +54,7 @@
 
 # Flags to link with libdl. Even if PRELOAD_MODULES=1, you may need this
 # setting (for e.g. Lua, when not instructed by pkg-config).
-DL_LIBS=-ldl
+DL_LIBS=
 
 
 ##
@@ -67,14 +67,11 @@
 
 # Default to paths and names that should work for a build installed from the
 # official Lua 5.1 source tarball.
-LUA_DIR=/usr/local
-LUA_LIBS=-L$(LUA_DIR)/lib -llua
-LUA_INCLUDES = -I$(LUA_DIR)/include
-
-ifneq ($(shell which lua),)
-LUA=$(LUA_DIR)/bin/lua
-LUAC=$(LUA_DIR)/bin/luac
-endif
+LUA_DIR=$(LOCALBASE)
+LUA_LIBS=-L$(LUA_LIBDIR) -llua
+LUA_INCLUDES = -I$(LUA_INCDIR)
+LUA=$(LUA_BINDIR)/lua
+LUAC=$(LUA_BINDIR)/luac
 
 # Attempt to autodect lua using pkg-config.
 
@@ -132,7 +129,7 @@
 ##
 
 # Paths
-X11_PREFIX=/usr/X11R6
+X11_PREFIX=$(LOCALBASE)
 # SunOS/Solaris
 #X11_PREFIX=/usr/openwin
 
@@ -141,7 +138,7 @@
 
 # XFree86 libraries up to 4.3.0 have a bug that can cause a segfault.
 # The following setting  should  work around that situation.
-DEFINES += -DCF_XFREE86_TEXTPROP_BUG_WORKAROUND
+#DEFINES += -DCF_XFREE86_TEXTPROP_BUG_WORKAROUND
 
 # Use the Xutf8 routines (XFree86 extension) instead of the Xmb routines
 # in an UTF-8 locale. (No, you don't need this in UTF-8 locales, and 
@@ -164,11 +161,11 @@
 #DEFINES += -DCF_NO_LOCALE -DCF_NO_GETTEXT
 
 # On some other systems you may need to explicitly link against libintl.
-#EXTRA_LIBS += -lintl
+EXTRA_LIBS += -L$(LOCALBASE)/lib -lintl
 # You may also need to give the location of its headers. The following
 # should work on Mac OS X (which needs the above option as well) with
 # macports.
-#EXTRA_INCLUDES += -I/opt/local/include
+EXTRA_INCLUDES += -I$(LOCALBASE)/include
 
 
 ##
@@ -183,7 +180,7 @@
 # The following setting is needed with GNU libc for clock_gettime and the
 # monotonic clock. Other systems may not need it, or may not provide a
 # monotonic clock at all (which Ion can live with, and usually detect).
-EXTRA_LIBS += -lrt
+#EXTRA_LIBS += -lrt
 
 # Cygwin needs this.
 #DEFINES += -DCF_NO_GETLOADAVG
@@ -200,7 +197,7 @@
 ## C compiler. 
 ##
 
-CC=gcc
+CC?=gcc
 
 # Same as '-Wall -pedantic' without '-Wunused' as callbacks often
 # have unused variables.
@@ -208,7 +205,7 @@
 	-Wtrigraphs -Wformat -Wchar-subscripts \
 	-Wparentheses -pedantic -Wuninitialized
 
-CFLAGS=-Os $(WARN) $(DEFINES) $(INCLUDES) $(EXTRA_INCLUDES) -DHAS_SYSTEM_ASPRINTF=$(HAS_SYSTEM_ASPRINTF)
+CFLAGS+=$(WARN) $(DEFINES) $(INCLUDES) $(EXTRA_INCLUDES) -DHAS_SYSTEM_ASPRINTF=$(HAS_SYSTEM_ASPRINTF)
 
 LDFLAGS=-Wl,--as-needed $(LIBS) $(EXTRA_LIBS) 
 EXPORT_DYNAMIC=-Xlinker --export-dynamic
@@ -224,7 +221,7 @@
 POSIX_SOURCE=-D_POSIX_C_SOURCE=200112L
 
 # Most systems
-#XOPEN_SOURCE=-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED
+XOPEN_SOURCE=-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED -D__XSI_VISIBLE
 # SunOS, (Irix)
 #XOPEN_SOURCE=-D__EXTENSIONS__
 
