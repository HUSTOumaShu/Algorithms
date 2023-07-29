#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;
int makespan;
int d[10005], Topo[10005]; // d[i] is duration of task i
int F[10005] = {0};        // F la thoi diem lon nhat ma nhiem vu u co the bat dau
vector<int> Adj[10005];
vector<bool> bMarked(10005, false);
int bVisited[10005];
stack<int> topo;

void DFS(int u)
{
    if (bMarked[u])
        return;
    bMarked[u] = true;
    bVisited[u] = 1;
    for (unsigned int i = 0; i < Adj[u].size(); i++)
    {
        int v = Adj[u][i];
        if (!bVisited[v])
        {
            bVisited[v] = true;
            DFS(v);
        }
    }
    topo.push(u);
}

int countMakeSpan(int u)
{
    if (F[u] != 0)
        return F[u];
    makespan = max(makespan, F[u] + d[u]);
    F[u] = makespan;
    for (int i = 0; i < Adj[u].size(); i++)
    {
        int v = Adj[u][i];
        F[v] = max(F[v], F[u] + d[u]);
    }
    return makespan;
}

int main()
{
    makespan = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        Adj[from].push_back(to);
    }
    for (int i = 1; i <= n; i++)
        if (!bVisited[i])
            DFS(i);
    int cnt = 0;
    while (!topo.empty())
    {
        Topo[topo.top()] = ++cnt;
        topo.pop();
    }
    for (int i = 1; i <= n; i++)
        cout << Topo[i] << " ";
}
