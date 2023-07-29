#include <iostream>
#include <map>
#include <math.h>
using namespace std;

int n;
int a[100005];
map<int, int> tmp;

int getNum(string str)
{
    int result = 0;
    for (int i = str.length() - 1; i >= 7; i--)
        result += (str[i] - '0') * pow(10, str.length() - 1 - i);
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string type;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        tmp[a[i]]++;
    cin.ignore();
    do
    {
        getline(cin, type);
        if (type == "*")
            break;
        if (type[0] == 'i')
        {
            tmp[getNum(type)]++;
        }
        else
        {
            if (tmp.rbegin()->second > 0)
            {
                tmp.rbegin()->second--;
                cout << tmp.rbegin()->first << endl;
            }
            else
            {
                tmp.erase(tmp.rbegin()->first);
                tmp.rbegin()->second--;
                cout << tmp.rbegin()->first << endl;
            }
        }
    } while (type != "*");
}
