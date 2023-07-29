#include <iostream>
#include <math.h>
using namespace std;

bool check(long n)
{
    long tmp = sqrt(n);
    if (tmp * tmp == n)
        return 1;
    return 0;
}

int main()
{
    long n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long result = 0;
        long tmp;
        cin >> tmp;
        for (long i = 1; i <= sqrt(tmp); i++)
            if (tmp % i == 0)
                result += i + tmp / i;
        if (check(tmp))
            result -= sqrt(tmp);
        cout << result << endl;
    }
}
