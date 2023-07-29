#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int a, b, c;
    double x1, x2, delta;
    cin >> a >> b >> c;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                cout << "WOW" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << setprecision(2) << fixed << (double)(-c) / (double)b << endl;
    }
    else
    {
        delta = (double)b * (double)b - 4 * (double)a * (double)c;
        if (delta < 0)
            cout << "NO" << endl;
        else if (delta == 0)
            cout << setprecision(2) << fixed << (double)(-b) / (2 * (double)a);
        else
        {
            x1 = ((double)(-b) - sqrt(delta)) / (2 * (double)a);
            x2 = ((double)(-b) + sqrt(delta)) / (2 * (double)a);
            cout << setprecision(2) << fixed << x1 << " ";
            cout << setprecision(2) << fixed << x2 << endl;
        }
    }
}
