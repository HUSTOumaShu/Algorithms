#include <iostream>
#include <stack>
#include <math.h>
#include <string.h>
using namespace std;

const int MOD = pow(10, 9) + 7;
stack<char> ops;
stack<int> value;

string processExpression(string str, int L, int R)
{
    int l, r;
    int tmp = 0;
    for (int i = L; i <= R; i++)
    {
        if (str[i] == '(')
        {
            tmp = 1;
            break;
        }
    }
    if (tmp == 0) // Epression with none ()
    {
    }
    else // Expression with ()
    {
        for (int i = L; i <= R; i++)
        {
            if(str[i] == '(') {
                ops.push(str[i]);
            }
            else if(str[i] == ')') {
                if(ops.empty()) {
                    cout << "NOT_CORRECT";
                }
                else {
                    ops.pop();
                    
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    getline(cin, str);

    int result = 0;

    for (int i = 0; i < str.length(); i++)
    {
    }
}
