/// harold_log.c
/// Harold Logger Implementation
/// Author: Justin Sostre

#include <stdio.h>
#include <pthread.h>

#include "harold_log.h"

/// I literally have no idea how this is going to work
/// so uhm... don't @ me
static void start_logger(void *args) {

    Logger *logger = (Logger*) args;
}


struct Csh_Logger *initialize_logger(FILE *fp) {
    struct Csh_Logger *logger; // makes a logger
    pthread_t *thread; // makes a pthread
    pthread_create(thread, NULL, start_logger, logger);
    return logger;
}
