#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double a, b;
    char c;
    cin >> a >> c >> b;
    if (c == '+')
        cout << setprecision(2) << fixed << a + b << endl;
    else if (c == '-')
        cout << setprecision(2) << fixed << a - b << endl;
    else if (c == '*')
        cout << setprecision(2) << fixed << a * b << endl;
    else if (c == '/')
    {
        if (b == 0)
            cout << "Math Error";
        else
            cout << setprecision(2) << fixed << a / b << endl;
    }
}
