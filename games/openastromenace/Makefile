# Created by: Oleg Alexeenkov
# $FreeBSD: head/games/openastromenace/Makefile 357184 2014-06-09 16:37:18Z amdmi3 $

PORTNAME=	openastromenace
PORTVERSION=	1.3.2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/
DISTNAME=	astromenace-src-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Hardcore 3D space shooter with spaceship upgrade possibilities

LICENSE=	GPLv3

LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libvorbisfile.so:${PORTSDIR}/audio/libvorbis \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

USES=		tar:bzip2 cmake openal:al,alut
USE_XORG=	x11 xinerama
USE_GL=		gl glu
USE_SDL=	sdl
WRKSRC=		${WRKDIR}/AstroMenace

PLIST_FILES=	bin/AstroMenace
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-build:
	cd ${WRKSRC} && ./AstroMenace --pack --rawdata=./RAW_VFS_DATA

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/AstroMenace ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gamedata.vfs ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
