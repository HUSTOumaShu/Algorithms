#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double result = 0.0;
    for (int i = 2; i <= n; i++)
        result += 1 / (double)i;
    cout << setprecision(4) << fixed << result << endl;
}
