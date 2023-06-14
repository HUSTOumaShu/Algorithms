#include <iostream>
#include <string.h>
using namespace std;
#define MAX 1000

int n, count, cost, result;
int c[MAX][MAX];
int route[MAX];
bool iCheck[MAX], user[MAX];

bool check(int k, int v)
{
    if (iCheck[v] || (count < 0))
        return false;
    return true;
}

void solution()
{
    result = min(result, cost + (c[route[2 * n]][0]));
}

void Try(int k)
{
    for (int v = 0; v <= 2 * n; v++)
    {
        if (check(k, v))
        {
            route[k] = v;
            iCheck[v] = true;
            cost += c[route[k - 1]][v];
            if (v <= n)
            {
                count++;
                user[v] = false;
            }
            else
            {
                if (user[v - n] == false)
                    count--;
            }
            if (k == 2 * n && count == 0)
            {
                solution();
            }
            else
            {
                if (cost < result)
                    Try(k + 1);
            }
            iCheck[v] = false;
            cost -= c[route[k - 1]][v];
            if (v <= n)
            {
                count--;
                user[v] = true;
            }
            else
            {
                if (user[v - n] == false)
                    count++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    result = 10000;
    cin >> n;
    for (int i = 0; i <= 2 * n; i++)
        for (int j = 0; j <= 2 * n; j++)
            cin >> c[i][j];
    memset(user, true, n + 1);
    memset(iCheck, false, 2 * n + 1);
    iCheck[0] = true;
    user[0] = false;
    count = 0;
    cost = 0;
    Try(1);
    cout << result;
}
