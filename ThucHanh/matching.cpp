#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define MAX 10000

int n, m;
int T[MAX][MAX];
vector<int> task;
int result;

bool check(int k, int v)
{
    if (k == 0)
        return true;
    for (int i = 0; i < k; i++)
    {
        if (task[i] == v)
            return false;
    }
    return true;
}

void Try(int k)
{
    for (int j = 1; j <= T[k][0]; j++)
    {
        int v = T[k][j];
        if (check(k, v))
        {
            task.push_back(v);
            if (k == n)
            {
                result = max(result, (int)task.size());
                cout << result << endl;
            }
            else
                Try(k + 1);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> T[i][0];
        for (int j = 1; j <= T[i][0]; j++)
            cin >> T[i][j];
    }
    result = 0;
    Try(0);
    cout << result << endl;
    for (int i = 0; i < n; i++)
        cout << task[i] << " ";
    return 0;
}
