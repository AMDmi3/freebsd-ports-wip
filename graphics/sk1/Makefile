# New ports collection makefile for:	sk1
# Date created:		28 Oct 2010
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sK1
DISTVERSION=	0.9.1pre_rev905
CATEGORIES=	graphics python
MASTER_SITES=	http://sk1project.org/downloads/sk1/${DISTVERSION}/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Vector graphics editor for prepress

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/sk1libs/__init__.py:${PORTSDIR}/graphics/sk1libs \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_XORG=	x11 xext
USE_TCL=	85+
USE_TK=		85+
USE_GETTEXT=	yes

MAKE_ENV=	TCL_VER=${TCL_VER:C/\.//} TK_VER=${TK_VER:C/\.//}

PYDISTUTILS_BUILD_TARGET=build_ext
PYDISTUTILS_BUILDARGS=	-L${LOCALBASE}/lib \
			-I${LOCALBASE}/include:${LOCALBASE}/include/freetype2:${LOCALBASE}/include/cairo:${TCL_INCLUDEDIR}:${TK_INCLUDEDIR}
PYDISTUTILS_PKGVERSION=	${DISTVERSION:C/_rev.*//}

WRKSRC=		${WRKDIR}/${DISTNAME:C/_rev.*//}

.include <bsd.port.mk>
