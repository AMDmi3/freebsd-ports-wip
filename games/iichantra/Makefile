# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iichantra
PORTVERSION=	git20130716
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/
DISTNAME=	iichan-scroller-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D run'n'gun Contra-like game

LIB_DEPENDS=	IL.2:${PORTSDIR}/graphics/devil \
		zzip.13:${PORTSDIR}/devel/zziplib

USE_BZIP2=	yes
USES=		cmake
CMAKE_ARGS=	-DWITH_BASS:BOOL=OFF \
		-DFORCE_SDLMIXER:BOOL=ON \
		-DIICHANTRA_INSTALL:BOOL=ON
USE_LUA=	5.1+
USE_SDL=	sdl net mixer
USE_GCC=	4.6+

WRKSRC=		${WRKDIR}/iichan-scroller/new_engine

PORTDOCS=	*

MAN6=		${PORTNAME}.6
MANCOMPRESSED=	yes

.include <bsd.port.options.mk>

post-extract:
	@${RM} -rf ${WRKSRC}/lib

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/INSTALL.*\/doc\// d' ${WRKSRC}/CMakeLists.txt
.endif
	@${REINPLACE_CMD} -e 's|/usr/games|${PREFIX}/bin|; s|/usr/share/man|${PREFIX}/man|; \
		s|/usr/share/games/iichantra|${DATADIR}|; s|/usr/share|${PREFIX}/share|; \
		s|/usr/share/doc/iichantra/|${DOCSDIR}|; s|/usr/lib|${PREFIX}/lib|' \
		${WRKSRC}/CMakeLists.txt ${WRKSRC}/Resource/iichantra ${WRKSRC}/src/defines.h

.include <bsd.port.mk>
