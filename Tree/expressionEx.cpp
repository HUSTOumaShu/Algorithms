#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
using namespace std;

int prority(char x)
{
    if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else if (x == '(')
        return 0;
}

vector<string> change_postfix(string str)
{
    stack<char> st;
    vector<string> postfix;

    int i = 0, n = str.length();
    while (i < n)
    {
        if (str[i] == '(')
        {
            st.push(str[i]);
            i++;
        }
        else if (str[i] == ')')
        {
        }
    }
}

int main()
{
}
