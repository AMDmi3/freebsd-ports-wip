# New ports collection makefile for:	libclaw
# Date created:		28 Mar 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD: ports/devel/libclaw/Makefile,v 1.7 2010/03/28 06:33:18 dinoex Exp $
#

PORTNAME=	libclaw
PORTVERSION=	1.7.0
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++ Library Absolutely Wonderful

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png

USE_CMAKE=	yes
CMAKE_ARGS=	-DCLAW_CMAKE_MODULES_INSTALL_PATH="${PREFIX}/lib/claw"
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e '/subdirs/ s|doc||' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/install.*COPYING/ d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
