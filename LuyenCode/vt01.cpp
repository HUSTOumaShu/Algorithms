#include <iostream>
using namespace std;

int main()
{
    int n;
    int result = -100000000;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        result = max(result, tmp);
    }
    cout << result << endl;
}
