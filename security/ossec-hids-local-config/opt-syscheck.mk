SYSCHECK_MANAGED_CONF=		130.syscheck.conf
SYSCHECK_LOCAL_CONF=		530.syscheck.local.conf

SYSCHECK_DESC=			File Integrity Checking (syscheck)

# Default direcotries
SYSCHECK_BASIC_OPTION=		BASIC_SC
SYSCHECK_BASIC_PROFILE=		basic
SYSCHECK_BASIC_DESC=		"bin", "sbin" and "etc"
SYSCHECK_BASIC_DEFINE=		server local agent pushed
SYSCHECK_BASIC_DEFAULT=		server local pushed
SYSCHECK_OPTIONS+=		SYSCHECK_BASIC

# OSSEC directories
SYSCHECK_OSSEC_OPTION=		OSSEC_SC
SYSCHECK_OSSEC_PROFILE=		ossec
SYSCHECK_OSSEC_DESC=		OSSEC directories
SYSCHECK_OSSEC_DEFINE=		server local agent pushed
SYSCHECK_OSSEC_DEFAULT=		server local pushed
SYSCHECK_OPTIONS+=		SYSCHECK_OSSEC

# Alert new files
SYSCHECK_NEWFILES_OPTION=	NEWFILES_SC
SYSCHECK_NEWFILES_DESC=		Alert on new files created
SYSCHECK_NEWFILES_DEFINE=	server local
SYSCHECK_NEWFILES_DEFAULT=	server local
SYSCHECK_OPTIONS+=		SYSCHECK_NEWFILES

# Disable auto_ignore
SYSCHECK_NOAUTO_OPTION=		NOAUTO_SC
SYSCHECK_NOAUTO_DESC=		Disable auto_ignore feature
SYSCHECK_NOAUTO_DEFINE=		server local
SYSCHECK_NOAUTO_DEFAULT=	server local
SYSCHECK_OPTIONS+=		SYSCHECK_NOAUTO

# Ignore /etc/hosts.allow
SYSCHECK_HOSTDENY_DEPENDS=	AR_HOSTDENY
SYSCHECK_HOSTDENY_OPTION=	HOSTDENY_SC
SYSCHECK_HOSTDENY_DESC=		Ignore access control files
SYSCHECK_HOSTDENY_DEFINE=	server local agent pushed
SYSCHECK_HOSTDENY_DEFAULT=	server local pushed
SYSCHECK_OPTIONS+=		SYSCHECK_HOSTDENY