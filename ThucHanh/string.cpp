#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 10000

bool check(vector<string> key, string value)
{
    vector<string>::iterator result;
    result = find(key.begin(), key.end(), value);
    if (result != key.end())
        return true;
    return false;
}

string getWord(string str)
{
    unsigned int i;
    for (i = 0; i < str.length(); i++)
        if (str[i] == ' ')
            break;
    string result;
    for (unsigned int j = i + 1; j < str.length(); j++)
    {
        result.push_back(str[j]);
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> key;
    vector<string> query;

    string type;
    do
    {
        getline(cin, type);
        if (type == "*")
            continue;
        key.push_back(type);
    } while (type != "*");

    do
    {
        getline(cin, type);
        if (type == "***")
            break;
        query.push_back(type);
    } while (type != "***");

    for (unsigned i = 0; i < query.size(); i++)
    {
        if (query[i][0] == 'f')
        {
            if (check(key, getWord(query[i])))
            {
                cout << 1 << endl;
            }
            else
                cout << 0 << endl;
        }
        else
        {
            if (check(key, getWord(query[i])))
            {
                cout << 0 << endl;
            }
            else
            {
                cout << 1 << endl;
                key.push_back(getWord(query[i]));
            }
        }
    }

    return 0;
}
