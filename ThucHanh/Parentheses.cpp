#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

stack<char> Stack;

bool check(const string str)
{
    bool result = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            Stack.push(str[i]);
        }
        else
        {
            if (!(Stack.top() == '(' || Stack.top() == '{' || Stack.top() == '['))
            {
                result = false;
                break;
            }
            else
            {
                if (str[i] == ')' && Stack.top() != '(')
                {
                    result = false;
                    break;
                }
                else if (str[i] == '}' && Stack.top() != '{')
                {
                    result = false;
                    break;
                }
                else if (str[i] == ']' && Stack.top() != '[')
                {
                    result = false;
                    break;
                }
                else
                {
                    Stack.pop();
                }
            }
        }
    }
    if (!Stack.empty())
        result = false;
    return result;
}

int main()
{
    string str;
    getline(cin, str);

    cout << check(str) << endl;
}
