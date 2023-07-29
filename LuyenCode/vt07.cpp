#include <iostream>
using namespace std;

int main()
{
    int arr[11];
    int count = 0;
    int x;
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    cin >> x;
    for (int i = 0; i < 10; i++)
        if (arr[i] == x)
        {
            cout << i + 1 << " ";
            count++;
        }
    if (count == 0)
        cout << -1;
    cout << endl;
}
