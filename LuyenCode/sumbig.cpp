#include <iostream>
#include <string.h>
using namespace std;
#define MAX 1000000

struct bigNum
{
    char num[MAX];
    bigNum()
    {
        for (int i = 0; i < MAX; i++)
            num[i] = 0;
    }
};

void input(bigNum &number)
{
    string str;
    cin >> str;
    for (int i = 0; i < (MAX - str.length()); i++)
        number.num[i] = '0';
    for (int i = (MAX - str.length()); i < MAX; i++)
        number.num[i] = str[i - MAX + str.length()];
}

void output(const bigNum number)
{
    int i = 0;
    for (i = 0; i < MAX; i++)
        if (number.num[i] != '0')
            break;
    for (int j = i; j < MAX; j++)
        cout << number.num[j];
    cout << endl;
}

bigNum add_ubigNum_ubigNum(bigNum &a, bigNum &b)
{
    bigNum result;
    int carry = 0; // phan co nho
    for (int i = MAX - 1; i >= 0; i--)
    {
        int tmp = (int)(a.num[i]) - 48 + (int)(b.num[i]) - 48 + carry;
        carry = tmp / 10;
        result.num[i] = (char)(tmp % 10 + 48);
    }
    return result;
}

int main()
{
    bigNum a, b;
    input(a);
    input(b);
    bigNum result = add_ubigNum_ubigNum(a, b);
    output(result);
}
