///
/// ldap_csh.c
/// CSH Specific LDAP Library Implementation
/// Contributor: Justin Sostre
///

#define LDAP_DEPRICATED 1
#include <stdio.h>
#include <ldap.h>

/// authenticates on the ldap server with SSL
LDAP *csh_authenticate(char *hostname, char *bind_on, char *passwd) {

    LDAP *ld;

    if (ldap_initialize(&ld, hostname)) {
        perror("LDAP Initialization");
        return NULL;
    }

    printf("Initialization of LDAP connection was successful.\n");
    
    int rc = ldap_simple_bind_s(ld, bind_on, passwd);

    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "LDAP Simple Bind failed on %d due to %s\n", __LINE__, ldap_err2string(rc));
        return NULL;
    }

    printf("Sucessfully authenticated to LDAP.\n");

    return ld;

}

