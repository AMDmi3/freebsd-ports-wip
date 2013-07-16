# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	centerim5
PORTVERSION=	5.0.0beta1
CATEGORIES=	net-im
MASTER_SITES=	http://www.centerim.org/download/cim5/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Text mode menu- and window-driven IM interface

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	purple:${PORTSDIR}/net-im/libpurple \
		sigc-2.0:${PORTSDIR}/devel/libsigc++20

GNU_CONFIGURE=	yes
USES=		ncurses:port
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		centerim5.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
