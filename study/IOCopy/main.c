#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ErrorSL/error_functions.h"
#include "../IOSL/io.h"

int main(int argc, char *argv[])
{
    if (argc != 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s source-file target-file\n", argv[0]);

    printf("Copying %s to %s...\n", argv[1], argv[2]);

    stat_io result_copy = cp(argv[1], argv[2]);

    //stat_io result_copy = cp("/home/eduardo/backup.sh", "/home/eduardo/temp/backup.sh");
    //stat_io result_copy = cp("/home/eduardo/Indra/Cartoes/Ambiente/servers_OLD.tar.gz", "/home/eduardo/temp/servers_OLD.tar.gz");

    switch (result_copy.result_operation) {
        case EXIT_SUCCESS:
            printf("%s -> %s copied.\n", argv[1], argv[2]);
            printf("Processed in %f seconds.\n", result_copy.seconds);
            printf("Size: %ld bytes.\n", result_copy.bytes_processed);
            printf("Velocity: %ld bytes per second.\n", bytes_per_second(result_copy));
            break;
        case ERR_COPY_OPEN_SOURCE:
            errExit("Open source error.");
            break;
        case ERR_COPY_OPEN_TARGET:
            errExit("Open target error.");
            break;
        case ERR_COPY_READWRITE:
            errExit("Couldn't write whole buffer");
            break;
        case ERR_COPY_CLOSE_SOURCE:
            errExit("Close source error");
            break;
        case ERR_COPY_CLOSE_TARGET:
            errExit("Close target error");
            break;
        default:
            errExit("Unknown error");
    }

    return EXIT_SUCCESS;
}
