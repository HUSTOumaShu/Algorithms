#include <iostream>
#include <math.h>
const unsigned long long mod = pow(10, 9) + 7;
using namespace std;

int main()
{
    unsigned long long a, b;
    cin >> a >> b;
    unsigned long long a0 = a % mod;
    unsigned long long b0 = b % mod;
    cout << (a0 + b0) % mod;
}
