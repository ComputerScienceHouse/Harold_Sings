///
/// ldap_csh.h
/// CSH Specific LDAP Library
/// Contributor: Justin Sostre
///

#ifndef CSH_LDAP_H
#define CSH_LDAP_H

#include <ldap.h>

/// authenticates on the ldap server with SSL
LDAP *csh_authenticate(char *hostname, char *bind_on, char *passwd);

#endif
