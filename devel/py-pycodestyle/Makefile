# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD: head/devel/py-pycodestyle-devel/Makefile 498530 2019-04-10 06:18:31Z antoine $

PORTNAME=	pycodestyle
PORTVERSION=	2.5.0git20191021
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Python style guide checker

LICENSE=	MIT # mentioned as "Expat"

USE_GITHUB=	yes
GH_ACCOUNT=	PyCQA
GH_TAGNAME=	d219c68

USES=		python
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
