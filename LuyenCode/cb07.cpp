#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double r;
    const double pi = 3.140;
    cin >> r;
    double p = 2 * pi * r;
    double s = pi * r * r;
    cout << setprecision(3) << fixed << p << " ";
    cout << setprecision(3) << fixed << s << endl;
}
