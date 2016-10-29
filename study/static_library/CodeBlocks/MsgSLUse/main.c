#include <stdio.h>
#include <stdlib.h>

#include "message.h"

int main()
{
    printf("MsgSLUse!\n");
    printf("This simple console application show how to use a static library\n");

    set_time_format("%Y/%m/%d %H:%M:%S");
    info("Simple Information");
    warn("Alert for something");
    debug("Information message", __FILE__, __LINE__);
    error("Error message", __FILE__, __LINE__);

    return 0;
}
