#define _BSD_SOURCE /* Get getpass() declaration from <unistd.h> */
//#define _XOPEN_SOURCE /* Get crypt() declaration from <unistd.h> */
#define __USE_XOPEN /* Get crypt() declaration from <unistd.h> */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <pwd.h>
#include <shadow.h>
#include <crypt.h>
#include "../ErrorSL/tlpi_hdr.h"
//#include "../ErrorSL/error_functions.h"

#include "getpass.h"

int check_passwd(int attempts)
{
    char *username, *password, *encrypted, *p;
    struct passwd *pwd;
    struct spwd *spwd;
    size_t len;
    long lnmax;
    int ret = 0;

    if (attempts <= 0)
        errExit("Attemps must be more than ZERO");

    lnmax = sysconf(_SC_LOGIN_NAME_MAX);
    if (lnmax == -1)
        lnmax = 256;

    username = malloc(lnmax);
    if (username == NULL)
        errExit("Memory resources fail");

    printf("Username: ");
    fflush(stdout);
    if (fgets(username, lnmax, stdin) == NULL)
        exit(EXIT_FAILURE);

    len = strlen(username);
    if (username[len-1] == '\n')
        username[len-1] = '\0';

    pwd = getpwnam(username);
    if (pwd == NULL)
        fatal("Couldn't get password record");

    spwd = getspnam(username);
    if (spwd == NULL && errno != 0)
        fatal("No permission to read shadown file");

    if (spwd != NULL)
        pwd->pw_passwd = spwd->sp_pwdp;

    int i;
    for (i = 0; i < attempts && !ret; i++) {
        password = getpass("Password: ");
        encrypted = crypt(password, pwd->pw_passwd);
        for (p = password; *p != 0;)
            *p++ = '\0';

        if (encrypted == NULL)
            errExit("Crypt error");

        ret = (strcmp(encrypted, pwd->pw_passwd) == 0);
    }

    return ret;
}
