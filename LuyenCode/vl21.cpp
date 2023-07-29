#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long N;
    cin >> N;
    cout << (int)(-1 + sqrt(8 * N + 1)) / 2;
}
