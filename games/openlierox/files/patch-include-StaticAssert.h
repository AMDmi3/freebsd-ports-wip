--- include/StaticAssert.h.orig	2014-01-13 08:03:05.598335164 +0400
+++ include/StaticAssert.h	2014-01-13 08:03:14.606334949 +0400
@@ -14,7 +14,9 @@
 template <> class static_assert_failure<true>  { char foo; };
 template <int s> class static_assert_test{};
 
+#ifndef _LIBCPP_VERSION
 #define static_assert(X, desc)  \
 	typedef static_assert_test< (int)sizeof(static_assert_failure< (bool)(X) >) > static_assert_typedef_##desc;
+#endif
 
 #endif
