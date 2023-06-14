#include <iostream>
#include <string.h>
using namespace std;
#define MAX 21

int n;
int c[MAX][MAX];
int route[MAX];
bool iCheck[MAX];
int cost, result;

void solution()
{
    result = min(result, cost + c[route[n]][route[1]]);
}

bool check(int k, int v)
{
    return !iCheck[v];
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (check(k, v))
        {
            route[k] = v;
            cost += c[route[k - 1]][v];
            iCheck[v] = true;
            if (k == n)
                solution();
            else
            {
                if (cost + c[route[n]][route[1]] < result)
                    Try(k + 1);
            }
            iCheck[v] = false;
            cost -= c[route[k - 1]][v];
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];

    // Initialization
    memset(iCheck, false, n + 1);
    cost = 0;
    result = 1000;
    Try(1);
    cout << result << endl;
}
