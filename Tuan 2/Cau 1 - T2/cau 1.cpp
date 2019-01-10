#include "tvcau1.h"
void Nhap (int a[100][100], int &n, int &m)
{
	cout<<"Nhap so dong va cot: ";
	cin>>n;
	m = n;
	srand(time(0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = rand()%101;
}
void Xuat (int a[100][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout<<a[i][j]<<"  ";
		cout<<endl;
	}
}
void Xoadong (int a[100][100], int &n, int m)
{
	int i;
	do
	{
		cout<<"Nhap dong can xoa: ";
		cin>>i;
	}
	while (i < 0 || i >= n);	
	for (int k = i; k < n - 1; k++)
		for (int j = 0; j < n; j++)
			a[k][j] = a[k+1][j];
	n--;
}
void Xoacot (int a[100][100], int n, int &m)
{
	int j;
	do
	{
		cout<<"Nhap cot can xoa: ";
		cin>>j;
	}
	while (j < 0 || j >= m);	
	for (int i = 0; i < n; i++)
		for (int k = j; k < m - 1; k++)
			a[i][k] = a[i][k+1];
	m--;
}
int Doixung (int a[100][100], int n, int m)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i][j] != a[j][i])
				return 0;
	return 1;
}
int SoHoangHau (int a[100][100], int n, int m, int vtd, int vtc)
{
	int x = a[vtd][vtc];
	//Kiem tra lon nhat tren cot
	for (int i = 0; i < n; i++)
		if (a[i][vtc] > x)
			return 0;
	//Kiem tra lon nhat tren hang
	for (int j = 0; j < n; j++)
		if (a[vtd][j] > x)
			return 0;
	//Kiem tra lon nhat tren duong cheo chinh
	int vtd1 = vtd + 1;
	int vtc1 = vtc + 1;
	while (vtd1 < n && vtc1 < m)
	{
		if (a[vtd1][vtc1] > x)
			return 0;
		vtd1++;
		vtc1++;
	}
	vtd1 = vtd - 1;
	vtc1 = vtc - 1;
	while (vtd1 >= 0  && vtc1 >= 0)
	{
		if (a[vtd1][vtc1] > x)
			return 0;
		vtd1--;
		vtc1--;
	}
	//Kiem tra lon nhat tren duong cheo phu
	vtd1 = vtd + 1;
	vtc1 = vtc - 1;
	while (vtd1 < n  && vtc1 >= 0)
	{
		if (a[vtd1][vtc1] > x)
			return 0;
		vtd1++;
		vtc1--;
	}
	vtd1 = vtd - 1;
	vtc1 = vtc + 1;
	while (vtd1 >= 0  && vtc1 < m)
	{
		if (a[vtd1][vtc1] > x)
			return 0;
		vtd1--;
		vtc1++;
	}
	return 1;
}
void DSSoHoangHau (int a[100][100], int n, int m)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (SoHoangHau(a,n,m,i,j) == 1)
			{
				f<<a[i][j]<<" (hang "<<i<<" / cot "<<j<<")\t";
				count++;
			}
	f<<endl<<"So luong cac so hoang hau trong ma tran: "<<count<<endl;
}
