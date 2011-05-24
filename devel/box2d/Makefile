# New ports collection makefile for:	box2d
# Date created:		08 Feb 2010
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	box2d
PORTVERSION=	2.0.1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	Box2D_v${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D rigid body simulation library

USE_ZIP=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/Box2D
BUILD_WRKSRC=	${WRKSRC}/Source
ALL_TARGET=	Gen/float/libbox2d.a

INCDIRS=	Collision Collision/Shapes Common Dynamics \
		Dynamics/Contacts Dynamics/Joints

PORTDOCS=	*

OPTIONS=	TESTBED "Build testbed with Box2D deponstrations" off

.include <bsd.port.options.mk>

.if defined(WITH_TESTBED)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libglui.a:${PORTSDIR}/devel/glui
USE_GL+=	glut
PLIST_SUB+=	TESTBED=""
.else
PLIST_SUB+=	TESTBED="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[gc]++|${CXX}|; s|make|$${MAKE}|; /CXXFLAGS=/d' \
		${WRKSRC}/Makefile ${WRKSRC}/Source/Makefile \
		${WRKSRC}/Examples/TestBed/Makefile
	@${FIND} ${WRKSRC}/Examples/TestBed -name "*.cpp" -o -name "*.h" | \
		${XARGS} ${REINPLACE_CMD} -e 's|".*/glut.h"|<GL/glut.h>|; \
		s|".*/glui.h"|<glui.h>|'

.if defined(WITH_TESTBED)
post-build:
	cd ${WRKSRC}/Examples/TestBed && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} \
		${ALL_TARGET:C/libbox2d.a/testbed/}
.endif

do-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/${ALL_TARGET} ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/Include/Box2D.h ${PREFIX}/include/
.for d in ${INCDIRS}
	${MKDIR} ${PREFIX}/include/Box2D/${d}
	${INSTALL_DATA} ${BUILD_WRKSRC}/${d}/*.h ${PREFIX}/include/Box2D/${d}
.endfor
	${REINPLACE_CMD} -i '' -e 's|"\.\./Source/\(.*\)"|<Box2D/\1>|' \
		${PREFIX}/include/Box2D.h
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/Documentation && ${COPYTREE_SHARE} '*' ${DOCSDIR}/
.endif
.if defined(WITH_TESTBED)
	${INSTALL_PROGRAM} ${WRKSRC}/Examples/TestBed/${ALL_TARGET:C/libbox2d.a/testbed/} \
		${PREFIX}/bin/box2d-testbed
.endif

.include <bsd.port.mk>
