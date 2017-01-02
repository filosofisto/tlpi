#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <limits.h>
#include "../ErrorSL/tlpi_hdr.h"

#define BUF_LEN (10*(sizeof(struct inotify_event)+NAME_MAX+1))

static void displayInotifyEvent(struct inotify_event *i)
{
    printf("Mask = ");
    if (i->mask & IN_ACCESS) printf("IN_ACCESS");
    if (i->mask & IN_ATTRIB) printf("IN_ATTRIB");
    if (i->mask & IN_CLOSE_NOWRITE) printf("IN_CLOSE_NOWRITE");
    if (i->mask & IN_CLOSE_WRITE) printf("IN_CLOSE_WRITE");
    if (i->mask & IN_CREATE) printf("IN_CREATE");
    if (i->mask & IN_DELETE) printf("IN_DELETE");
    if (i->mask & IN_DELETE_SELF) printf("IN_DELETE_SELF");
    if (i->mask & IN_IGNORED) printf("IN_IGNORED");
    if (i->mask & IN_ISDIR) printf("IN_ISDIR");
    if (i->mask & IN_MODIFY) printf("IN_MODIFY");
    if (i->mask & IN_MOVE_SELF) printf("IN_MOVE_SELF");
    if (i->mask & IN_MOVED_FROM) printf("IN_MOVED_FROM");
    if (i->mask & IN_MOVED_TO) printf("IN_MOVED_TO");
    if (i->mask & IN_OPEN) printf("IN_OPEN");
    if (i->mask & IN_Q_OVERFLOW) printf("IN_Q_OVERFLOW");
    if (i->mask & IN_UNMOUNT) printf("IN_UNMOUNT");
}

int main(int argc, char **argv)
{
    printf("inotify Hello Word\n");

    if (argc < 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s <file to monitor>\n", argv[0]);

    char *file = argv[1];
    //char *file = "/home/eduardo/Private/tlpi/study/inotify/bin/Debug/test";

    int inotifyFd, wd;
    struct inotify_event *event;
    ssize_t numRead;
    char buf[BUF_LEN] __attribute__((aligned(8)));
    char *p;

    inotifyFd = inotify_init();
    if (inotifyFd == -1)
        errExit("inotify_init");
    printf("inotify fd: %d for file: %s\n", inotifyFd, file);

    wd = inotify_add_watch(inotifyFd, file, IN_ALL_EVENTS);
    if (wd == -1)
        errExit("inotify_add_watch");
    printf("Watching %s using wd %d\n", file, wd);

    for (;;) {
        numRead = read(inotifyFd, buf, BUF_LEN);

        if (numRead == 0)
            fatal("read() from inotify fd returned 0!");

        if (numRead == -1)
            errExit("read");

        printf("Read %d bytes\n", (int) numRead);

        for (p = buf; p < buf+numRead;) {
            event = (struct inotify_event *) p;
            displayInotifyEvent(event);

            p += sizeof(struct inotify_event) + event->len;
        }
    }

    return EXIT_SUCCESS;
}
