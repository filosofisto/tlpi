/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: eduardo
 *
 * Created on October 29, 2016, 1:02 PM
 */

#include <cstdlib>
#include <iostream>
#include "Test.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    cout << "MsgSLUse++!" << endl;
    cout << "This simple console application show how to use a static library from C++ Program" << endl;

    Test t = Test();
    t.do_something();
    
    return 0;
}

