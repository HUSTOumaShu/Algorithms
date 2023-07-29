#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int count = 0;
    if (a > b)
        cout << "NOT FOUND";
    else
    {
        for (int i = b; i >= a; i--)
            if (i % 3 == 0)
            {
                count++;
                cout << i << " ";
            }
        if (count == 0)
            cout << "NOT FOUND";
    }
}
