#include <iostream>
#include <vector>
using namespace std;

vector<int> Adj[1001];
vector<bool> bVisited(1001, false);
vector<bool> bMarked(1001, false);

void DFS(int u)
{
    if (bMarked[u])
        return;
    cout << u << " ";
    bMarked[u] = true;
    bVisited[u] = true;
    for (unsigned int i = 0; i < Adj[u].size(); i++)
    {
        int v = Adj[u][i];
        bVisited[v] = true;
        DFS(v);
    }
}

void input()
{
    Adj[1].push_back(2);
    Adj[1].push_back(3);
    Adj[2].push_back(5);
    Adj[3].push_back(2);
    Adj[3].push_back(4);
    Adj[4].push_back(1);
    Adj[5].push_back(6);
    Adj[6].push_back(3);
    Adj[6].push_back(4);
    Adj[6].push_back(7);
    Adj[6].push_back(8);
    Adj[6].push_back(9);
    Adj[7].push_back(8);
    Adj[7].push_back(9);
    Adj[8].push_back(11);
    Adj[9].push_back(10);
    Adj[10].push_back(9);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    a = 0;
    b = 0;
    cin >> a >> b;
    // input();
    // DFS(1);
    if (a != 0 && b != 0)
        cout << a << b;
}
