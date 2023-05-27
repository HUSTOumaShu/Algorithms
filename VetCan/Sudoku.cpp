#include <iostream>
using namespace std;

int arr[10][10];
bool check_x[10][10], check_y[10][10], check_x_y[4][4][10];
int result = 0;

bool check(int x, int y, int v)
{
    return (!check_x[x][v]) && (!check_y[y][v]) && (!check_x_y[(x + 2) / 3][(y + 2) / 3][v]);
}

void Try(int x, int y)
{
    for (int v = 1; v <= 9; v++)
    {
        if (arr[x][y] == 0 && check(x, y, v))
        {
            arr[x][y] = v;
            check_x[x][v] = true;
            check_y[y][v] = true;
            check_x_y[(x + 2) / 3][(y + 2) / 3][v] = true;
            if (y == 8)
            {
                if (x == 8)
                    result++;
                Try(x + 1, y);
            }
            Try(x, y + 1);
            arr[x][y] = 0;
            check_x[x][v] = false;
            check_y[y][v] = false;
            check_x_y[(x + 2) / 3][(y + 2) / 3][v] = false;
        }
    }
}

int main()
{
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != 0)
            {
                check_x[i][(arr[i][j])] = true;
                check_y[j][(arr[i][j])] = true;
                check_x_y[(i + 2) / 3][(j + 2) / 3][(arr[i][j])] = true;
            }
            else
            {
                check_x[i][(arr[i][j])] = false;
                check_y[j][(arr[i][j])] = false;
                check_x_y[(i + 2) / 3][(j + 2) / 3][(arr[i][j])] = false;
            }
        }
    Try(1, 1);
    cout << result << endl;
}
