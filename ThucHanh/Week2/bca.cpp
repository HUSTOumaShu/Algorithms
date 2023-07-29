#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100

int n, m, maxC;             // n - number of teacher, m - number of course, maxC - number coflicting course
int d[MAX][MAX], c[MAX][2]; // d - list of course teacher could teach, c - conflicting of course
int res[MAX];               // result (res[course] = teacher)

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
            for (int j = 1; j <= maxC; j++)
            {
                if ((c[j][0] == i && c[j][1] == k))
                {
                    return false;
                    break;
                }
            }
        }
    }
    return true;
}

int solution()
{
    if (res[m] == 0)
        return -1;
    int count[n + 1];
    int result = 0;
    memset(count, 0, n + 1);
    for (int i = 1; i <= m; i++)
    {
        count[res[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        result = max(result, count[i]);
    }
    return result;
}

bool check(int k, int v)
{
    if (!checkList(v, k) || !checkConflict(k, v))
        return false;
    return true;
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (check(k, v))
        {
            res[k] = v;
            if (k == m)
                cout << solution() << endl;
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
        cin >> c[i][0] >> c[i][1];
    Try(1);
}
