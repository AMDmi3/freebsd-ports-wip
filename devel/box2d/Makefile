# New ports collection makefile for:	box2d
# Date created:		08 Feb 2010
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	box2d
PORTVERSION=	2.2.1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	Box2D_v${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D rigid body simulation library

USE_ZIP=	yes
USE_CMAKE=	yes
CMAKE_ARGS+=	-DBOX2D_BUILD_EXAMPLES:BOOL=OFF
MAKE_JOBS_SAFE=	yes

DOCSDIR=	${PREFIX}/share/doc/Box2D
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CMAKE_ARGS+=	-DBOX2D_INSTALL_DOC:BOOL=ON
.else
CMAKE_ARGS+=	-DBOX2D_INSTALL_DOC:BOOL=OFF
.endif

.include <bsd.port.mk>
