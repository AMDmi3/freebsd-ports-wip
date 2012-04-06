# New ports collection makefile for:	mygui
# Date created:		28 Sep 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mygui
PORTVERSION=	3.2.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/my-gui/MyGUI/MyGUI_${PORTVERSION}
DISTNAME=	MyGUI_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast, simple and flexible GUI system for Ogre engine

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so:${PORTSDIR}/graphics/ogre3d \
		${LOCALBASE}/lib/libOIS.so:${PORTSDIR}/devel/ois
RUN_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so:${PORTSDIR}/graphics/ogre3d \
		${LOCALBASE}/lib/libOIS.so:${PORTSDIR}/devel/ois

USE_ZIP=	yes
USE_CMAKE=	yes
CMAKE_ARGS=	-DMYGUI_BUILD_DEMOS=OFF -DMYGUI_BUILD_DOCS=OFF
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/install/ s|lib/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMake/ConfigureBuild.cmake

.include <bsd.port.mk>
