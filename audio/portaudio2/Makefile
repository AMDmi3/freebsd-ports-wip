# New ports collection makefile for:	portaudio
# Date created:		18 May 2003
# Whom:			michaelnottebrock@gmx.net and lioux@FreeBSD.org
#
# $FreeBSD: ports/audio/portaudio2/Makefile,v 1.16 2009/03/04 18:02:45 thierry Exp $
#

PORTNAME=	portaudio
DISTVERSION=	19_20110326
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	pa_stable_v${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable cross-platform Audio API

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-alsa	\
		--libdir=${PREFIX}/lib/${PORTNAME}2 --includedir=${PREFIX}/include/${PORTNAME}2
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}2

LATEST_LINK=	${PORTNAME}2
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	JACK "JACK support" off

.include <bsd.port.options.mk>

.if !defined(WITH_JACK)
CONFIGURE_ARGS+=	--without-jack
PLIST_SUB+=	JACK="@comment "
.else
# NO circular dependency as audio/jack depends on portaudio18
CONFIGURE_ARGS+=	--with-jack
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
PLIST_SUB+=	JACK=""
.endif

pre-configure:
# replace obsolete headers, and fix up thread library
	${FIND} ${WRKSRC} -type f \
		| ${XARGS} -x -n 10 \
			${REINPLACE_CMD} -E \
				-e 's|malloc.h|stdlib.h|' \
				-e 's|-lpthread|${PTHREAD_LIBS}|'
	${REINPLACE_CMD} -e '/pkgconfig/s|$$[(]libdir[)]|${PREFIX}/libdata|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
