#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100

int n, m, maxC;  // n - number of teacher, m - number of course, maxC - number coflicting course
int d[MAX][MAX]; // d - list of course teacher could teach
int res[MAX];    // result (res[course] = teacher)
bool checkConf[MAX][MAX];

bool checkList(int v, int k)
{
    for (int i = 0; i <= d[v][0]; i++)
    {
        if (d[v][i] == k)
        {
            return true;
            break;
        }
    }
    return false;
}

bool checkConflict(int k, int v)
{
    if (k == 1)
        return true;
    for (int i = 1; i < k; i++)
    {
        if (res[i] == v)
        {
            if (checkConf[i][k])
                return false;
        }
    }
    return true;
}

// int solution()
// {
//     if (res[m] == 0)
//         return -1;
//     int count[n + 1];
//     int result = 0;
//     memset(count, 0, n + 1);
//     for (int i = 1; i <= m; i++)
//     {
//         count[res[i]]++;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         result = max(result, count[i]);
//     }
//     return result;
// }

void solution()
{
    for (int i = 1; i <= m; i++)
        cout << res[i] << " ";
    cout << endl;
}

bool check(int k, int v)
{
    if (!checkList(v, k) || !checkConflict(k, v))
        return false;
    return true;
}

void Try(int k)
{
    cout << k << " ";
    for (int v = 1; v <= 4; v++)
    {
        if (check(k, v))
        {
            res[k] = v;
            if (k == m)
            {
                solution();
            }
            else
                Try(k + 1);
        }
    }
}

int main()
{
    cin >> n >> m;
    memset(res, 0, m + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i][0];
        for (int j = 1; j <= d[i][0]; j++)
            cin >> d[i][j];
    }
    cin >> maxC;
    for (int i = 1; i <= maxC; i++)
    {
        int x, y;
        cin >> x >> y;
        checkConf[x][y] = true;
    }
    Try(1);
}
