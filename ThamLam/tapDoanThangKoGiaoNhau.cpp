#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000
int n;

vector<int> S;
vector<pair<int, int>> work;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> work[i].first >> work[i].second;
    sort(work.begin(), work.end());
    for (int i = 0; i < n; i++)
        cout << work[i].first << " " << work[i].second << endl;
}
