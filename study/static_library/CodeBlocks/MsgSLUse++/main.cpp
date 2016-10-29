#include <iostream>
#include "Test.h"

using namespace std;

int main()
{
    cout << "MsgSLUse++!" << endl;
    cout << "This simple console application show how to use a static library from C++ Program" << endl;

    Test t = Test();
    t.do_something();

    return 0;
}
