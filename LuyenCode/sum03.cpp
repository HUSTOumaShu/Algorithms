#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    long n;
    cin >> n;
    double S = 0;
    for (int i = 1; i <= n; i++)
        S += 1 / (double(i) * (double)(i + 1));
    cout << setprecision(5) << fixed << S;
}
