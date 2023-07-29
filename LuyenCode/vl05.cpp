#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int result = 0;
    for (int i = 1; i <= 3 * n + 1; i++)
        result += pow(-1, i - 1) * i;
    cout << result << endl;
}
