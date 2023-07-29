#include <iostream>
using namespace std;

int main()
{
    long n;
    cin >> n;
    cin.ignore();
    for (unsigned int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        long sum = 0;
        for (int i = 0; i < str.length(); i++)
        {
            sum += (int)(str[i] - '0');
        }
        cout << sum << endl;
    }
}
