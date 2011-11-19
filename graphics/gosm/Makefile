# New ports collection makefile for:	gosm
# Date created:		29 Jun 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gosm
PORTVERSION=	0.0.9
CATEGORIES=	graphics geography
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.09
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Empty comment

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		curl.6:${PORTSDIR}/ftp/curl \
		webkitgtk-1.0.0:${PORTSDIR}/www/webkit-gtk2 \
		png.6:${PORTSDIR}/graphics/png

LICENSE=	GPLv3

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_GNOME=	gtk20 glib20 pango
USE_GCC=	4.4+
ALL_TARGET=	gosm

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/gosm

PORTDOCS=	README

post-extract:
	@${RM} -f ${WRKSRC}/gosm

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/poi/RTree/*.c
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/paths.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gosm ${PREFIX}/bin/
	${MKDIR} ${DATADIR}/about
	${INSTALL_DATA} ${WRKSRC}/about/*.html ${DATADIR}/about/
	${INSTALL_DATA} ${WRKSRC}/about/*.png ${DATADIR}/about/
	${MKDIR} ${DATADIR}/manual
	${INSTALL_DATA} ${WRKSRC}/manual/*.html ${DATADIR}/manual/
	${INSTALL_DATA} ${WRKSRC}/manual/*.png ${DATADIR}/manual/
	${MKDIR} ${DATADIR}/namefinder/res
	${INSTALL_DATA} ${WRKSRC}/namefinder/res/*.txt ${DATADIR}/namefinder/res/
	${MKDIR} ${DATADIR}/poi/res/
	${INSTALL_DATA} ${WRKSRC}/poi/res/poi_layers ${DATADIR}/poi/res/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "icons legend" ${DATADIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
