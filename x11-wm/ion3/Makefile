# New ports collection makefile for:	ion3
# Date created:		30 Sep 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ion3
PORTVERSION=	20090110
CATEGORIES=	x11-wm
MASTER_SITES=	http://modeemi.fi/~tuomov/dl/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME:C/([0-9])/-\1/}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A tiling tabbed window manager

USE_XORG=	x11 xext sm
USE_LUA=	5.1+
USE_GMAKE=	yes
USE_GETTEXT=	yes
MAKE_JOBS_UNSAFE=yes

PORTDOCS=	*

MANLANG=	"" cs fi
MAN1=		ion3.1 pwm3.1

.if defined(NOPORTDOCS)
post-patch:
	@${REINPLACE_CMD} -e '/^_install:/,/^$$/ d' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
