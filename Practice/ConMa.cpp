#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
bool a[10][10];
int r, c, n, dem = 0;
vector<ii> q;
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

void show(vector<ii> q)
{
	for (int i = 0; i < q.size(); i++)
		cout << q[i].first << "," << q[i].second << " ";
	cout << endl;
}

void nhap()
{
	q.resize(n * n);
	cin >> n;
	cin >> r >> c;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = false;
		}
	}
	q.push_back(ii(r, c));
}

void Try(int k)
{
	if (k == n * n)
	{
		dem++;
		return;
	}
	ii u = q[k - 1];
	// show(q);
	if (!a[u.first][u.second])
	{
		a[u.first][u.second] = true;
		for (int i = 0; i < 8; i++)
		{
			int x = dx[i] + u.first;
			int y = dy[i] + u.second;
			if (x < 1 || x > n || y < 1 || y > n)
				continue;
			if (!a[x][y])
			{
				q.push_back(ii(x, y));
				Try(k + 1);
				a[x][y] = false;
				q.pop_back();
			}
		}
	}
}
int main()
{
	nhap();
	Try(1);
	cout << dem;
}
