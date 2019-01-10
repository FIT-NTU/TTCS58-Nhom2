#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
/*
	Ham tao so ngau nhien
	Input: n - so luong so ngau nhien can tao
		   m - gioi han gia tri cac so ngau nhien se tao
		   a[] - mang se luu gia tri cac so ngau nhien se tao
	Output: Dua cac so ngau nhien vao mang a[] 
*/
void SoNgauNhien (int n, int m, int a[])
{
	int b[m] = {0};
	int i = 1;
	int tam;
	while (i <= n)
	{
		tam = 1 + rand()%m;	
		if (b[tam] == 0)
		{
			b[tam] = 1;
			a[i] = tam;
			i++;
		}
	}
}
int main()
{
	int n, m;
	cout<<"Nhap m: ";
	cin>>m;
	do
	{
		cout<<"Nhap n: ";
		cin>>n;
	}
	while (n >= m);
	int a[n];
	srand(time(0));
	SoNgauNhien(n,m,a);
	for (int i = 1; i <= n; i++)
		cout<<a[i]<<"\t";
}
