#include<iostream>
#include<ctime>
using namespace std;
int C, V[100][100], x[100];
int max(int x, int y)
{
	if (x>y)
		return x;
	else
		return y;
}
int KnapSack(int n, int w[], int v[]) {
	C = n;
	int i, j;
	for (i = 0; i <= n; i++)
	{
		V[i][0] = 0;
	}
	for (j = 0; j <= C; j++)
	{
		V[0][j] = 0;
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= C; j++)
		{
			if (j<w[i - 1]) V[i][j] = V[i - 1][j];
			else V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i - 1]] + v[i - 1]);
		}
	}
	for (j = C, i = n; i>0; i--)
	{
		if (V[i][j]>V[i - 1][j])
		{
			x[i - 1] = 1;
			j = j - w[i - 1];
		}
		else x[i - 1] = 0;
	}
	return V[n][C];
}
int main()
{
	srand((int)time(NULL));
	int w[100], v[100], n, c;        //w重量，v价值,n物品数量，c背包容量
	cout << "请输入物品数量和背包容量：";
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		w[i] = rand() % 9 + 1;
		v[i] = rand() % 9 + 1;
	}
	cout << "各物品的重量和价值为" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "第" << i + 1 << "件物品：(" << w[i] << "," << v[i] << "）" << endl;

	}

	cout << "背包的最大价值为:" << KnapSack(n, w, v) << endl;
	cout << "装入背包的物品是:";
	for (int i = 0; i < n; i++)
	{
		if (x[i] == 1)
		{
			cout << "物品" << i + 1 << " ";
		}
	}
	cout << endl;
	return 0;
}
