/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: eduardo
 *
 * Created on October 29, 2016, 12:49 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "message.h"

/*
 * 
 */
int main(int argc, char** argv) 
{
    printf("MsgSLUse!\n");
    printf("This simple console application show how to use a static library\n");

    set_time_format("%Y/%m/%d %H:%M:%S");
    info("Simple Information");
    warn("Alert for something");
    debug("Information message", __FILE__, __LINE__);
    error("Error message", __FILE__, __LINE__);
    
    return (EXIT_SUCCESS);
}

