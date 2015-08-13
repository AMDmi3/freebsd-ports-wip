# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	box2d
PORTVERSION=	2.2.1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	Box2D_v${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D rigid body simulation library

USES=		cmake zip
CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}"

DOCSDIR=	${PREFIX}/share/doc/Box2D
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS TESTBED
TESTBED_DESC=	Build and install testbed (requires glut and glui)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CMAKE_ARGS+=	-DBOX2D_INSTALL_DOC:BOOL=ON
.else
CMAKE_ARGS+=	-DBOX2D_INSTALL_DOC:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MTESTBED}
CMAKE_ARGS+=	-DBOX2D_BUILD_EXAMPLES:BOOL=ON
USE_GL+=	glut
LIB_DEPENDS+=	libglui.so:${PORTSDIR}/devel/glui
PLIST_SUB+=	TESTBED=""
.else
CMAKE_ARGS+=	-DBOX2D_BUILD_EXAMPLES:BOOL=OFF
PLIST_SUB+=	TESTBED="@comment "
.endif

.if ${PORT_OPTIONS:MTESTBED}
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Testbed/Testbed ${STAGEDIR}${PREFIX}/bin/box2d-testbed
.endif

.include <bsd.port.mk>
