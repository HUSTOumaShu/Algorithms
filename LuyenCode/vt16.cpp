#include <iostream>
using namespace std;

int main()
{
    int tmp;
    int count = 0;
    do
    {
        cin >> tmp;
        if (tmp == 0)
            break;
        if (tmp < 0)
        {
            cout << tmp << " ";
            count++;
        }
    } while (tmp != 0);
    if (count == 0)
        cout << "NOT FOUND";
}
