#include <iostream>
using namespace std;

bool checkYear(int year)
{
    if (year % 400 == 0)
        return true;
    else if (year % 4 == 0 && year % 100 != 0)
        return true;
    else
        return false;
}

int main()
{
    int month, year;
    cin >> month >> year;
    if (month >= 1 && month <= 12 && year > 0 && year <= 100000)
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            cout << 31 << endl;
        else if (month == 2)
        {
            if (checkYear(year))
                cout << 29 << endl;
            else
                cout << 28 << endl;
        }
        else
            cout << 30 << endl;
    }
    else
        cout << "INVALID" << endl;
}
