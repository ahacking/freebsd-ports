# Created by: Pakhom Golynga <pg@pakhom.spb.ru>
# $FreeBSD$

PORTNAME=	zabbix4
CATEGORIES=	net-mgmt
PKGNAMESUFFIX=	-frontend

MASTERDIR=	${.CURDIR}/../zabbix4-server

NO_BUILD=	yes
NO_ARCH=	yes
PATCHDIR=
PLIST=		${PKGDIR}/pkg-plist.frontend

USE_PHP=	bcmath ctype dom filter gd gettext json ldap mbstring pcre \
		session simplexml snmp sockets xml xmlreader xmlwriter
USES+=		php:web

OPTIONS_DEFINE=		MYSQL MYSQLI PGSQL ORACLE
OPTIONS_DEFAULT=	MYSQLI
MYSQLI_DESC=		MySQLI backend

MYSQL_VARS=	IGNORE_WITH_PHP+="70 71 72 73"
MYSQL_USE=	PHP=mysql

MYSQLI_USE=	PHP=mysqli

PGSQL_USE=	PHP=pgsql

ORACLE_CONFIGURE_WITH=	oracle

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/frontends/php && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include "${MASTERDIR}/Makefile"
