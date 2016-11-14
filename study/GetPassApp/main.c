#include <stdio.h>
#include <stdlib.h>

#include "../GetPassSL/getpass.h"

#define ATTEMPTS 3

int main()
{
    printf("Authenticate!\n");

    int authOk = check_passwd(ATTEMPTS);
    //int authOk = 0;

    if (authOk != 0)
        printf("Success\n");
    else
        printf("Sorry about that\n");

    return 0;
}
