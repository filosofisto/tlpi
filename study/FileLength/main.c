#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../ErrorSL/error_functions.h"
#include "../IOSL/io.h"

int main(int argc, char *argv[])
{
    if (argc != 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s file\n", argv[0]);
    char *file = argv[1];
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        errExit(sprintf("Open %s\n", argv[1]));

    size_t bytes = file_length(fd);

    if (bytes < KBYTE)
        printf("File %s has %d bytes.\n", argv[1], bytes);
    else if (bytes < MBYTE)
        printf("File %s has %d Kbytes (%d bytes).\n", argv[1], kbytes(bytes), bytes);
    else if (bytes < GBYTE)
        printf("File %s has %d Mbytes (%d bytes).\n", argv[1], mbytes(bytes), bytes);
    else if (bytes < TBYTE)
        printf("File %s has %d Gbytes (% bytes).\n", argv[1], gbytes(bytes), bytes);
    else
        printf("File %s has %d Tbytes (% bytes).\n", argv[1], tbytes(bytes), bytes);

    return EXIT_SUCCESS;
}
