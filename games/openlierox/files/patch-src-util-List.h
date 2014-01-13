Avoid std::vector<bool> specialization, which doesn't work
--- src/util/List.h.orig	2012-04-17 04:26:15.000000000 +0400
+++ src/util/List.h	2014-01-13 08:01:51.012850920 +0400
@@ -8,6 +8,7 @@
 #define OLX_LIST_H
 
 #include <vector>
+#include <deque>
 #include <string>
 #include <assert.h>
 #include "util/CustomVar.h"
@@ -47,7 +48,7 @@
 	virtual LuaReference getMetaTable() const { return metaTable; }
 };
 
-template<typename T, typename ImplType = std::vector<T> >
+template<typename T, typename ImplType = std::deque<T> >
 class List : public DynamicList {
 public:
 	static const ScriptVarType_t typeId = GetType<T>::value;
