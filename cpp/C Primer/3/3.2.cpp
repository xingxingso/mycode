#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() 
{
    string line;

    // while(getline(cin, line))    
    while(cin >> line)
        cout << line << endl;


    return 0;
}
