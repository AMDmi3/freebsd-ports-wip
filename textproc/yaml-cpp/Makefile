# New ports collection makefile for:	yaml-cpp
# Date created:		03 Oct 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yaml-cpp
PORTVERSION=	0.2.7
CATEGORIES=	textproc
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A YAML parser and emitter for C++

USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

regression-test:
	cd ${CONFIGURE_WRKSRC} && ${CMAKE_BIN:C/cmake/ctest/}

.include <bsd.port.mk>
