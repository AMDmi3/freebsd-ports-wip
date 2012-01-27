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
PKGNAMESUFFIX=	-amdmi3

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

OPTIONS=	XINERAMA "Xinerama module support" on \
		XRANDR "Xrandr module support" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_XINERAMA)
USE_XORG+=	xinerama
PLIST_SUB+=	XINERAMA=""
.else
PLIST_SUB+=	XINERAMA="@comment "
.endif

.if !defined(WITHOUT_XRANDR)
USE_XORG+=	xrandr
PLIST_SUB+=	XRANDR=""
.else
PLIST_SUB+=	XRANDR="@comment "
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^_install:/,/^$$/ d' ${WRKSRC}/Makefile
.endif
.if defined(WITHOUT_XINERAMA)
	@${REINPLACE_CMD} -e 's|mod_xinerama||' ${WRKSRC}/modulelist.mk
.endif
.if defined(WITHOUT_XRANDR)
	@${REINPLACE_CMD} -e 's|mod_xrandr||' ${WRKSRC}/modulelist.mk
.endif

.include <bsd.port.mk>
