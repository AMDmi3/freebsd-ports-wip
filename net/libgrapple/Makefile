# New ports collection makefile for:	libgrapple
# Date created:		12 Aug 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgrapple
PORTVERSION=	0.9.8
CATEGORIES=	net
MASTER_SITES=	http://osfiles.linuxgamepublishing.com/ \
		http://mirror.amdmi3.ru/distfiles/
EXTRACT_SUFX=	.tbz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A high level network layer for multiuser applications

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS=	SSL "Enable OpenSSL support" yes

.include <bsd.port.options.mk>

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=--disable-openssl

.else
USE_OPENSSL=	yes
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC} " \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
.endif

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
