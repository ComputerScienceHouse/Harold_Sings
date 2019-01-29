/// harold.h
/// Harold Functions Interface
/// Author Justin Sostre

#ifndef HAROLD_H
#define HAROLD_H

#include <ldap.h>

#include "harold_log.h"

typedef struct Harold_S {
    char *current_song;
    int vol;
} Harold;


void start_harold(Harold *harold, LDAP *ld, Logger *logger);

#endif
