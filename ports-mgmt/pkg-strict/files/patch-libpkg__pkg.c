--- libpkg/pkg.c.orig	2013-07-06 14:48:19.000000000 +0400
+++ libpkg/pkg.c	2013-10-23 00:44:11.274197440 +0400
@@ -475,8 +475,8 @@
 
 	HASH_FIND_STR(pkg->licenses, __DECONST(char *, name), l);
 	if (l != NULL) {
-		pkg_emit_error("duplicate license listing: %s, ignoring", name);
-		return (EPKG_OK);
+		pkg_emit_error("duplicate license listing: %s, fatal", name);
+		return (EPKG_FATAL);
 	}
 
 	pkg_license_new(&l);
@@ -498,8 +498,8 @@
 
 	HASH_FIND_STR(pkg->users, __DECONST(char *, name), u);
 	if (u != NULL) {
-		pkg_emit_error("duplicate user listing: %s, ignoring", name);
-		return (EPKG_OK);
+		pkg_emit_error("duplicate user listing: %s, fatal", name);
+		return (EPKG_FATAL);
 	}
 
 	pkg_user_new(&u);
@@ -532,8 +532,8 @@
 
 	HASH_FIND_STR(pkg->groups, __DECONST(char *, name), g);
 	if (g != NULL) {
-		pkg_emit_error("duplicate group listing: %s, ignoring", name);
-		return (EPKG_OK);
+		pkg_emit_error("duplicate group listing: %s, fatal", name);
+		return (EPKG_FATAL);
 	}
 
 	pkg_group_new(&g);
@@ -569,9 +569,9 @@
 	HASH_FIND_STR(pkg->deps, __DECONST(char *, origin), d);
 	if (d != NULL) {
 		pkg_get(pkg, PKG_NAME, &n1, PKG_VERSION, &v1);
-		pkg_emit_error("%s-%s: duplicate dependency listing: %s-%s, ignoring",
+		pkg_emit_error("%s-%s: duplicate dependency listing: %s-%s, fatal",
 		    n1, v1, name, version);
-		return (EPKG_OK);
+		return (EPKG_FATAL);
 	}
 
 	pkg_dep_new(&d);
@@ -627,8 +627,8 @@
 	if (check_duplicates) {
 		HASH_FIND_STR(pkg->files, __DECONST(char *, path), f);
 		if (f != NULL) {
-			pkg_emit_error("duplicate file listing: %s, ignoring", pkg_file_path(f));
-			return (EPKG_OK);
+			pkg_emit_error("duplicate file listing: %s, fatal", pkg_file_path(f));
+			return (EPKG_FATAL);
 		}
 	}
 
@@ -662,8 +662,8 @@
 
 	HASH_FIND_STR(pkg->categories, __DECONST(char *, name), c);
 	if (c != NULL) {
-		pkg_emit_error("duplicate category listing: %s, ignoring", name);
-		return (EPKG_OK);
+		pkg_emit_error("duplicate category listing: %s, fatal", name);
+		return (EPKG_FATAL);
 	}
 
 	pkg_category_new(&c);
@@ -693,8 +693,8 @@
 	if (check_duplicates) {
 		HASH_FIND_STR(pkg->dirs, __DECONST(char *, path), d);
 		if (d != NULL) {
-			pkg_emit_error("duplicate directory listing: %s, ignoring", path);
-			return (EPKG_OK);
+			pkg_emit_error("duplicate directory listing: %s, fatal", path);
+			return (EPKG_FATAL);
 		}
 	}
 
@@ -816,8 +816,8 @@
 
 	HASH_FIND_STR(pkg->options, __DECONST(char *, key), o);
 	if (o != NULL) {
-		pkg_emit_error("duplicate options listing: %s, ignoring", key);
-		return (EPKG_OK);
+		pkg_emit_error("duplicate options listing: %s, fatal", key);
+		return (EPKG_FATAL);
 	}
 	pkg_option_new(&o);
 
@@ -892,8 +892,8 @@
 	HASH_FIND_STR(pkg->annotations, __DECONST(char *, tag), an);
 	if (an != NULL) {
 		pkg_emit_error("duplicate annotation tag: %s value: %s,"
-			       " ignoring", tag, value);
-		return (EPKG_OK);
+			       " fatal", tag, value);
+		return (EPKG_FATAL);
 	}
 	an = NULL;
 	pkg_annotation_new(&an);
@@ -1181,6 +1181,20 @@
 	struct pkg_dir *dir = NULL;
 	char spath[MAXPATHLEN + 1];
 	char dpath[MAXPATHLEN + 1];
+	bool disable_mtree;
+	const char *prefix;
+	char *mtree;
+
+	pkg_config_bool(PKG_CONFIG_DISABLE_MTREE, &disable_mtree);
+	if (!disable_mtree) {
+		pkg_get(pkg, PKG_PREFIX, &prefix, PKG_MTREE, &mtree);
+		do_extract_mtree(mtree, prefix);
+	}
+
+	/*
+	 * Execute pre-install scripts
+	 */
+	pkg_script_run(pkg, PKG_SCRIPT_PRE_INSTALL);
 
 	if (packing_init(&pack, dest, 0) != EPKG_OK) {
 		/* TODO */
@@ -1190,15 +1204,21 @@
 	while (pkg_dirs(pkg, &dir) == EPKG_OK) {
 		snprintf(spath, sizeof(spath), "%s%s", src, pkg_dir_path(dir));
 		snprintf(dpath, sizeof(dpath), "%s%s", dest, pkg_dir_path(dir));
-		packing_append_file(pack, spath, dpath);
+		packing_append_file_attr(pack, spath, dpath,
+		    dir->uname, dir->gname, dir->perm);
 	}
 
 	while (pkg_files(pkg, &file) == EPKG_OK) {
 		snprintf(spath, sizeof(spath), "%s%s", src, pkg_file_path(file));
 		snprintf(dpath, sizeof(dpath), "%s%s", dest, pkg_file_path(file));
-		packing_append_file(pack, spath, dpath);
+		packing_append_file_attr(pack, spath, dpath,
+		    file->uname, file->gname, file->perm);
 	}
 
+	/*
+	 * Execute post install scripts
+	 */
+	pkg_script_run(pkg, PKG_SCRIPT_POST_INSTALL);
 
 	return (packing_finish(pack));
 }
