#include <iostream>

using namespace std;

int main()
{
    char str[10] = {72, 97, 112, 112, 121, 32, 50, 48, 49, 55};

    for (int i = 0; i < sizeof(str); ++i)
        cout << (char) str[i];

    return 0;
}
