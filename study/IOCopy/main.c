#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ErrorSL/error_functions.h"
#include "../IOSL/io.h"

int main(int argc, char *argv[])
{
    if (argc != 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s source-file target-file\n", argv[0]);

    printf("Copying %s to %s\n", argv[1], argv[2]);

    stat_io result_copy = cp(argv[1], argv[2]);

    //stat_io result_copy = cp("/home/eduardo/backup.sh", "/home/eduardo/temp/backup.sh");

    switch (result_copy.result_operation) {
        case 0:
            printf("%s -> %s copied.\n", argv[1], argv[2]);
            printf("Processed in %3.0f seconds.\n", (int)result_copy.seconds);
            printf("%s size: %ld bytes.\n", argv[1], result_copy.bytes_processed);
            printf("Stat: %ld bytes per second.\n", bytes_per_second(result_copy));
            break;
        case -1:
            errExit("Open source error.");
            break;
        case -2:
            errExit("Open target error.");
            break;
        case -3:
            errExit("Couldn't write whole buffer");
            break;
        case -4:
            errExit("Close source error");
            break;
        case -5:
            errExit("Close target error");
            break;
        default:
            errExit("Unknown error");
    }

    return EXIT_SUCCESS;
}
