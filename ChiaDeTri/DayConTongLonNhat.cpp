#include <iostream>
#include <math.h>
using namespace std;

int arr[1000];

int midSeqMax(int i, int j)
{
    int s = 0, max_left = 0, max_right = 0;
    if (i == j)
        return arr[i];
    int mid = (i + j) / 2;
    for (int k = mid; k >= i; k--)
    {
        max_left = max(s, s + arr[k]);
        s = s + arr[k];
    }
    s = 0;
    for (int k = mid + 1; k <= j; k++)
    {
        max_right = max(s, s + arr[k]);
        s = s + arr[k];
    }
    return max_left + max_right;
}

int subSeqMax(int i, int j)
{
    if (i == j)
        return arr[i];
    int mid = (i + j) / 2;
    int leftMAX = subSeqMax(i, mid);
    int rightMAX = subSeqMax(mid + 1, j);
    int midMAX = midSeqMax(i, j);
    return max(max(leftMAX, rightMAX), max(rightMAX, midMAX));
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << subSeqMax(0, n - 1);
}
