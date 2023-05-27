#include <iostream>
#include <string.h>
using namespace std;

int n, L;

void change(string str, int L)
{
    for (int i = 0; i < L - str.length(); i++)
        cout << '0';
    cout << str;
}

int main()
{
    cin >> n >> L;
    cin.ignore();
    string str;
    int i = 0;
    while (i < n)
    {
        getline(cin, str);
        for (int j = 0; j < L - str.length(); j++)
        {
            cout << '0';
        }
        cout << str << endl;
        i++;
    }
}
