#include <iostream>
using namespace std;

int main()
{
    char a, b;
    cin >> a >> b;
    for (char x = a; x <= b; x++)
        cout << (char)toupper(x) << " ";
}
