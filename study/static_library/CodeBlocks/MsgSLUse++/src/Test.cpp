#include <iostream>
#include "Test.h"
#include "message.h"

using namespace std;

Test::Test()
{
    //ctor
}

Test::~Test()
{
    //dtor
}

void Test::do_something()
{
    set_time_format("%Y/%m/%d %H:%M:%S");
    info("Simple Information");
    warn("Alert for something");
    debug("Information message", __FILE__, __LINE__);
    error("Error message", __FILE__, __LINE__);
}
