# New ports collection makefile for:	notion
# Date created:		20 Oct 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	notion
PORTVERSION=	20110930
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}/snapshots
DISTNAME=	${PORTNAME}-snapshot-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A tiling tabbed window manager

USE_BZIP2=	yes
USE_XORG=	x11 xext sm xinerama xrandr
USE_LUA=	5.1+
USE_GMAKE=	yes
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/notion

PORTDOCS=	*

MANLANG=	"" cs fi
MAN1=		notion.1 pwm3.1

.if defined(NOPORTDOCS)
post-patch:
	@${REINPLACE_CMD} -e '/^_install:/,/^$$/ d' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
