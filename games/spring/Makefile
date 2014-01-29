# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD: head/games/spring/Makefile 337464 2013-12-25 23:29:34Z antoine $

PORTNAME=	spring
PORTVERSION=	96.0
CATEGORIES=	games
MASTER_SITES=	SF/springrts/springrts/${PORTNAME}-${PORTVERSION} \
		http://springrts.com/dl/
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A project aiming to create a new and versatile RTS Engine

LICENSE=	GPLv2

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libIL.so:${PORTSDIR}/graphics/devil \
		libogg.so:${PORTSDIR}/audio/libogg \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo
BUILD_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	relies on x86 floating-point math and amd64 atomic ops

USE_SDL=	sdl
USE_GL=		gl glu glew
USE_XORG=	x11 xcursor
USE_LDCONFIG=	yes
DOS2UNIX_GLOB=	*.h *.hpp *.cpp

USES=		cmake compiler:c++11-lib dos2unix openal:al
CMAKE_ARGS=	-DDATADIR:STRING="share/${PORTNAME}" \
		-DAI_TYPES:STRING="NATIVE" \
		-DUNITSYNC_PYTHON_WRAPPER:BOOL=false \
		-DCUSTOM_CFLAGS:BOOL=true \
		-DUSE_TCMALLOC=FALSE

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	MANPAGES PR_DOWNLOADER DOCS
OPTIONS_DEFAULT=MANPAGES PR_DOWNLOADER
OPTIONS_SUB=	*

PR_DOWNLOADER_DESC=	Map and game downloader

MANPAGES_CMAKE_ON=	-DCREATE_MAN_PAGES:BOOL=true -DMANDIR:STRING="man"
MANPAGES_CMAKE_OFF=	-DCREATE_MAN_PAGES:BOOL=false
MANPAGES_BUILD_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip \
			asciidoc:${PORTSDIR}/textproc/asciidoc \
			xsltproc:${PORTSDIR}/textproc/libxslt \
			${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl \
			bash:${PORTSDIR}/shells/bash

PR_DOWNLOADER_LIB_DEPENDS=libcurl.so:${PORTSDIR}/ftp/curl

.include <bsd.port.options.mk>

.if defined(WITH_SYNC_DEBUG)
CFLAGS=		# empty
CXXFLAGS=	# empty
CMAKE_ARGS+=	-DTRACE_SYNC=true -DSYNCDEBUG=true
CMAKE_BUILD_TYPE=DEBUG2
.endif

.if ! ${PORT_OPTIONS:MPR_DOWNLOADER}
post-extract:
	@${RM} ${WRKSRC}/tools/pr-downloader/CMakeLists.txt
.endif

.if ${ARCH} == "i386"
CFLAGS+=	-msse
CXXFLAGS+=	-msse
.endif

.if ${OSVERSION} < 1000024
# The reason is actually lack of some C99 math functions in our
# libm (erfl, erfcl, lgammal, tgammal) which are used in C++11
# math library.
# This applies to 10.0 as well, butlibc++ handles it gracefully
# by using lower-precision versions (you may see warnings on this
# when linking), whil libstdc++ disables all C99 math functions
# completely, including std::hypot which is needed by spring.
# Solution is being sought
IGNORE=		doesn't build on < 10.x (lack of c++11 support)
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O[12]||' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|/etc/\(spring/datadir\)|${PREFIX}/\1|g' \
		${WRKSRC}/rts/System/FileSystem/DataDirLocater.cpp
	@${REINPLACE_CMD} -e 's|x1F3F|x0F3F|g' \
		${WRKSRC}/rts/System/Sync/FPUCheck.cpp
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/rts/build/cmake/*.cmake
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}&|' \
		${WRKSRC}/doc/manpages/make_manpages.sh
.if ! ${PORT_OPTIONS:MMANPAGES}
	@${REINPLACE_CMD} -e '/set(CREATE_MAN_PAGES)/ d' \
		${WRKSRC}/doc/CMakeLists.txt
.endif

pre-build:
	cd ${WRKSRC} && ${MAKE} generateVersionFiles

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS README.markdown \
		FAQ THANKS ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
