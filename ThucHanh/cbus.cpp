#include <iostream>
using namespace std;
#define MAX 25

int n, kx, result;
int c[MAX][MAX];
bool cCheck[MAX];
int route[MAX];
int num;

void solution()
{
    // fixed
    for (int i = 0; i < 2 * n; i++)
        cout << route[i] << " ";
    cout << endl;
}

bool check(int k, int v)
{
    return !cCheck[v];
}

void Try(int k)
{
    for (int v = 0; v <= 2 * n; v++)
    {
        if (check(k, v))
        {
            route[k] = v;
            cCheck[v] = true;
            if (k == 2 * n)
                solution();
            else
                Try(k + 1);
            cCheck[v] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    num = 0;
    cin >> n >> kx;
    for (int i = 0; i <= 2 * n; i++)
    {
        if (i <= n)
            cCheck[i] = true;
        for (int j = 0; j <= 2 * n; j++)
            cin >> c[i][j];
    }
    route[0] = 0;
    Try(1);
}
