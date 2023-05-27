#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string str;
    int count = 0;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && str[i + 1] == ' ')
        {
            count++;
        }
    }
    if (str[str.length() - 1] != ' ')
        count++;
    cout << count;
}
