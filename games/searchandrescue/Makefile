# New ports collection makefile for:	searchandrescue
# Date created:		25 Sep 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	searchandrescue
PORTVERSION=	1.4.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Program:src \
		SF/${PORTNAME}/Data_Files:data
DISTFILES=	SearchAndRescue-${PORTVERSION}${EXTRACT_SUFX}:src \
		SearchAndRescue-data-${DATAVERSION}${EXTRACT_SUFX}:data
EXTRACT_ONLY=	SearchAndRescue-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Search and Rescue flight simulator

DATAVERSION=	1.3.0

USE_SDL=	sdl mixer
USE_XORG=	x11 xext xmu xpm xxf86vm sm ice
USE_GL=		gl glu
MAKE_JOBS_SAFE=	yes

MAKE_ENV+=	SEARCHANDRESCUE_DATA="${DATADIR}"

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/sar

PLIST_FILES=	bin/SearchAndRescue \
		share/applications/SearchAndRescue.desktop \
		share/pixmaps/SearchAndRescue.xpm
PLIST_DIRSTRY=	share/applications
PORTDATA=	*
PORTDOCS=	README AUTHORS

MAN6=		SearchAndRescue.6

OPTIONS=	OPTIMIZED_CFLAGS "Enable additional optimizations" on

.include <bsd.port.options.mk>

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -funroll-loops -fomit-frame-pointer -ffast-math -finline-functions -fexpensive-optimizations
.endif

post-extract:
	@cd ${WRKSRC} && ${BZIP2_CMD} -d sar/man/SearchAndRescue.6.bz2
	@${MKDIR} ${WRKSRC}/data
	@cd ${WRKSRC}/data && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/SearchAndRescue-data-${DATAVERSION}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/games/searchandrescue|${DATADIR}|; \
		s|/usr/share/pixmaps|${PREFIX}/share/pixmaps|' ${WRKSRC}/sar/config.h
	@${ECHO_CMD} 'Icon=SearchAndRescue' >> ${WRKSRC}/SearchAndRescue.desktop

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/SearchAndRescue ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/sar/man/SearchAndRescue.6 ${MAN6PREFIX}/man/man6/
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/SearchAndRescue.desktop ${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/SearchAndRescue.xpm ${PREFIX}/share/pixmaps/
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} "*" ${DATADIR}/
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
