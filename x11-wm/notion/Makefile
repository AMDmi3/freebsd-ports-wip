# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	notion
PORTVERSION=	2013030200
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	${PORTNAME}-3-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A tiling tabbed window manager

USE_XORG=	x11 xext sm xinerama xrandr
USES=		gmake gettext tar:bzip2 lua pkgconfig

WRKSRC=		${WRKDIR}/${PORTNAME}-3-${PORTVERSION}

PORTDOCS=	*

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
	@${REINPLACE_CMD} -e '/pkg-config/ s|lua5.2|lua-5.2|g; \
		/which/ s|lua5.2|lua52|; /which/ s|luac5.2|luac52|' \
		${WRKSRC}/system-autodetect.mk
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/ioncore/Makefile
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^_install:/,/^$$/ d' ${WRKSRC}/Makefile
.endif
.if ! ${PORT_OPTIONS:MXINERAMA}
	@${REINPLACE_CMD} -e 's|mod_xinerama||' ${WRKSRC}/modulelist.mk
.endif
.if ! ${PORT_OPTIONS:MXRANDR}
	@${REINPLACE_CMD} -e 's|mod_xrandr||' ${WRKSRC}/modulelist.mk
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/notion \
		${STAGEDIR}${PREFIX}/lib/notion/bin/* \
		${STAGEDIR}${PREFIX}/lib/notion/mod/*.so

.include <bsd.port.mk>
