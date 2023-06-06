#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> S, C;
int n, x;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        C.push_back(tmp);
    }

    sort(C.begin(), C.end(), greater<int>());
    while (x > 0)
    {
        for (int i = 0; i < C.size(); i++)
        {
            if (C[i] < x)
            {
            }
        }
    }
}
