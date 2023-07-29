#include <iostream>
#include <vector>
using namespace std;

// 1. Danh sach ke
vector<int> Adj_list[5];
// 2. Ma tran ke
bool Adj[5][5];

// Bac cua 1 dinh
int Deg(int v)
{
    return Adj_list[v].size();
}

int main()
{
    /*
    Bieu dien do thi
    */
    Adj_list[1].push_back(2);
    Adj_list[1].push_back(3);
    Adj_list[2].push_back(1);
    Adj_list[2].push_back(3);
    Adj_list[3].push_back(1);
    Adj_list[3].push_back(2);
    Adj_list[3].push_back(4);
    Adj_list[4].push_back(3);

    Adj[1][2] = true;
    Adj[1][3] = true;
    Adj[2][1] = true;
    Adj[2][3] = true;
    Adj[3][1] = true;
    Adj[3][2] = true;
    Adj[3][4] = true;
    Adj[4][3] = true;

    // 3. Danh sach canh
    vector<pair<int, int>> Edges;
    Edges.push_back(make_pair(1, 2));
    Edges.push_back(make_pair(1, 3));
    Edges.push_back(make_pair(2, 3));
    Edges.push_back(make_pair(3, 4));
}
