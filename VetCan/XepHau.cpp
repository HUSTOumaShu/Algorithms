#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000

int n, res[MAX];
bool row[MAX];
vector<int> mark;

void insert(int k)
{
    bool found = false;
    for (int i = 0; i < mark.size(); i++)
    {
        if (mark[i] == k)
        {
            found = true;
            break;
        }
    }
    if (found == false)
        mark.push_back(k);
}

void initialize()
{
    mark.push_back(MAX);
    for (int i = 1; i < MAX; i++)
    {
        row[i] = false;
    }
}

void solution(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

bool check(int n, int k, int i)
{
    bool result = false;
    if (row[i] == false)
        result = true;
    else
    {
        if (mark.empty())
            result = true;
        else
        {
            for (int i = 0; i < mark.size(); i++)
            {
                if ((k - i) == mark[i])
                {
                    result = false;
                    break;
                }
            }
        }
    }
    return result;
}

void Try(int n, int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (check(n, k, i))
        {
            res[k] = i;
            row[i] = true;
            insert(k - i);
            if (k == n)
                solution(n);
            else
                Try(n, k + 1);
            row[i] = false;
            mark.pop_back();
        }
    }
}

int main()
{
    initialize();
    Try(4, 1);
}
