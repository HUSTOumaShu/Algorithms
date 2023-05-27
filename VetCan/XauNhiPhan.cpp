#include <iostream>
using namespace std;

int n, arr[100];

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

bool check(int k, int i)
{
    return true;
    // if (k == 1)
    //     return true;
    // if (arr[k - 1] == 0 && i == 0)
    //     return false;
    // else
    //     return true;
}

void Try(int k)
{
    for (int i = 0; i <= 1; i++)
    {
        if (check(k, i))
        {
            arr[k] = i;
            if (k == n)
                solution();
            else
                Try(k + 1);
        }
    }
}

int main()
{
    cin >> n;
    Try(1);
}
