# New ports collection makefile for:	flare
# Date created:		03 May 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flare
PORTVERSION=	v013
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}_src_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Empty comment

PROJECTHOST=	flare-engine

USE_ZIP=	yes
USE_CMAKE=	yes
USE_SDL=	sdl mixer image
MAKE_JOBS_SAFE=	yes

CMAKE_SOURCE_PATH=	${WRKSRC}/build

PORTDOCS=	*

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
