#include <iostream>
#include <string>

using std::cout; using std::endl; using std::cin;
using std::string;

int main ()
{
    string s1, s2;

    /*cin >> s1 >> s2;

    if (s1 > s2)
    {
        cout << s1 << endl;
    } else if (s1 < s2) {
        cout << s2 << endl;
    }else {
        cout << "wo string is equal" << endl;
    }*/

    while(cin >> s1 >> s2)
        if (s1.size() == s2.size())
            cout << "The two string have the same length." << endl;
        else
            cout << "The large string is " << 
                    ((s1.size() > s2.size()) ? s1 : s2) << endl; 

    return 0;
} 
