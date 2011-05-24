# New ports collection makefile for:	stressapptest
# Date created:		09 Jan 2010
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stressapptest
PORTVERSION=	1.0.1
CATEGORIES=	benchmarks
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}_autoconf

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Stressful Application Test

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/stressapptest

MAN1=		stressapptest.1

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/stressapptest ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/stressapptest.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.post.mk>
