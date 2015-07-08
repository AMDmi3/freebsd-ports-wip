--- build/lua-detect.mk.orig	2015-06-13 14:37:26 UTC
+++ build/lua-detect.mk
@@ -26,7 +26,7 @@ endif
 LUA_VERSION ?= $(or $(shell $(PKG_CONFIG) --variable=V $(LUA_PKG)),5.0)
 
 # prior to 5.1 the lib didn't include version in name.
-LUA_SUFFIX := $(if $(findstring $(LUA_VERSION),5.0),,$(LUA_VERSION))
+LUA_SUFFIX := $(if $(findstring $(LUA_VERSION),5.0),,$(subst .,,$(LUA_VERSION)))
 
 LUA_LIBS     := $(or $(shell $(PKG_CONFIG) --libs $(LUA_PKG)), $(error "pkg-config couldn't find linker flags for lua$(LUA_SUFFIX)!"))
 LUA_INCLUDES := $(shell $(PKG_CONFIG) --cflags $(LUA_PKG))
