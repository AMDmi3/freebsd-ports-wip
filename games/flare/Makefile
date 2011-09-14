# New ports collection makefile for:	flare
# Date created:		03 May 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flare
PORTVERSION=	v014
CATEGORIES=	games
MASTER_SITES=	http://cloud.github.com/downloads/clintbellanger/flare/ \
		http://mirror.amdmi3.ru/files/
DISTNAME=	${PORTNAME}_src_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free Libre Action Roleplaying Engine

PROJECTHOST=	flare-engine

USE_ZIP=	yes
USE_CMAKE=	yes
USE_SDL=	sdl mixer image
MAKE_JOBS_SAFE=	yes

CMAKE_SOURCE_PATH=	${WRKSRC}/build

LATEST_LINK=	flare-rpg

PORTDOCS=	*

# this should go away in v015
post-patch:
	@${REINPLACE_CMD} -e 's|SDLmain|$${SDLMAIN_LIBRARY}|' ${WRKSRC}/build/CMakeLists.txt

do-install:
	${FALSE} installation no supported
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
