#include <iostream>
using namespace std;

int main()
{
    long long n;
    long long sum = 0;
    cin >> n;
    for (long long i = 1; i <= n; i++)
        sum += i * i;
    cout << sum;
}
