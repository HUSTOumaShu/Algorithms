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
    if (b == 0)
        cout << "INVALID" << endl;
    else
    {
        if (a * b > 0)
        {
            a = abs(a);
            b = abs(b);
            int c = gcd(a, b);
            a = a / c;
            b = b / c;
            if (b == 1)
                cout << a << endl;
            else
                cout << a << " " << b << endl;
        }
        else if (a * b < 0)
        {
            a = abs(a);
            b = abs(b);
            int c = gcd(a, b);
            a = a / c;
            b = b / c;
            if (b == 1)
                cout << -a << endl;
            else
                cout << -a << " " << b << endl;
        }
        else
            cout << 0 << endl;
    }
}
