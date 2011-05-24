# New ports collection makefile for:	thebutterflyeffect
# Date created:		24 May 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	thebutterflyeffect
DISTVERSION=	m8.2
CATEGORIES=	games
MASTER_SITES=	SF/tbe/${PORTVERSION:C/m/Milestone%20/}/
DISTNAME=	TheButterflyEffect-${DISTVERSION}
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Physics-based logic game

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build uic_build moc_build rcc_build corelib gui xml svg
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	AUTHORS README RUNNING

post-extract:
	@cd ${WRKSRC}/3rdParty && ${UNZIP_CMD} -q Box2D_v2.0.1.zip && \
		for f in *.patch; do ${PATCH} --silent -p0 <$$f; done

do-configure:
	${SED} 's|%%DATADIR|QString(\"${DATADIR}\")|' < ${WRKSRC}/src/tbe_global.h.in \
		> ${WRKSRC}/src/tbe_global.h
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} tbe.pro

do-build:
	cd ${WRKSRC}/3rdParty/Box2D_v2.0.1/Box2D/Source && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} Gen/float/libbox2d.a
	${CP} ${WRKSRC}/3rdParty/Box2D_v2.0.1/Box2D/Source/Gen/float/libbox2d.a \
		${WRKSRC}/3rdParty/lib/
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tbe ${PREFIX}/bin/tbe
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "images levels i18n" ${DATADIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
