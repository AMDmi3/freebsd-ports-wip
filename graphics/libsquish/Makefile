# New ports collection makefile for:	libsquish
# Date created:		12 Aug 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libsquish
PORTVERSION=	1.10
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	squish-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open source DXT compression library

USE_GMAKE=	yes
MAKE_ENV=	INSTALL_DIR="${PREFIX}"
MAKE_JOBS_SAFE=	yes

PORTDOCS=	README ChangeLog
PLIST_FILES=	include/squish.h lib/libsquish.a

OPTIONS=	ALTIVEC	"Use Altivec instructions" off \
		SSE "Use SSE2 instructions" off

.include <bsd.port.options.mk>

.if ${ARCH} != "i386"
CXXFLAGS+=	-fPIC
.endif

.if defined(WITH_ALTIVEC)
MAKE_ENV+=	USE_ALTIVEC=1
.endif
.if defined(WITH_SSE)
MAKE_ENV+=	USE_SSE=1
.endif

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
