#include <iostream>
using namespace std;
#define MAX 1001

int n, m, result;
int a[MAX][MAX], count[MAX][MAX];

int areaMAX(int *a, int n)
{
    int next, prev;
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != 0)
        {
            for (next = i; next <= n; next++)
                if (a[next] < a[i])
                    break;
            for (prev = i; prev >= 1; prev--)
                if (a[prev] < a[i])
                    break;
            result = ((next - prev - 1) * a[i]) > result ? ((next - prev - 1) * a[i]) : result;
        }
    }
    return result;
}

int main()
{
    result = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 0)
                count[i][j] = 0;
            else
            {
                count[i][j] = count[i - 1][j] + 1;
            }
        }
    for (int i = 1; i <= n; i++)
    {
        result = (areaMAX(count[i], m) > result) ? areaMAX(count[i], m) : result;
    }
    cout << result << endl;
}
