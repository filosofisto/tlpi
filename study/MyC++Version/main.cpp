#include <iostream>

using namespace std;

int main()
{
    string version = "I don't know";

    switch (__cplusplus) {
        case 1:
            version = "C++ pre-C++98";
            break;
        case 199711L:
            version = "C++98";
            break;
        case 201103L:
            version = "C++11";
            break;
        case 201402L:
            version = "C++14";
            break;
    }

    cout << "My C++ Version is: " << version << endl;

    return 0;
}
