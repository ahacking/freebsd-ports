# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	helm
PORTVERSION=	2.11.0
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/danilo

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Kubernetes Package Manager

LICENSE=	APACHE20

RUN_DEPENDS=	kubectl:sysutils/kubectl

USES=		go tar:xz

PLIST_FILES=	bin/${PORTNAME} \
		bin/tiller \
		bin/rudder

post-patch:
	${RM} -r ${WRKSRC}/vendor/k8s.io/kubernetes/vendor
	${RM} -r ${WRKSRC}/vendor/k8s.io/apiextensions-apiserver/vendor
	${MV} ${WRKSRC}/vendor/* ${WRKDIR}/src/
	${LN} -s ${WRKSRC} ${WRKDIR}/src/k8s.io/helm

do-build:
.for cmd in helm tiller rudder
	cd ${WRKDIR}/src/k8s.io/helm/cmd/${cmd} ; \
		GOPATH=${WRKDIR} go build \
		-ldflags="-X k8s.io/helm/pkg/version.Version=v${PORTVERSION} \
		-X k8s.io/helm/pkg/version.GitCommit=2e55dbe1fdb5fdb96b75ff144a339489417b146b \
		-X k8s.io/helm/pkg/version.BuildMetadata="
.endfor

do-install:
.for cmd in helm tiller rudder
	${INSTALL_PROGRAM} \
		${WRKSRC}/cmd/${cmd}/${cmd} \
		${STAGEDIR}${PREFIX}/bin/${cmd}
.endfor

maintainer-distfile:
	(cd /tmp; fetch https://github.com/helm/helm/archive/v${PORTVERSION}.tar.gz; \
		tar xzf v${PORTVERSION}.tar.gz; \
		cd helm-${PORTVERSION}; \
		glide install; \
		cd ..; tar cJf helm-${PORTVERSION}.tar.xz helm-${PORTVERSION})

.include <bsd.port.mk>
