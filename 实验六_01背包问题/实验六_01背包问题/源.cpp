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
	int w[100], v[100], n, c;        //w������v��ֵ,n��Ʒ������c��������
	cout << "��������Ʒ�����ͱ���������";
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		w[i] = rand() % 9 + 1;
		v[i] = rand() % 9 + 1;
	}
	cout << "����Ʒ�������ͼ�ֵΪ" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "��" << i + 1 << "����Ʒ��(" << w[i] << "," << v[i] << "��" << endl;

	}

	cout << "����������ֵΪ:" << KnapSack(n, w, v) << endl;
	cout << "װ�뱳������Ʒ��:";
	for (int i = 0; i < n; i++)
	{
		if (x[i] == 1)
		{
			cout << "��Ʒ" << i + 1 << " ";
		}
	}
	cout << endl;
	return 0;
}
