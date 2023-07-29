#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string str;
    unsigned int i = 0;
    getline(cin, str);
    if (str[i] == '0' && str.length() == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for (i = 0; i < str.length(); i++)
        if (str[i] != '0' && str[i] != ' ' && str[i] != '-')
            break;
    cout << str.length() - i << endl;
}
