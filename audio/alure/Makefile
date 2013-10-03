# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	alure
PORTVERSION=	1.2
CATEGORIES=	audio
MASTER_SITES=	http://kcat.strangesoft.net/alure-releases/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	AL Utilities REtooled

USE_BZIP2=	yes
USE_OPENAL=	al
USES=		cmake pkgconfig
CMAKE_ARGS=	-DCMAKE_REQUIRED_INCLUDES="${LOCALBASE}/include" \
		-DCMAKE_REQUIRED_LIBRARIES="-L${LOCALBASE}/lib"
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	SNDFILE VORBIS FLAC MPG123 DUMB MODPLUG FLUIDSYNTH DOCS EXAMPLES
OPTIONS_DEFAULT=SNDFILE VORBIS FLAC MPG123 DUMB FLUIDSYNTH DOCS EXAMPLES

SNDFILE_DESC=	SoundFile support (for various formats)
VORBIS_DESC=	VorbisFile support (for Ogg Vorbis)
FLAC_DESC=	FLAC support (for FLAC and Ogg FLAC)
MPG123_DESC=	MPG123 support (for MP1/MP2/MP3)
DUMB_DESC=	DUMB support (for IT/XM/S3M/MOD)
MODPLUG_DESC=	ModPlug support (for IT/XM/S3M/MOD)
FLUIDSYNTH_DESC=FluidSynth support (for MID)
EXAMPLES_DESC=	Build and install example programs

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSNDFILE}
LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile
CMAKE_ARGS+=	-DSNDFILE:BOOL=ON
.else
CMAKE_ARGS+=	-DSNDFILE:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
CMAKE_ARGS+=	-DVORBIS:BOOL=ON
.else
CMAKE_ARGS+=	-DVORBIS:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
CMAKE_ARGS+=	-DFLAC:BOOL=ON
.else
CMAKE_ARGS+=	-DFLAC:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MMPG123}
LIB_DEPENDS+=	mpg123:${PORTSDIR}/audio/mpg123
CMAKE_ARGS+=	-DMPG123:BOOL=ON
.else
CMAKE_ARGS+=	-DMPG123:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MDUMB}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libdumb.a:${PORTSDIR}/audio/dumb
CMAKE_ARGS+=	-DDUMB:BOOL=ON
.else
CMAKE_ARGS+=	-DDUMB:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MMODPLUG}
LIB_DEPENDS+=	modplug:${PORTSDIR}/audio/libmodplug
CMAKE_ARGS+=	-DMODPLUG:BOOL=ON
.else
CMAKE_ARGS+=	-DMODPLUG:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MFLUIDSYNTH}
LIB_DEPENDS+=	fluidsynth:${PORTSDIR}/audio/fluidsynth
CMAKE_ARGS+=	-DFLUIDSYNTH:BOOL=ON
.else
CMAKE_ARGS+=	-DFLUIDSYNTH:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
.else
CMAKE_ARGS+=	-DBUILD_EXAMPLES:BOOL=OFF
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|lib$${LIB_SUFFIX}/pkgconfig|libdata/pkgconfig|; \
		/FIND_PROGRAM.*NaturalDocs/d; s|LIBFLAC|FLAC|' ${WRKSRC}/CMakeLists.txt
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/INSTALL.*DIRECTORY.*docs\/html/,/^)/d' \
		${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
