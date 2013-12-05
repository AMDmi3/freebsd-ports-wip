--- libpkg/pkg.c.orig	2013-11-27 22:14:50.000000000 +0400
+++ libpkg/pkg.c	2013-12-06 00:18:58.701924119 +0400
@@ -490,8 +490,8 @@
 
 	HASH_FIND_STR(pkg->licenses, name, l);
 	if (l != NULL) {
-		pkg_emit_error("duplicate license listing: %s, ignoring", name);
-		return (EPKG_OK);
+		pkg_emit_error("duplicate license listing: %s, fatal", name);
+		return (EPKG_FATAL);
 	}
 
 	pkg_license_new(&l);
@@ -513,8 +513,8 @@
 
 	HASH_FIND_STR(pkg->users, name, u);
 	if (u != NULL) {
-		pkg_emit_error("duplicate user listing: %s, ignoring", name);
-		return (EPKG_OK);
+		pkg_emit_error("duplicate user listing: %s, fatal", name);
+		return (EPKG_FATAL);
 	}
 
 	pkg_user_new(&u);
@@ -547,8 +547,8 @@
 
 	HASH_FIND_STR(pkg->groups, name, g);
 	if (g != NULL) {
-		pkg_emit_error("duplicate group listing: %s, ignoring", name);
-		return (EPKG_OK);
+		pkg_emit_error("duplicate group listing: %s, fatal", name);
+		return (EPKG_FATAL);
 	}
 
 	pkg_group_new(&g);
@@ -585,9 +585,9 @@
 	HASH_FIND_STR(pkg->deps, origin, d);
 	if (d != NULL) {
 		pkg_get(pkg, PKG_NAME, &n1, PKG_VERSION, &v1);
-		pkg_emit_error("%s-%s: duplicate dependency listing: %s-%s, ignoring",
+		pkg_emit_error("%s-%s: duplicate dependency listing: %s-%s, fatal",
 		    n1, v1, name, version);
-		return (EPKG_OK);
+		return (EPKG_FATAL);
 	}
 
 	pkg_dep_new(&d);
@@ -646,8 +646,8 @@
 	if (check_duplicates) {
 		HASH_FIND_STR(pkg->files, path, f);
 		if (f != NULL) {
-			pkg_emit_error("duplicate file listing: %s, ignoring", pkg_file_path(f));
-			return (EPKG_OK);
+			pkg_emit_error("duplicate file listing: %s, fatal", pkg_file_path(f));
+			return (EPKG_FATAL);
 		}
 	}
 
@@ -681,8 +681,8 @@
 
 	HASH_FIND_STR(pkg->categories, name, c);
 	if (c != NULL) {
-		pkg_emit_error("duplicate category listing: %s, ignoring", name);
-		return (EPKG_OK);
+		pkg_emit_error("duplicate category listing: %s, fatal", name);
+		return (EPKG_FATAL);
 	}
 
 	pkg_category_new(&c);
@@ -713,8 +713,8 @@
 	if (check_duplicates) {
 		HASH_FIND_STR(pkg->dirs, path, d);
 		if (d != NULL) {
-			pkg_emit_error("duplicate directory listing: %s, ignoring", path);
-			return (EPKG_OK);
+			pkg_emit_error("duplicate directory listing: %s, fatal", path);
+			return (EPKG_FATAL);
 		}
 	}
 
@@ -847,8 +847,8 @@
 		pkg_option_new(&o);
 		sbuf_set(&o->key, key);
 	} else if ( o->value != NULL) {
-		pkg_emit_error("duplicate options listing: %s, ignoring", key);
-		return (EPKG_OK);
+		pkg_emit_error("duplicate options listing: %s, fatal", key);
+		return (EPKG_FATAL);
 	}
 
 	sbuf_set(&o->value, value);
@@ -880,8 +880,8 @@
 		pkg_option_new(&o);
 		sbuf_set(&o->key, key);
 	} else if ( o->default_value != NULL) {
-		pkg_emit_error("duplicate default value for option: %s, ignoring", key);
-		return (EPKG_OK);
+		pkg_emit_error("duplicate default value for option: %s, fatal", key);
+		return (EPKG_FATAL);
 	}
 
 	sbuf_set(&o->default_value, default_value);
@@ -912,8 +912,8 @@
 		pkg_option_new(&o);
 		sbuf_set(&o->key, key);
 	} else if ( o->description != NULL) {
-		pkg_emit_error("duplicate description for option: %s, ignoring", key);
-		return (EPKG_OK);
+		pkg_emit_error("duplicate description for option: %s, fatal", key);
+		return (EPKG_FATAL);
 	}
 
 	sbuf_set(&o->description, description);
@@ -986,8 +986,8 @@
 	HASH_FIND_STR(pkg->annotations, tag, an);
 	if (an != NULL) {
 		pkg_emit_error("duplicate annotation tag: %s value: %s,"
-			       " ignoring", tag, value);
-		return (EPKG_OK);
+			       " fatal", tag, value);
+		return (EPKG_FATAL);
 	}
 	an = NULL;
 	pkg_annotation_new(&an);
