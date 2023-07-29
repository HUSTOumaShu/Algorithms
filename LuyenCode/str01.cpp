#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
        putchar(tolower(str[i]));
}
