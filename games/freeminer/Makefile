# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD: head/games/freeminer/Makefile 412346 2016-04-01 14:00:51Z mat $

PORTNAME=	freeminer
PORTVERSION=	0.4.14.8
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open source sandbox game inspired by Minecraft

LICENSE=	LGPL21+ GPLv3+ # source mentions GPLv3+, LICENSE.txt LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING # don't remove space

LIB_DEPENDS=	libmsgpackc.so:devel/msgpack \
		libjsoncpp.so:devel/jsoncpp \
		libgmp.so:math/gmp \
		libfreetype.so:print/freetype2

USE_GITHUB=	yes
GH_TUPLE=	freeminer:enet:1f8eb62:enet

USES=		compiler:c++11-lib cmake
CMAKE_ARGS=	-DCUSTOM_MANDIR="${PREFIX}/man" \
		-DCUSTOM_EXAMPLE_CONF_DIR="${PREFIX}/etc" \
		-DENABLE_SYSTEM_JSONCPP=1 \
		-DENABLE_SYSTEM_MSGPACK=1 \
		-DRUN_IN_PLACE=0

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	CLIENT SERVER THREADS CURL SOUND LEVELDB LUAJIT OPTIMIZED_CFLAGS \
		SQLITE3 REDIS MINETEST NLS DOCS EXAMPLES SPATIAL
OPTIONS_DEFAULT=CLIENT SERVER THREADS CURL SOUND LEVELDB LUAJIT OPTIMIZED_CFLAGS
OPTIONS_SUB=	yes

CLIENT_DESC=	Build client
SERVER_DESC=	Build server
CURL_DESC=	Enable cURL support for fetching media
SOUND_DESC=	Enable sound
LEVELDB_DESC=	Enable LevelDB backend
LUAJIT_DESC=	LuaJIT support
MINETEST_DESC=	Use minetest protocol (slow and buggy)
SPATIAL_DESC=	Enable SpatialIndex AreaStore backend

CLIENT_CMAKE_ON=	-DBUILD_CLIENT=1
CLIENT_CMAKE_OFF=	-DBUILD_CLIENT=0
CLIENT_LIB_DEPENDS=	libpng.so:graphics/png \
			libIrrlicht.so:x11-toolkits/irrlicht
CLIENT_USES=		jpeg
CLIENT_USE=		GL=gl XORG=x11,xext,xxf86vm
SERVER_CMAKE_ON=	-DBUILD_SERVER=1
SERVER_CMAKE_OFF=	-DBUILD_SERVER=0
CURL_CMAKE_ON=		-DENABLE_CURL=1
CURL_CMAKE_OFF=		-DENABLE_CURL=0
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
NLS_CMAKE_ON=		-DENABLE_GETTEXT=1
NLS_CMAKE_OFF=		-DENABLE_GETTEXT=0
NLS_USES=		gettext
NLS_LDFLAGS=		-L${LOCALBASE}/lib
SOUND_CMAKE_ON=		-DENABLE_SOUND=1
SOUND_CMAKE_OFF=	-DENABLE_SOUND=0
LEVELDB_CMAKE_ON=	-DENABLE_LEVELDB=1
LEVELDB_CMAKE_OFF=	-DENABLE_LEVELDB=0
LEVELDB_LIB_DEPENDS=	libleveldb.so:databases/leveldb \
			libsnappy.so:archivers/snappy
SQLITE3_CMAKE_ON=	-DENABLE_SQLITE3=1
SQLITE3_CMAKE_OFF=	-DENABLE_SQLITE3=0
SQLITE3_USES=		sqlite
REDIS_CMAKE_ON=		-DENABLE_REDIS=1
REDIS_CMAKE_OFF=	-DENABLE_REDIS=0
REDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis
LUAJIT_CMAKE_ON=	-DENABLE_LUAJIT=1
LUAJIT_CMAKE_OFF=	-DENABLE_LUAJIT=0
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
MINETEST_CMAKE_ON=	-DMINETEST_PROTO=1
MINETEST_CMAKE_OFF=	-DMINETEST_PROTO=0
SPATIAL_CMAKE_ON=	-DENABLE_SPATIAL=1
SPATIAL_CMAKE_OFF=	-DENABLE_SPATIAL=0
SPATIAL_LIB_DEPENDS=	libspatialindex.so:devel/spatialindex

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT} && ${PORT_OPTIONS:MSOUND}
USES+=		openal
LIB_DEPENDS+=	libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg
.endif

.if ${PORT_OPTIONS:MSERVER}
USE_RC_SUBR=	${PORTNAME}
USERS=		minetest # reuse, as freeminer is a fork of
GROUPS=		minetest
.endif

# hacky way to not bring irrlicht and X11 depends for server only
.if ! ${PORT_OPTIONS:MCLIENT} && ${PORT_OPTIONS:MSERVER}
BUILD_DEPENDS+=		${NONEXISTENT}:x11-toolkits/irrlicht:patch
IRRLICHT_INCLUDE_DIR=	`${MAKE} -C ${PORTSDIR}/x11-toolkits/irrlicht -V WRKSRC`/include
CMAKE_ARGS+=		-DIRRLICHT_INCLUDE_DIR:STRING="${IRRLICHT_INCLUDE_DIR}"
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-irrlichtdepend
.endif

post-extract:
	@${MV} ${WRKSRC_enet}/* ${WRKSRC}/src/enet

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/*.cmake
	@${REINPLACE_CMD} -e 's|-lpthread|-pthread|' \
		-e 's|-lstdc++||' \
		${WRKSRC}/src/CMakeLists.txt

post-patch-OPTIMIZED_CFLAGS-off:
	@${REINPLACE_CMD} -e '/set(CMAKE_CXX_FLAGS_RELEASE.*-O3/ d' \
		${WRKSRC}/src/CMakeLists.txt

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.example \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
