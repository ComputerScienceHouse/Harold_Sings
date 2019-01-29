/// main.c
/// Main for Harold
/// Author Justin Sostre


#include <stdlib.h>
#include <stdio.h>
#include <ldap.h>
#include <sys/mman.h>
#include <wiringPi.h>

#include "harold.h"
#include "harold_log.h"
#include "ldap_csh.h"

#define MAX_LINE 100

void start_harold(Harold *harold, LDAP *ld, Logger *log) {

    harold->current_song = NULL;
    harold->vol = 50;
    
    // start listening for music and shit
    //
    return;

}


/// main - start of the program
/// argc - the number of arguments
/// argv - arguments given to the program
int main(int argc, char *argv[]) {

    if (argc != 2) {  // Only two arguments
        fprintf(stderr, "Usage: ./Harold [CredTxt]\n");
        return 1;
    }

    if (wiringPiSetup() == -1) {
        fprintf(stderr, "Setting up WiringPi failed.\n");
        return 2;
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

    Harold *harold;
    start_harold(harold, ld, NULL);
    return 0;
}
