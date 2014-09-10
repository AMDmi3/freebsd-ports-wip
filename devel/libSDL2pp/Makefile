# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libSDL2pp
PORTVERSION=	0.1.1
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++ wrapper for libSDL2

USE_GITHUB=	yes
GH_ACCOUNT=	AMDmi3
GH_COMMIT=	6150f41

USES=		compiler:c++11-lib cmake
USE_SDL=	sdl2 image2

CXXFLAGS+=	-D_GLIBCXX_USE_C99

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
