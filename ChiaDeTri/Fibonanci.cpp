#include <iostream>
#include <vector>
using namespace std;

vector<long long> fibo;

int main()
{
    fibo.push_back(0);
    fibo.push_back(1);
    for (int i = 2; i <= 50; i++)
    {
        fibo.push_back(fibo[i - 1] + fibo[i - 2]);
    }
    for (int i = 1; i <= 50; i++)
        cout << fibo[i] << " ";
    cout << endl;
}
