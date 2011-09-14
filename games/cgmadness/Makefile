# New ports collection makefile for:	cgmadness
# Date created:		12 Sep 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cgmadness
PORTVERSION=	1.3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/CG%20Madness/${PORTVERSION} \
		http://www.fluxparticle.com/cgmadness/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Empty comment

LIB_DEPENDS=	GLEW.1:${PORTSDIR}/graphics/glew \
		grapple-0.9.7:${PORTSDIR}/net/libgrapple

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GL=		gl glu glut
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -lgrapple -lglut -lGLEW ${PTHREAD_LIBS}

# Remove after ldflags megapatch merge
MAKE_ENV=	LDFLAGS="${LDFLAGS}"

WRKSRC=		${WRKDIR}/${PORTNAME}

post-extract:
	@${RM} -rf ${WRKSRC}/libgrapple

post-patch:
	@${FIND} ${WRKSRC} -name "*.hpp" | ${XARGS} \
		${REINPLACE_CMD} -i '' -e 's|\(include \)\("libgrapple\)\(/.*\)\("\)|\1<grapple\3>|'
	@${FIND} ${WRKSRC} -name "*.cpp" | ${XARGS} \
		${REINPLACE_CMD} -i '' -e 's|data/|${DATADIR}/&|g'
	${REINPLACE_CMD} -i '' -e 's|levels|${DATADIR}/&|' ${WRKSRC}/LevelLoader.cpp
	${REINPLACE_CMD} -i '' -e 's|[a-z]*.[vf][er][ra][gt]"|${DATADIR}/&|g' ${WRKSRC}/hw/features.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cgmadness ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "data levels *.vert *.frag" ${DATADIR}/

.include <bsd.port.mk>
