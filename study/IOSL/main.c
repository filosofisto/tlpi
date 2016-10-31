#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include "../ErrorSL/tlpi_hdr.h"
#include "io.h"

stat_io cp(const char *source_file, const char *target_file)
{
    clock_t begin = clock();

    stat_io result;
    int source_fd, target_fd, open_flags;
    mode_t file_perms;
    ssize_t num_read;
    char buf[BUF_SIZE];

    source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        up_err_stat_io(&result, ERR_COPY_OPEN_SOURCE);

        return result;
    }

    open_flags = O_CREAT | O_WRONLY | O_TRUNC;
    file_perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWGRP | S_IROTH | S_IWOTH;

    target_fd = open(target_file, open_flags, file_perms);
    if (target_fd == -1) {
        up_err_stat_io(&result, ERR_COPY_OPEN_TARGET);

        return result;
    }

    Boolean err_read_write = FALSE;

    while ((num_read = read(source_fd, buf, BUF_SIZE)) > 0) {
        if (write(target_fd, buf, num_read) != num_read) {
            err_read_write = TRUE;
            break;
        }

        result.bytes_processed += num_read;
    }

    if (err_read_write) {
        close(source_fd);
        close(target_fd);

        up_err_stat_io(&result, ERR_COPY_READWRITE);

        return result;
    }

    if (close(source_fd) == -1) {
        up_err_stat_io(&result, ERR_COPY_CLOSE_SOURCE);

        return result;
    }

    if (close(target_fd) == -1) {
        up_err_stat_io(&result, ERR_COPY_CLOSE_TARGET);

        return result;
    }

    result.result_operation = EXIT_SUCCESS;
    clock_t end = clock();
    result.seconds = (double)(end - begin) / CLOCKS_PER_SEC;

    return result;
}

void up_stat_io(stat_io* stat, int result_operation, double seconds, long bytes_processed)
{
    stat->result_operation = result_operation;
    stat->seconds = seconds;
    stat->bytes_processed = bytes_processed;
}

void up_err_stat_io(stat_io* stat, int result_operation)
{
    stat->result_operation = result_operation;
    stat->seconds = 0.0;
    stat->bytes_processed = 0;
}

size_t file_length(int file_descriptor)
{
    off_t current_pos = lseek(file_descriptor, (off_t)0, SEEK_CUR);
    size_t ret = lseek(file_descriptor, (off_t)0, SEEK_END);
    lseek(file_descriptor, current_pos, SEEK_SET);

    return ret;
}

long bytes_per_second(const stat_io stat)
{
    return (long) (stat.bytes_processed / stat.seconds);
}

size_t kbytes(size_t bytes)
{
    return bytes / KBYTE;
}
size_t mbytes(size_t bytes)
{
    return bytes / MBYTE;
}
size_t gbytes(size_t bytes)
{
    return bytes / GBYTE;
}
size_t tbytes(size_t bytes)
{
    return bytes / TBYTE;
}

