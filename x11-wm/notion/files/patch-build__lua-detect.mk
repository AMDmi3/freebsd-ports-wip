--- build/lua-detect.mk.orig	2014-05-28 02:00:18.000000000 +0400
+++ build/lua-detect.mk	2014-06-09 18:58:27.837518042 +0400
@@ -14,8 +14,8 @@
 #  * LUAC (full path to lua compiler)
 
 LUA_VERSION := $(or $(LUA_VERSION), $(shell \
-       (pkg-config --exists lua5.2 && echo 5.2) \
-    || (pkg-config --exists lua5.1 && echo 5.1) \
+       (pkg-config --exists lua-5.2 && echo 5.2) \
+    || (pkg-config --exists lua-5.1 && echo 5.1) \
     || (pkg-config --exists lua    && echo 5.0)))
 
 ifeq ($(LUA_VERSION),)
@@ -27,7 +27,7 @@
     LUA_VERSION=
 endif
 
-LUA_LIBS     := $(or $(shell pkg-config --libs lua$(LUA_VERSION)),   $(error "pkg-config couldn't find linker flags for lua$(LUA_VERSION)!"))
-LUA_INCLUDES := $(shell pkg-config --cflags lua$(LUA_VERSION))
-LUA          := $(or $(shell which lua$(LUA_VERSION)),               $(error No lua$(LUA_VERSION) interpreter found!))
-LUAC         := $(or $(shell which luac$(LUA_VERSION)),              $(error No lua$(LUA_VERSION) compiler found!))
+LUA_LIBS     := $(or $(shell pkg-config --libs lua-$(LUA_VERSION)),   $(error "pkg-config couldn't find linker flags for lua-$(LUA_VERSION)!"))
+LUA_INCLUDES := $(shell pkg-config --cflags lua-$(LUA_VERSION))
+LUA          := $(or $(shell which lua$(subst .,,$(LUA_VERSION))),               $(error No lua$(LUA_VERSION) interpreter found!))
+LUAC         := $(or $(shell which luac$(subst .,,$(LUA_VERSION))),              $(error No lua$(LUA_VERSION) compiler found!))
