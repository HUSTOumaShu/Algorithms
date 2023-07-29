#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n <= 1)
        cout << "NO";
    else
    {
        int sum = 0;
        for (int i = 1; i < n; i++)
            if (n % i == 0)
                sum += i;
        if (sum == n)
            cout << "YES";
        else
            cout << "NO";
    }
}
