#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> Adj[1001];
vector<bool> bMarked(1001, false);
vector<bool> bVisited(1001, false);
void DFS(int u)
{
    if (bMarked[u])
        return;
    bMarked[u] = true;
    bVisited[u] = true;
    for (unsigned int i = 0; i < Adj[u].size(); i++)
    {
        if (Adj[u][i] != 0)
        {
            int v = Adj[u][i];
            bVisited[v] = true;
            DFS(v);
        }
    }
}

int countConnectedComponent()
{
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!bVisited[i])
        {
            DFS(i);
            count++;
        }
    }
    return count;
}

void initialize()
{
    for (int i = 1; i <= N; i++)
    {
        bMarked[i] = false;
        bVisited[i] = false;
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        Adj[from].push_back(to);
        Adj[to].push_back(from);
    }

    int num = countConnectedComponent();
    int result = 0;
    for (int i = 1; i <= N; i++)
    {
        initialize();
        bVisited[i] = true;
        vector<int> tmp;
        for (int j = 0; j < Adj[i].size(); j++)
            tmp.push_back(Adj[i][j]);
        Adj[i].clear();
        int newNum = countConnectedComponent();
        if (newNum > num)
            result++;

        bVisited[i] = false;
        for (int j = 0; j < tmp.size(); j++)
            Adj[i].push_back(tmp[j]);
    }
    cout << result << endl;

    // Bridges
    result = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < Adj[N].size(); j++)
        {
            initialize();
            int tmp = Adj[i][j];
            int k;
            Adj[i][j] = 0;
            for (k = 0; k < Adj[tmp].size(); k++)
                if (Adj[tmp][k] == i)
                {
                    Adj[tmp][k] = 0;
                    break;
                }
            int newNum = countConnectedComponent();
            if (newNum > num)
                result++;
            Adj[i][j] = tmp;
            Adj[tmp][k] = i;
        }
    }
    cout << result;
}
