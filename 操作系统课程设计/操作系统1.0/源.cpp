#include<iostream>
#include<ctime>
using namespace std;
int a[20], b[20], c[20], A[3], B[3], C[3], d[20] = { 0 };
float n;
void menu()
{
	system("cls");
	cout << "============���˵�============" << endl;
	cout << "*1.ˢ�µ�ǰ�������к�        *" << endl;
	cout << "*2.FIFO�û��㷨              *" << endl;
	cout << "*3.LRU�û��㷨               *" << endl;
	cout << "*0.�˳�                      *" << endl;
	cout << "==============================" << endl;
	cout << "��ǰ�������к�Ϊ��" << endl;
	cout << " |---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---|" << endl;
	cout << " |";
	for (int i = 0; i < 16; i++)
	{
		cout << " " << d[i] << " |";
	}
	cout << endl;
	cout << " |---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---|" << endl;

}
void random()
{
	srand((int)time(0));  // �����������
	d[0] = 1;
	d[1] = 2;
	d[2] = 3;
	for (int i = 3; i < 16; i++)
	{
		d[i] = rand() % 7 + 1;
	}
}
void show()
{
	cout << " |---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---|" << endl;
	cout << " |";
	for (int i = 0; i < 16; i++)
	{
		cout << " " << d[i] << " |";
	}
	cout << endl;
	cout << " |---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---|" << endl;
	cout << " |";
	for (int i = 0; i < 16; i++)
	{
		if (a[i] == 0) { cout << "   |"; }
		else cout << " " << a[i] << " |";
	}
	cout << endl;
	cout << " |";
	for (int i = 0; i < 16; i++)
	{
		if (b[i] == 0) { cout << "   |"; }
		else cout << " " << b[i] << " |";
	}
	cout << endl;
	cout << " |";
	for (int i = 0; i < 16; i++)
	{
		if (c[i] == 0) { cout << "   |"; }
		else cout << " " << c[i] << " |";
	}
	cout << endl;
	cout << " |---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---|" << endl;
	cout << "ȱҳ����Ϊ��" << n << endl;
	cout << "ȱҳ�ʣ�" << n / 16 << endl;
	system("pause");
}
void FIFO()
{
	a[0] = a[1] = a[2] = d[0];
	b[1] = b[2] = d[1];
	c[2] = d[2];
	A[0] = A[1] = A[2] = d[0];
	B[1] = B[2] = d[1];
	C[2] = d[2];
	n = 3;
	for (int i = 3; i < 16; i++)
	{
		if (d[i] == A[2] || d[i] == B[2] || d[i] == C[2])
		{
			a[i] = b[i] = c[i] = 0;
		}
		else
		{
			n++;
			if (A[0] == A[1] && A[1] == A[2])
			{
				a[i] = d[i];
				b[i] = B[2];
				c[i] = C[2];
				A[2] = d[i]; B[0] = B[1]; C[1] = C[2];
			}
			else if (B[0] == B[1] && B[1] == B[2])
			{
				a[i] = A[2];
				b[i] = d[i];
				c[i] = C[2];
				A[1] = A[2]; B[2] = d[i]; C[0] = C[1];
			}
			else if (C[0] == C[1] && C[1] == C[2])
			{
				a[i] = A[2];
				b[i] = B[2];
				c[i] = d[i];
				A[0] = A[1]; B[1] = B[2]; C[2] = d[i];
			}
		}
	}
	system("cls");
	cout << "LRU�û��㷨" << endl;
	show();

}
void LRU()
{

	a[0] = a[1] = a[2] = d[0];
	b[1] = b[2] = d[1];
	c[2] = d[2];
	A[0] = B[0] = d[0];
	A[1] = B[1] = d[1];
	A[2] = B[2] = d[2];
	n = 3;
	for (int i = 3; i < 16; i++)
	{
		if (d[i] == A[0])
		{
			A[0] = A[1]; A[1] = A[2]; A[2] = d[i];
		}
		else if (d[i] == A[1])
		{
			A[1] = A[2]; A[2] = d[i];
		}
		else if (d[i] == A[2])
		{
			A[2] = d[i];
		}
		else
		{
			n++;
			if (A[0] == B[0]) { a[i] = d[i]; b[i] = B[1]; c[i] = B[2]; }
			else if (A[0] == B[1] ){ a[i] = B[0]; b[i] = d[i]; c[i] = B[2]; }
			else if (A[0] == B[2]) { a[i] = B[0]; b[i] = B[1]; c[i] = d[i]; }
			A[0] = A[1]; A[1] = A[2]; A[2] = d[i];
			B[0] = a[i]; B[1] = b[i]; B[2] = c[i];
		}
	}
	system("cls");
	cout << "LRU�û��㷨" << endl;
	show();
}
void caozuo()
{
	char m;
	while (1)
	{
		menu();
		cin >> m;
		if (m == '1')
		{
			random();
		}
		else if (m == '2')
		{
			FIFO();
		}
		else if (m == '3')
		{
			LRU();
		}
		else if (m == '0')
		{
			system("cls");
			cout << "�˳��ɹ�������" << endl;
			break;
		}
		else
		{
			cout << "�����������������룡����" << endl;
			system("pause");
		}
	}
}
void main()
{
	caozuo();
}