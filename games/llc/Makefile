# New ports collection makefile for:	llc
# Date created:		17 Jun 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lunar-lander-clone
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	llc-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple clone of lunar lander

LIB_DEPENDS=	confuse.0:${PORTSDIR}/devel/libconfuse

USE_BZIP2=	yes
USE_SDL=	sdl image ttf gfx
USE_GCC=	4.4+

WRKSRC=		${WRKDIR}/llc

post-patch:
#	@${REINPLACE_CMD} -e '/dirscan/ s|\./|${DATADIR}/|' ${WRKSRC}/src/menu.cpp
#	@${REINPLACE_CMD} -e 's|[map]*font\.ttf|${DATADIR}/&|; s|lander\.png|${DATADIR}/&|' \
#		${WRKSRC}/src/*.cpp

do-build:
	cd ${WRKSRC}/src && ${CXX} ${CXXFLAGS} *.cpp \
		`${SDL_CONFIG} --libs --cflags` -lSDL_image \
		-lSDL_ttf -lSDL_gfx -lconfuse -o ${WRKSRC}/llc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/llc ${PREFIX}/bin/
	${MKDIR} ${DATADIR}/
	cd ${WRKSRC} && ${COPYTREE_SHARE} '0x0* *png *ttf' ${DATADIR}/

.include <bsd.port.mk>
