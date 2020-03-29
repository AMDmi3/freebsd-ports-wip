# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	notion
DISTVERSION=	4.0.0
CATEGORIES=	x11-wm

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tiling tabbed window manager

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	raboof

USES=		gettext gmake groff lua:53 pkgconfig readline xorg
USE_XORG=	x11 xext xft sm ice xinerama xrandr
MAKE_ENV=	LUA_VERSION="${LUA_VER}" \
		LUA_INCLUDES="-isystem${LUA_INCDIR}" \
		LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}" \
		LUA="${LUA_CMD}" \
		LUAC="${LUAC_CMD}" \
		USE_XFT=1 \
		USE_READLINE=1 \
		MANDIR="${MANDIR}" \
		NOTION_RELEASE="${DISTVERSION}"

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/notion* \
		${STAGEDIR}${PREFIX}/lib/notion/bin/* \
		${STAGEDIR}${PREFIX}/lib/notion/mod/*.so

.include <bsd.port.mk>
