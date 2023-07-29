/*
Bai toan chuyen bieu thuc thanh cay nhi phan
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Xet do uu tien cua toan tu
int priority(char x)
{
    if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else if (x == '(')
        return 0;
}

// Chuyen bieu thuc trung to s sang dang hau to
vector<string> change_to_postfix(string s)
{
    stack<char> st; // ngan xep toan tu
    vector<string> postfix;

    int i = 0, n = s.size();

    // Xu ly phan tu s[i]
    while (i < n)
    {
        if (s[i] == ' ')
        {
            // do nothing
            i++;
        }

        // Day s[i] vao stack
        else if (s[i] == '(')
        {
            st.push(s[i]);
            i++;
        }

        // Pop stack
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                string temp;
                temp.push_back(st.top());
                postfix.push_back(temp);
                st.pop();
            }
            st.pop();
            i++;
        }

        // Lay toan bo so
        else if (s[i] >= '0' && s[i] <= '9')
        {
            string number;
            while (i < n && s[i] >= '0' && s[i] <= '9')
            {
                number += s[i];
                i++;
            }
            postfix.push_back(number);
        }

        // Xu ly dua tren uu tien
        else
        {
            while (!st.empty() && priority(st.top()) >= priority(s[i]))
            {
                string temp;
                temp.push_back(st.top());
                postfix.push_back(temp);
                st.pop();
            }
            st.push(s[i]);
            i++;
        }
    }

    while (!st.empty())
    {
        string temp;
        temp.push_back(st.top());
        postfix.push_back(temp);
        st.pop();
    }

    return postfix;
}

// Tinh gia tri expression
int get_expression_value(string s)
{
    vector<string> postfix = change_to_postfix(s);
    stack<int> st;

    for (string e : postfix)
    {
        if (e == "+" || e == "-" || e == "*" || e == "/")
        {
            int v1 = st.top();
            st.pop();
            int v2 = st.top();
            st.pop();

            if (e == "+")
                st.push(v1 + v2);
            else if (e == "-")
                st.push(v1 - v2);
            else if (e == "*")
                st.push(v1 * v2);
            else if (e == "/")
                st.push(v1 / v2);
        }
        else
        {
            int number = 0;
            for (int j = 0; j < e.size(); j++)
                number = number * 10 + (e[j] - '0');
            st.push(number);
        }
    }

    return st.top();
}

int main()
{
    string s;
    getline(cin, s);
    vector<string> postfix = change_to_postfix(s);
    for (auto it : postfix)
        cout << it << endl;
    cout << get_expression_value(s);
}
