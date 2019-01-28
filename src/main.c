/// main.c
/// Main for Harold
/// Author Justin Sostre


#include <stdlib.h>
#include <stdio.h>
#include <ldap.h>

#include "harold_log.h"
#include "ldap_csh.h"

#define MAX_LINE 100

/// main - start of the program
/// argc - the number of arguments
/// argv - arguments given to the program
int main(int argc, char *argv[]) {
    if (argc != 2) {  // Only two arguments
        fprintf(stderr, "Usage: ./Harold [CredTxt]\n");
        return 1;
    }

    // declare the important ldap things
    char hostname[MAX_LINE], bind_dn[MAX_LINE], passwd[MAX_LINE]; 

    // get creds from the file... because posting secrets is against
    // RTP policy or something...? @jacksauriol
    FILE *creds = fopen(argv[1], "r");

    if (creds == NULL) {
        perror(argv[1]);
        return -1;
    }

    // get the creds
    fscanf(creds, "%s\n%s\n%s", hostname, bind_dn, passwd);
    fclose(creds);

    // authenticate to the CSH LDAP
    LDAP *ld = csh_authenticate(hostname, bind_dn, passwd);

    // setting up harold
    return 0;
}
