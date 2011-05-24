# New ports collection makefile for:	mygui
# Date created:		28 Sep 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mygui
PORTVERSION=	2.2.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/my-gui/MyGUI/MyGUI_${PORTVERSION}
DISTNAME=	MyGUI${PORTVERSION}_source

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast, simple and flexible GUI system for Ogre engine

LIB_DEPENDS=	uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid \
		freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so:${PORTSDIR}/graphics/ogre3d \
		${LOCALBASE}/lib/libOIS.so:${PORTSDIR}/devel/ois
RUN_DEPENDS=	${LOCALBASE}/lib/libOgreMain.so:${PORTSDIR}/graphics/ogre3d \
		${LOCALBASE}/lib/libOIS.so:${PORTSDIR}/devel/ois

USE_ZIP=	yes
USE_AUTOTOOLS=	libtool:env aclocal:env autoconf:env automake:env
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.am | ${XARGS} \
		${REINPLACE_CMD} -e '/Shared\/linux/ s|INSTALL_PROGRAM|INSTALL_SCRIPT|; \
			/^pkgconfigdir =/ s|libdir)/|prefix)/libdata/|'

run-autotools:
	@cd ${WRKSRC} && ${SH} ./bootstrap

.include <bsd.port.mk>
