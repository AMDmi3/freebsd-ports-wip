# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	notion
PORTVERSION=	2013030200
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	${PORTNAME}-3-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A tiling tabbed window manager

USE_BZIP2=	yes
USE_XORG=	x11 xext sm xinerama xrandr
USE_LUA=	5.1+
USE_GMAKE=	yes
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-3-${PORTVERSION}

PORTDOCS=	*

MANLANG=	"" cs fi
MAN1=		notion.1

OPTIONS_DEFINE=	XINERAMA XRANDR DOCS
OPTIONS_DEFAULT=XINERAMA XRANDR
XINERAMA_DESC=	Xinerama module support
XRANDR_DESC=	Xrandr module support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXINERAMA}
USE_XORG+=	xinerama
PLIST_SUB+=	XINERAMA=""
.else
PLIST_SUB+=	XINERAMA="@comment "
.endif

.if ${PORT_OPTIONS:MXRANDR}
USE_XORG+=	xrandr
PLIST_SUB+=	XRANDR=""
.else
PLIST_SUB+=	XRANDR="@comment "
.endif

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^_install:/,/^$$/ d' ${WRKSRC}/Makefile
.endif
.if ! ${PORT_OPTIONS:MXINERAMA}
	@${REINPLACE_CMD} -e 's|mod_xinerama||' ${WRKSRC}/modulelist.mk
.endif
.if ! ${PORT_OPTIONS:MXRANDR}
	@${REINPLACE_CMD} -e 's|mod_xrandr||' ${WRKSRC}/modulelist.mk
.endif

.include <bsd.port.mk>
