#include <iostream>
using namespace std;

int arr[9][9];
int result;
bool check_x[9][10], check_y[9][10], check_x_y[3][3][10];

bool check(int v, int x, int y)
{
    return !(check_x[x][v] || check_y[y][v] || check_x_y[x / 3][y / 3][v]);
}

void Try(int x, int y)
{
    if (arr[x][y] == 0)
    {
        for (int v = 1; v <= 9; v++)
        {
            if (check(v, x, y))
            {
                arr[x][y] = v;
                check_x[x][v] = true;
                check_y[y][v] = true;
                check_x_y[x / 3][y / 3][v] = true;
                if (y == 8)
                {
                    if (x == 8)
                        result++;
                    else
                        Try(x + 1, 0);
                }
                else
                    Try(x, y + 1);
                check_x[x][v] = false;
                check_y[y][v] = false;
                check_x_y[x / 3][y / 3][v] = false;
            }
        }
        arr[x][y] = 0;
    }
    else if (y == 8)
    {
        if (x == 8)
            result++;
        else
            Try(x + 1, 0);
    }
    else
        Try(x, y + 1);
}

int main()
{
    result = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int v = 1; v <= 9; v++)
        {
            check_x[i][v] = false;
            check_y[i][v] = false;
        }
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int v = 1; v <= 9; v++)
                check_x_y[i][j][v] = false;

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != 0)
            {
                check_x[i][arr[i][j]] = true;
                check_y[j][arr[i][j]] = true;
                check_x_y[i / 3][j / 3][arr[i][j]] = true;
            }
        }

    Try(0, 0);
    cout << result;
}
