#include <iostream>
#include <string>

using std::cout; using std::endl; using std::cin;
using std::string;

int main()
{
    string big, str;

    while (cin >> str)
        big += str + ' ';

    cout << big << endl;
    return 0;
}
