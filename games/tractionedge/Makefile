# New ports collection makefile for:	tractionedge
# Date created:		09 Feb 2012
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tractionedge
DISTVERSION=	0.2b
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	Traction%20Edge%20v${DISTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Steampunk turn based strategy game with roguelike elements

LIB_DEPENDS=	sfml-system.1:${PORTSDIR}/devel/sfml

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/v${DISTVERSION}

CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS}

PORTDOCS=	README.txt

do-install:
	@${ECHO_CMD} "Installation not supported yet, you can play from ${WRKSRC}"
	@${FALSE}
.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
