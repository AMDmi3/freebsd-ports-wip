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
		webkit-1.0.13:${PORTSDIR}/www/webkit-gtk2 \
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gosm ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
