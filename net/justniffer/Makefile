# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	justniffer
PORTVERSION=	0.5.11
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Network TCP Packet Sniffer

LICENSE=	GPLv3

LIB_DEPENDS=	libboost_regex.so:${PORTSDIR}/devel/boost-libs
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost-regex=boost_regex \
		--with-boost-program-options=boost_program_options \
		--with-boost-iostreams=boost_iostreams

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		man/man8/justniffer.8.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} 's|netinet/ip.h|netinet/in.h|' ${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/ChangeLog \
		${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
