#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << ltm->tm_mday << "/" << ltm->tm_mon << "/" << ltm->tm_year << " - ";
    cout << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
    string str;
    getline(cin, str);
    int find = str.find("huy");
    if (find < str.length())
        cout << find;
    else
        cout << 0;
}
