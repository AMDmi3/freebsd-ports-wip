# New ports collection makefile for:	musescore
# Date created:		28 Jul 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	musescore
PORTVERSION=	1.1
CATEGORIES=	audio
MASTER_SITES=	SF/mscore/mscore/MuseScore-${PORTVERSION}
DISTNAME=	mscore-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Empty comment

LIB_DEPENDS=	asound.2:${PORTSDIR}/audio/alsa-lib \
		sndfile.1:${PORTSDIR}/audio/libsndfile

CONFLICTS=	qtscriptgenerator-*

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network svg xml script scripttools designer webkit \
		qmake_build moc_build uic_build linguist_build rcc_build
MAKE_JOBS_SAFE=	yes

CMAKE_SOURCE_PATH=	${WRKSRC}/mscore
CMAKE_OUTSOURCE=	yes

ALL_TARGET=	lrelease all

OPTIONS=	JACK "Jack support" on \
		PORTAUDIO "Portaudio support" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_JACK)
CMAKE_ARGS+=	-DBUILD_JACK_BOOL=ON
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.else
CMAKE_ARGS+=	-DBUILD_JACK_BOOL=OFF
.endif

.if !defined(WITHOUT_PORTAUDIO)
LIB_DEPENDS+=	portaudio.2:${PORTSDIR}/audio/portaudio2
.endif

post-patch:
.if defined(WITHOUT_PORTAUDIO)
	@${REINPLACE_CMD} -ie '/PKGCONFIG.*portaudio/ d' ${WRKSRC}/mscore/CMakeLists.txt
.endif
	@${REINPLACE_CMD} -e 's|/usr/include/freetype2|${LOCALBASE}/include/freetype2|; \
		s|-lfreetype|${LOCALBASE}/lib/libfreetype.so|' \
		${WRKSRC}/mscore/mscore/CMakeLists.txt
# XXX: make optional
	@${REINPLACE_CMD} -e '/TargetDoc.cmake/ d' ${WRKSRC}/mscore/CMakeLists.txt
# XXX: fix CFLAGS override and useless -g in all CMakeLists

.include <bsd.port.mk>
