# New ports collection makefile for:	tilesathome
# Date created:		03 Sep 2010
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tilesathome
PORTVERSION=	1.0
CATEGORIES=	graphics geography
MASTER_SITES=	# empty
PKGNAMESUFFIX=	-prerequisites
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Meta-port for Tiles@Home prerequisites

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/dejavu:${PORTSDIR}/x11-fonts/dejavu \
		inkscape:${PORTSDIR}/graphics/inkscape \
		p5-AppConfig>=0:${PORTSDIR}/devel/p5-AppConfig \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run \
		p5-Math-Vec>=0:${PORTSDIR}/math/p5-Math-Vec \
		p5-Module-Pluggable>=0:${PORTSDIR}/devel/p5-Module-Pluggable \
		p5-Set-Object>=0:${PORTSDIR}/devel/p5-Set-Object \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer \
		p5-XML-XPath>=0:${PORTSDIR}/textproc/p5-XML-XPath \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-libxml>=0:${PORTSDIR}/textproc/p5-libxml \
		pngcrush:${PORTSDIR}/graphics/pngcrush \
		pngnq:${PORTSDIR}/graphics/pngnq \
		svn:${PORTSDIR}/devel/subversion \
		xml:${PORTSDIR}/textproc/xmlstarlet \
		zip:${PORTSDIR}/archivers/zip

NO_BUILD=	yes

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
