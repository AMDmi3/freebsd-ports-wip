# New ports collection makefile for:	arx-libertatis
# Date created:		24 Apr 2012
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	arx-libertatis
PORTVERSION=	1.0.1
CATEGORIES=	games
MASTER_SITES=	http://cloud.github.com/downloads/arx/ArxLibertatis/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform port of Arx Fatalis

LICENSE=	GPLv3

LIB_DEPENDS=	IL.2:${PORTSDIR}/graphics/devil \
		GLEW.1:${PORTSDIR}/graphics/glew \
		freetype.9:${PORTSDIR}/print/freetype2 \
		boost_program_options.4:${PORTSDIR}/devel/boost-libs

USE_XZ=		yes
USE_OPENAL=	yes
USE_SDL=	sdl
USE_GL=		gl glu
USE_CMAKE=	yes
CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR="man" -DDATA_DIR=arx
MAKE_JOBS_SAFE=	yes

MAN1=		arxsavetool.1 arxunpak.1
MAN6=		arx.6

OPTIONS=	CRASHREPORTER "Build crash reporter (requires Qt4)" off \
		EDITOR "Build editor" off

.include <bsd.port.options.mk>

.if defined(WITH_CRASHREPORTER)
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network rcc_build moc_build uic_build qmake_build
CMAKE_ARGS+=	-DBUILD_CRASHREPORTER=ON
PLIST_SUB+=	CRASHREPORTER=""
.else
CMAKE_ARGS+=	-DBUILD_CRASHREPORTER=OFF
PLIST_SUB+=	CRASHREPORTER="@comment "
.endif

.if defined(WITH_EDITOR)
CMAKE_ARGS+=	-DBUILD_EDITOR=ON
.else
CMAKE_ARGS+=	-DBUILD_EDITOR=OFF
.endif

PORTDOCS=	AUTHORS CHANGELOG README.md

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
