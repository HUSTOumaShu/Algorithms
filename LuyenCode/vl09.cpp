#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int gt(int n)
{
    if (n <= 1)
        return 1;
    int result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

int main()
{
    int n;
    double x;
    cin >> x >> n;
    double result = 0;
    for (int i = 1; i <= n; i++)
        result += (double)(pow(x, (double)i)) / (double)gt(i);
    cout << setprecision(2) << fixed << result << endl;
}
