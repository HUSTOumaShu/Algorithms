#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a == 0)
    {
        if (b == 0)
            cout << "WOW" << endl;
        else
            cout << "NO" << endl;
    }
    else
        cout << setprecision(2) << fixed << (float)(-b) / (float)(a) << endl;
}
