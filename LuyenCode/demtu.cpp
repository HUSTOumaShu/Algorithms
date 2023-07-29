#include <iostream>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    long result = 0, i = 0;
    while (i < str.length())
    {
        if (str[i] != ' ')
        {
            result++;
            int j;
            for (j = i; j < str.length(); j++)
            {
                if (str[j] == ' ')
                    break;
            }
            i = j + 1;
        }
        else
            i++;
    }
    cout << result;
}
