#include <iostream>
using namespace std;
#define MAX 1000

int n, arr[MAX];
bool mark[MAX];

bool check(int k, int v)
{
    return !mark[v];
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (check(k, v))
        {
            arr[k] = v;
            mark[v] = true;
            if (k == n)
                solution();
            else
                Try(k + 1);
            mark[v] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        mark[i] = false;
    }
    Try(1);
}
