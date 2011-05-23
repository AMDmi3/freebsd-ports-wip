# New ports collection makefile for:	tut
# Date created:		04 Aug 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tut
DISTVERSION=	2008-11-30
CATEGORIES=	devel
MASTER_SITES=	SF/tut-framework

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Pure C++ unit test framework

NO_BUILD=	yes

post-extract:
	${RM} -rf ${WRKSRC}/tut/.svn

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "*.h tut" ${PREFIX}/include

.include <bsd.port.mk>
