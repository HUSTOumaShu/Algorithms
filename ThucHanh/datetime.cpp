#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int getIndex(const vector<string> &date, const string &str)
{
    unsigned int i;
    for (i = 0; i < date.size(); i++)
    {
        int res = str.compare(date[i]);
        if (res == 0)
            break;
    }
    return i;
}

string getTime(string str)
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

string getDate(string str)
{
    string result;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            break;
        result.push_back(str[i]);
    }
    return result;
}

int getSecond(string str)
{
    unsigned int i, j;
    for (i = 0; i < str.length(); i++)
        if (str[i] == ' ')
            break;
    for (j = i + 1; j < str.length(); j++)
        if (str[j] == ' ')
            break;
    int result = 0;
    for (unsigned int k = j + 1; k < str.length(); k++)
    {
        result += (int)(str[k] - '0') * pow(10, str.length() - 1 - k);
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> date;
    vector<string> task;

    string type;
    do
    {
        getline(cin, type);
        if (type == "*")
            continue;
        date.push_back(type);
    } while (type != "*");
    do
    {
        getline(cin, type);
        if (type == "***")
            break;
        task.push_back(type);
    } while (type != "***");

    for (unsigned int i = 0; i < task.size(); i++)
    {
        string day = getDate(task[i]);
        int second = getSecond(task[i]);
        int index = getIndex(date, day);
        int numDay = second / 86400;
        int time = second % 86400;

        cout << date[index + numDay] << " ";
        cout << endl;
    }
}
