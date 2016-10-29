/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Test.cpp
 * Author: eduardo
 * 
 * Created on October 29, 2016, 1:03 PM
 */

#include "Test.h"
#include "message.h"

using namespace std;

Test::Test() {
}

Test::Test(const Test& orig) {
}

Test::~Test() {
}

void Test::do_something()
{
    set_time_format("%Y/%m/%d %H:%M:%S");
    info("Simple Information");
    warn("Alert for something");
    debug("Information message", __FILE__, __LINE__);
    error("Error message", __FILE__, __LINE__);
}

