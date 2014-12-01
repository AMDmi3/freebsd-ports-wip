# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	notion
PORTVERSION=	2014091000
CATEGORIES=	x11-wm

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A tiling tabbed window manager

USE_GITHUB=	yes
GH_ACCOUNT=	raboof
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	b74deb9

USE_XORG=	x11 xext sm
USES=		gmake gettext tar:bzip2 lua pkgconfig

PORTDOCS=	*

OPTIONS_DEFINE=	XINERAMA XRANDR DOCS
OPTIONS_DEFAULT=XINERAMA XRANDR
OPTIONS_SUB=	yes

XINERAMA_DESC=	Xinerama module support
XINERAMA_USE=	XORG=xinerama
XRANDR_DESC=	Xrandr module support
XRANDR_USE=	XORG=xrandr

.include <bsd.port.options.mk>

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

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/notion \
		${STAGEDIR}${PREFIX}/lib/notion/bin/* \
		${STAGEDIR}${PREFIX}/lib/notion/mod/*.so

.include <bsd.port.mk>
