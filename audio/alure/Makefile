# New ports collection makefile for:	alure
# Date created:		28 Sep 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	alure
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	http://kcat.strangesoft.net/alure-releases/ \
		http://mirror.amdmi3.ru/distfiles/
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	AL Utilities REtooled

USE_BZIP2=	yes
USE_OPENAL=	al
USE_GNOME=	pkgconfig
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/INSTALL.*DIRECTORY.*docs\/html/,/^)/d' \
		${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
