///
/// Harold_Log.h
/// Log Interface for Harold
/// Contributor: Justin Sostre
///

#ifndef HAROLD_LOG_H
#define HAROLD_LOG_H

#include <stdio.h>

/// Csh_Logger - Controls how to log the file with states and the file to output to
typedef struct Csh_Logger {
    FILE *file;
    int state;
} Logger; 


/// initialize_logger - initializes a logger to write to the log files
/// file - the file to start writing to
struct Csh_Logger *initialize_logger(FILE *file);

#endif
