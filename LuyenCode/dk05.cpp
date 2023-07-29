#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long a;
    cin >> a;
    long long b = sqrt(a);
    if (b * b == a)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
