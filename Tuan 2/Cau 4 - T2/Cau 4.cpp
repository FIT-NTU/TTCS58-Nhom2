#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
ifstream f("input4.txt");
ofstream g("output4.txt");
int sum;
//Nhap du lieu tu file
void Nhap (int lop[100], int phong[100], int &k, int &n)
{
	f>>n;
	for (int i = 0; i < n; i++)
		f>>phong[i];
	f>>k;
	for (int i = 0; i < k; i++)
		f>>lop[i];
}
//Tim so lan chuyen ghe vao/ra ung voi 1 cach bo tri
int Demghe (int lop[100], int phong[100], int k, int n, int c[100])
{
	int a = 0;
	int ghetrong = 0, ghedu = 0;
	int sumghe = 0;
	for (int i = 0; i < n; i++)
		if (c[i] == 1)
		{
			if (phong[i] >= lop[a])
			{
				sumghe += phong[i] - lop[a];
				ghedu += phong[i] - lop[a];
			}				
			a++;
		}
	a = 0;
	for (int i = 0; i < n; i++)
		if (c[i] == 0)
			ghetrong += phong[i];
	for (int i = 0; i < n; i++)
		if (c[i] == 1)
		{
			if (phong[i] < lop[a])
			{
				if (phong[i] + ghedu >= lop[a])
				{
					sumghe += lop[a] - phong[i];
					ghedu -= lop[a] - phong[i];
				}
				else
				{
					ghetrong -= lop[a] - phong[i] - ghedu;
					sumghe += ghedu + 2*(lop[a] - phong[i] - ghedu);
					ghedu = 0;
				}
			}
			a++;
		}
	return sumghe;		
}
//So lan chuyen ghe vao/ra it nhat
void Minghe (int lop[100], int phong[100], int k, int n, int c[100], int i)
{
	for (int j = 0; j <= 1; j++)
	{
		c[i] = j;
		if (i == n - 1)
		{
			int count = 0;
			for (int p = 0; p < n; p++)
				if (c[p] == 1)
					count++;
			if (count == k && Demghe(lop,phong,k,n,c) < sum)
				sum = Demghe(lop,phong,k,n,c);
		}
		else
			Minghe(lop,phong,k,n,c,i+1);
	}
}
//Liet ke cac cach bo tri de so lan chuyen ghe vao/ra it nhat
void Lietke (int lop[100], int phong[100], int k, int n, int c[100], int i)
{
	for (int j = 0; j <= 1; j++)
	{
		c[i] = j;
		if (i == n - 1)
		{
			int count = 0;
			for (int p = 0; p < n; p++)
				if (c[p] == 1)
					count++;
			if (count == k && Demghe(lop,phong,k,n,c) == sum)
			{
				int a = 1;
				for (int p = 0; p < n; p++)
					if (c[p] == 1)
					{
						g<<"P"<<p+1<<"-L"<<a<<"\t";
						a++;
					}						
					else
						g<<"P"<<p+1<<"\t";
				g<<endl<<endl;
			}
		}
		else
			Lietke(lop,phong,k,n,c,i+1);
	}
}
int main()
{
	int n, k;						//n = so luong phong, k = so luong lop
	int lop[100];
	int phong[100];
	int c[100];						//Mang luu tru cach bo tri
	Nhap(lop,phong,k,n);
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++)		//Tong so ghe
		sum1 += phong[i];
	for (int i = 0; i < k; i++)		//Tong so sinh vien
		sum2 += lop[i];
	if (sum1 >= sum2 && n >= k)		//Tong so phong phai dap ung du so lop va tong so ghe phai dap ung du so sinh vien
	{
		sum = sum1;
		Minghe(lop,phong,k,n,c,0);
		g<<"Tong so lan chuyen ghe vao/ra it nhat: "<<sum<<endl<<endl;
		g<<"Cac cach bo tri: "<<endl;
		Lietke(lop,phong,k,n,c,0);		
	}
	else
		if (n < k)
			cout<<"Khong du phong cho cac lop hoc";
		else
			cout<<"Khong du ghe cho tat ca sinh vien";
}
