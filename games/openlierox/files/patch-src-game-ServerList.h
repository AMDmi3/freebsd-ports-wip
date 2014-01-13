--- src/game/ServerList.h.orig	2014-01-13 07:30:32.779469727 +0400
+++ src/game/ServerList.h	2014-01-13 07:59:55.674349013 +0400
@@ -123,7 +123,7 @@
 
 	class NetworkAddrComp  {
 	public:
-		bool operator() (const NetworkAddr& a1, const NetworkAddr& a2)
+		bool operator() (const NetworkAddr& a1, const NetworkAddr& a2) const
 		{
 			return stringcasecmp(NetAddrToString(a1), NetAddrToString(a2)) < 0;  // TODO: inefficient
 		}
