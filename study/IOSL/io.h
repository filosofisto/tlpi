#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define BUF_SIZE 1024
#define ERR_COPY_OPEN_SOURCE -1
#define ERR_COPY_OPEN_TARGET -2
#define ERR_COPY_READWRITE -3
#define ERR_COPY_CLOSE_SOURCE -4
#define ERR_COPY_CLOSE_TARGET -5

#define KBYTE 1024
#define MBYTE (1024*1024)
#define GBYTE (1024*1024*1024)
#define TBYTE (1024*1024*1024*1024)

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

size_t kbytes(size_t);
size_t mbytes(size_t);
size_t gbytes(size_t);
size_t tbytes(size_t);

/**
 Calcula a quantidade de bytes / segundo
 **/
long bytes_per_second(const stat_io);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // IO_H_INCLUDED
