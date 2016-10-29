// The functions contained in this file are pretty dummy
// and are included only as a placeholder. Nevertheless,
// they *will* get included in the static library if you
// don't remove them :)
//
// Obviously, you 'll have to write yourself the super-duper
// functions to include in the resulting library...
// Also, it's not necessary to write every function in this file.
// Feel free to add more files in this project. They will be
// included in the resulting library.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "message.h"

#define DEFAULT_TIME_FORMAT "%Y-%m-%d %H:%M:%S"

char *time_format = DEFAULT_TIME_FORMAT;

void set_time_format(const char *new_format)
{
    time_format = new_format;
}

char* format_time()
{
    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);
    strftime(buffer, sizeof(buffer), time_format, tm_info);

    char *target = (char*) malloc(sizeof(buffer));
    strcpy(target, buffer);

    return target;
}

void info(const char *text)
{
    printf("[INFO] %s: %s\n", format_time(), text);
}

void warn(const char *text)
{
    printf("[WARN] %s: %s\n", format_time(), text);
}

void debug(const char *text, const char *file, int line)
{
    printf("[DEBUG] %s: %s [%s, %d]\n", format_time(), text, file, line);
}

void error(const char *text, const char *file, int line)
{
    printf("[ERROR] %s: %s [%s, %d]\n", format_time(), text, file, line);
}

