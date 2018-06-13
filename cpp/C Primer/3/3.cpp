#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() 
{
    // 1
    string s10, s11;
    cin >> s10 >> s11;
    cout << s10  << s11 << endl;

    // 2
    string word17;
    // while (cin >> word17) 
    //     cout << word17 <<endl;

    // 3
    string line22;
    while (getline(cin, line22)) {    
        if (!line22.empty())
            cout << line22 << endl;
        if (line22.size() > 10)
            cout << line22 << endl;        
    }

    return 0;
}
