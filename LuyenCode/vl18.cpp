#include <iostream>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int i = str.length() - 1;
    while (i >= 0)
    {
        if (str[i] != '0')
            break;
        i--;
    }
    if (i == -1)
        cout << 0;
    else
    {
        for (int k = i; k >= 0; k--)
            cout << str[k];
    }
}
