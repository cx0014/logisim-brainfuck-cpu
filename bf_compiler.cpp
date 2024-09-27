#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("source.bf");
    if(!file.is_open())
    {
        cout << "Cannot open file source.b" << endl;
        return -1;
    }
    
    char c;
    string conversion[256] = {""};
    conversion['>'] = "1 f ";
    conversion['<'] = "2 f ";
    conversion['+'] = "3 f ";
    conversion['-'] = "4 f ";
    conversion['.'] = "5 f ";
    conversion[','] = "6 f ";
    conversion['['] = "7 f ";
    conversion[']'] = "8 f ";
    
    cout << "f f ";
    while (file.get(c)) cout << conversion[(int)c];
    cout << endl;
    
    file.close();
}