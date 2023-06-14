#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000000

int n;
vector<pair<int, int>> X, S;

bool sortBySec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

bool select(const pair<int, int> &tmp)
{
    if (S.empty())
        return true;
    return (tmp.first >= S[S.size() - 1].second);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        X.push_back(tmp);
    }
    sort(X.begin(), X.end(), sortBySec);
    int count = 0;

    while (!X.empty())
    {
        if (select(X[0]))
        {
            S.push_back(X[0]);
            X.erase(X.begin());
        }
        else
            X.erase(X.begin());
    }
    cout << S.size() << endl;
}
