///
/// ldap_csh.h
/// CSH Specific LDAP Library
/// Contributor: Justin Sostre
///

#ifndef CSH_LDAP_H
#define CSH_LDAP_H

#include <ldap.h>

/// csh_authenticate - authenticates to an ldap server
/// hostname - hostname to the ldap server
/// bind_on - the binding thing url thing whatever
/// passwd - password
LDAP *csh_authenticate(char *hostname, char *bind_on, char *passwd);

#endif
