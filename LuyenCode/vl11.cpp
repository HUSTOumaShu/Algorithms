#include <iostream>
#include <math.h>
using namespace std;

bool check(long long n)
{
    if (n <= 1)
        return false;
    else if (n <= 3)
        return true;
    else
    {
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;
        return true;
    }
}

int main()
{
    long long n;
    cin >> n;
    if (check(n))
        cout << "YES";
    else
        cout << "NO";
}
