#include <iostream>
using namespace std;
#define MAX 30

int m, n, k;
int p[MAX][MAX], res[MAX];
int c[MAX][2];
bool iCheck[MAX], cCheck[MAX][MAX];

void solution()
{
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

bool find(int x, int *p, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == x)
            return true;
    }
    return false;
}

bool check(int k, int v)
{
    if (!find(v, p[k], p[k][0]))
        return false;
    return true;
}

void Try(int k)
{
    for (int v = 1; v <= m; v++)
    {
        if (check(k, v))
        {
            res[k] = v;
            if (k == n)
                solution();
            else
                Try(k + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin.tie(NULL);

    for (int j = 1; j <= n; j++)
        iCheck[j] = false;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cCheck[i][j] = true;

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        cin >> p[i][0];
        for (int j = 1; j <= p[i][0]; j++)
        {
            cin >> p[i][j];
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> c[i][0] >> c[i][1];
        cCheck[c[i][0]][c[i][1]] = false;
    }

    Try(1);
}
