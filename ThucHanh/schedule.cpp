#include <iostream>
using namespace std;
#define MAX 10000

int n, m;
int d[MAX], a[MAX];
int Q[MAX][MAX];

void swap(int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    for (int i = 1; i <= n; i++)
        cin >> d[i];

    for (int i = 1; i <= m; i++)
    {
        cin >> Q[i][0] >> Q[i][1];
        if (Q[i][0] > Q[i][1])
        {
            swap(a[Q[i][0]], a[Q[i][i]]);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}
