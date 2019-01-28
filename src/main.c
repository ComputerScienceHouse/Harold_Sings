/// main.c
/// Main for Harold
/// Author Justin Sostre


#include <stdlib.h>
#include <stdio.h>
#include <ldap.h>

#include "harold_log.h"
#include "ldap_csh.h"

#define MAX_LINE 100

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./Harold [CredTxt]\n");
        return 1;
    }

    char hostname[MAX_LINE], bind_dn[MAX_LINE], passwd[MAX_LINE];
    FILE *creds = fopen(argv[1], "r");

    if (creds == NULL) {
        perror(argv[1]);
        return -1;
    }

    fscanf(creds, "%s\n%s\n%s", hostname, bind_dn, passwd);
    fclose(creds);

    LDAP *ld = csh_authenticate(hostname, bind_dn, passwd);
    return 0;
}
