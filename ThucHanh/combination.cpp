#include <iostream>
using namespace std;
#define MAX 10000

int x, n;
bool iCheck[MAX];
int arr[MAX];

void solution()
{
    for (int i = 1; i <= x; i++)
        cout << arr[i] << " ";
    cout << endl;
}

bool check(int k, int v)
{
    if (k == 1)
        return !iCheck[v];
    return (!iCheck[v]) && (arr[k - 1] < v);
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (check(k, v))
        {
            arr[k] = v;
            iCheck[v] = true;
            if (k == x)
                solution();
            else
                Try(k + 1);
            iCheck[v] = false;
        }
    }
}

int main()
{
    cin >> x >> n;
    for (int i = 0; i <= n; i++)
        iCheck[i] = false;
    Try(1);
}
