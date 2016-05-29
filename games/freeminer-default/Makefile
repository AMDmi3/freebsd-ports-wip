# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD: head/games/freeminer-default/Makefile 397337 2015-09-19 20:00:54Z amdmi3 $

PORTNAME=	default
PORTVERSION=	0.4.14.8
CATEGORIES=	games
PKGNAMEPREFIX=	freeminer-
DIST_SUBDIR=	freeminer

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Main game for the Freeminer game engine

LICENSE=	LGPL21+

RUN_DEPENDS=	freeminer:${PORTSDIR}/games/freeminer

USE_GITHUB=	yes
GH_ACCOUNT=	freeminer
GH_TUPLE=	stujones11:minetest-3d_armor:ac414d3:3d_armor \
		BlockMen:dungeon_loot:2391f04:dungeon_loot \
		HybridDog:heads:27c9b5a:heads \
		tenplus1:mobs_animal:7b106ab:mobs_animal \
		tenplus1:mobs_monster:f83ecdf:mobs_monster \
		tenplus1:mobs_npc:796589d:mobs_npc \
		tenplus1:mobs_redo:c6d4b95:mobs_redo \
		tenplus1:protector:a37e8e6:protector

NO_BUILD=	yes
NO_ARCH=	yes
DATADIR=	${PREFIX}/share/freeminer/games/${PORTNAME}
PORTDATA=	*

post-extract:
.for mod in 3d_armor dungeon_loot heads mobs_animal mobs_monster mobs_npc mobs_redo protector
	@${MV} ${WRKSRC_${mod}}/* ${WRKSRC}/mods/${mod}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
