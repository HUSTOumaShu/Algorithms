#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;
typedef pair<int, int> ii;

int arr[MAX][MAX], check[MAX][MAX], count[MAX][MAX];
int n, m; // size of the maze
int r, c; // position
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<ii> qe;

int solve()
{
    qe.push(ii(r - 1, c - 1));
    check[r - 1][c - 1] = 1;
    count[r - 1][c - 1] = 0;
    while (!qe.empty())
    {
        ii u = qe.front();
        qe.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = dx[i] + u.first;
            int y = dy[i] + u.second;
            if (x < 1 || x > m || y < 1 || y > n)
                return count[u.first][u.second] + 1;
            if (arr[x][y] != 1)
            {
                count[x][y] = count[u.first][u.second] + 1;
                qe.push(ii(x, y));
                arr[x][y] = 1;
            }
        }
    }
    return -1;
}

int main()
{
    int count = 0;
    cin >> n >> m >> r >> c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            check[MAX][MAX] = 0;
        }
    check[r - 1][c - 1] = 1;
    int result = solve();
    cout << result;
}
