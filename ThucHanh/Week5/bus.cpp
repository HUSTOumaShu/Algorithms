#include <iostream>
#include <vector>
using namespace std;

int n, m;
int c[5001], d[5001];
vector<int> Adj[5001];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> c[i] >> d[i];
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        Adj[from].push_back(to);
        Adj[to].push_back(from);
    }
}
