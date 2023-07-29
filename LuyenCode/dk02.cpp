#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int c1 = (a >= b) ? a : b;
    int c2 = (c1 >= c) ? c1 : c;
    cout << c2 << endl;
}
