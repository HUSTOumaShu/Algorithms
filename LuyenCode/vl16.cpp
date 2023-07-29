#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0 || b == 0)
        return a + b;
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    a = abs(a);
    b = abs(b);
    int c = gcd(a, b);
    cout << (a * b) / c << endl;
}
