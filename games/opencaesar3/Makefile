# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opencaesar3
PORTVERSION=	git20130823
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Remake of the classic Caesar3 PC game

LICENSE=	GPLv3

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		boost_filesystem:${PORTSDIR}/devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	dalerank
GH_TAGNAME=	de67868
GH_COMMIT=	de67868

USES=		cmake gettext
USE_SDL=	sdl mixer image ttf
USE_GL=		gl
MAKE_JOBS_SAFE=	yes

SUB_FILES=	pkg-message
PORTDOCS=	README.md INSTALL_LINUX

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/std::string application_path = / s|=.*|= "${DATADIR}";|' \
		${WRKSRC}/oc3_app_config.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/caesar3 ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "resources" ${DATADIR}/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "*.model locale" ${DATADIR}/resources/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
