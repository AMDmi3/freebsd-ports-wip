# New ports collection makefile for:	panda3d
# Date created:		08 Feb 2010
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	panda3d
PORTVERSION=	1.7.2
CATEGORIES=	devel graphics games
MASTER_SITES=	http://www.panda3d.org/download/panda3d-${PORTVERSION}/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open source 3D Engine and game development framework

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_PYTHON=	yes
USE_BISON=	build
MAKE_JOBS_UNSAFE=yes

AUTOPLIST_DIRS=	${PREFIX}/bin/panda3d ${PREFIX}/include/panda3d \
		${PREFIX}/lib/panda3d ${DATADIR}

MAKEPANDA_ARGS=	${_MAKE_JOBS:C/-j/--threads /} --nothing
MAKEPANDA_ARGS+=--use-direct --use-deploytools # required for successfull build
MAKEPANDA_ARGS+=--use-zlib --use-png --use-jpeg --use-tiff # cheap

PORTDOCS=	README ReleaseNotes

OPTIONS=	PYTHON "Python support" on \
		GL "OpenGL support" on \
		OPENAL "OpenAL support" on \
		FFMPEG "ffmpeg support" on \
		ODE "ODE support" on \
		FREETYPE "Freetype support" on \
		OPENSSL "OpenSSL support" on \
		NPAPI "NPAPI support" on \
		GTK2 "GTK2 support" on \
		WX "wx support" on \
		X11 "X11 extensions support" on \
		PANDATOOL "pandatool support" on \
		PVIEW "pview support" on \
		CONTRIB "contrib support" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_PYTHON)
MAKEPANDA_ARGS+=--use-python
.endif

.if !defined(WITHOUT_GL)
USE_GL=		gl
MAKEPANDA_ARGS+=--use-gl
.endif

.if !defined(WITHOUT_FFMPEG)
# ffmpeg requires swscale, so both options are merged
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
MAKEPANDA_ARGS+=--use-ffmpeg --use-swscale
.endif

.if !defined(WITHOUT_ODE)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libode.a:${PORTSDIR}/devel/ode
MAKEPANDA_ARGS+=--use-ode
.endif

.if !defined(WITHOUT_OPENAL)
MAKEPANDA_ARGS+=--use-openal
USE_OPENAL=	yes
.endif

.if !defined(WITHOUT_FREETYPE)
MAKEPANDA_ARGS+=--use-freetype
USE_FREETYPE2=	yes
.endif

.if !defined(WITHOUT_OPENSSL)
MAKEPANDA_ARGS+=--use-openssl
USE_OPENSSL=	yes
.endif

.if defined(WITH_NPAPI)
MAKEPANDA_ARGS+=--use-npapi
# DEPENDS?
.endif

.if defined(WITH_GTK2)
MAKEPANDA_ARGS+=--use-gtk2
USE_GNOME+=	gtk20
.endif

.if defined(WITH_WX)
MAKEPANDA_ARGS+=--use-wx
USE_WX=		2.6+
.endif

.if !defined(WITHOUT_X11)
MAKEPANDA_ARGS+=--use-x11 --use-xf86dga --use-xrandr --use-xcursor
USE_XORG+=	x11 xxf86dga xrandr xcursor
.endif

.if !defined(WITHOUT_PANDATOOL)
MAKEPANDA_ARGS+=--use-pandatool
.endif

.if !defined(WITHOUT_PVIEW)
MAKEPANDA_ARGS+=--use-pview
.endif

.if !defined(WITHOUT_CONTRIB)
MAKEPANDA_ARGS+=--use-contrib
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O.||; s|gcc|${CC} ${CFLAGS}|; \
		s|g++|${CXX} ${CXXFLAGS}|; s|-lpthread|${PTHREAD_LIBS}|; \
		s|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/makepanda/makepanda.py
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|; \
		/PPATH =/ s|get_python_lib(1)|&.replace("${LOCALBASE}", "${PREFIX}")|' \
		${WRKSRC}/makepanda/installpanda.py
	@${REINPLACE_CMD} -e '/VERBOSE/ s|False|True|' \
		${WRKSRC}/makepanda/makepandacore.py

do-build:
	cd ${WRKSRC} && ${PYTHON_CMD} makepanda/makepanda.py \
		${MAKEPANDA_ARGS}

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} makepanda/installpanda.py \
		--prefix=${PREFIX}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${FIND} ${AUTOPLIST_DIRS} -type f -o -type l | \
		${SED} -e 's|^${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} ${AUTOPLIST_DIRS} -type d | ${SORT} -r | \
		${SED} -e 's|^${PREFIX}/|@dirrm |' >> ${TMPPLIST}

.include <bsd.port.mk>
