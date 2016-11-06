#include <stdio.h>
#include <stdlib.h>
#include "../ErrorSL/error_functions.h"
#include "../IOSL/io.h"

int main(int argc, char *argv[])
{
    printf("LogBreaker\n");

    if (argc != 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s target-log-file\n", argv[0]);

    printf("Breaking %s...\n", argv[1]);

    int fd = open(argv[1]);
    if (fd == -1)
        errExit("Open source error.");

    char buf[BUF_SIZE];
    int numRead;
    char *last_start = '\0';

    while ((numRead = read(fd, buf, BUF_SIZE)) > 0)

    return EXIT_SUCCESS;
}
