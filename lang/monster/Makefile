# New ports collection makefile for:	monster
# Date created:		14 Jun 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	monster
PORTVERSION=	0.14
CATEGORIES=	lang
MASTER_SITES=	SF/monster-script/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Advanced scripting language made for game programming

BUILD_DEPENDS=	dsss:${PORTSDIR}/devel/dsss \
		gdc:${PORTSDIR}/lang/gdc

DSSS?=		${LOCALBASE}/bin/dsss
DSSS_ARGS=	--prefix="${PREFIX}"

PORTDOCS=	*

do-build:
	cd ${WRKSRC} && ${DSSS} build ${DSSS_ARGS}

do-install:
	cd ${WRKSRC} && ${DSSS} install ${DSSS_ARGS}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
