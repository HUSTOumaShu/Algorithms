#include <iostream>
using namespace std;
#define MAX 10000

int n, M;
int a[MAX];
int s, count;

bool check(int k, int v)
{
    return true;
}

void Try(int k)
{
    int tmp = 0;
    for (int i = k + 1; i <= n; i++)
    {
        tmp += a[i];
    }
    int x = (M - s - tmp);

    for (int v = 1; v <= x; v++)
    {
        if (check(k, v))
        {
            s += v * a[k];
            if (k == n)
            {
                if (s == M)
                    count++;
            }
            else
                Try(k + 1);
            s -= v * a[k];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    s = 0;
    count = 0;
    cin >> n >> M;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Try(1);
    cout << count << endl;
}
