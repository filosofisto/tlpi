#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define BUF_SIZE 1024

typedef struct
{
    int result_operation;
    double seconds;
    long bytes_processed;
} stat_io;

/**
  Copy File
 **/
stat_io cp(const char *, const char *);

/**
  File length
 **/
size_t file_length(int);

/**
 Calcula a quantidade de bytes / segundo
 **/
long bytes_per_second(const stat_io);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // IO_H_INCLUDED
