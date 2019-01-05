#include "pch.h"
#include <iostream>
#include<conio.h>
#include<math.h>
#include<fstream>
#define MAX 29
using namespace std;
//dữ liệu lưu các quân cờ có hai phần trên và dưới
struct Co {
	int tren;
	int duoi;
};
Co a[29];//mảng lưu trữ thông tin các quân cờ
int ttluu[29], tt[29], cl = 168;
int n;//số quân cờ cần xử lý
void NhapCo(int &n) {
	cout << "Nhap so quan co: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Quan co thu: " << i << endl;
		cout << "Mat tren: ";
		do {
			cin >> a[i].tren;
		} while (a[i].tren <= 0 || a[i].tren > 6);
		cout << "Mat duoi: ";
		do {
			cin >> a[i].duoi;
		} while (a[i].duoi <= 0 || a[i].duoi > 6);
	}
	for (int i = 1; i <= n; i++)
		cout << a[i].tren << "   " << a[i].duoi << "   " << endl;
}

void KiemTra() {
	int tren = 0, duoi = 0, dochenh;
	for (int i = 1; i <= n; i++)
	{
		if (tt[i] == 0)
		{
			tren += a[i].tren;
			duoi += a[i].duoi;
		}
		else
		{
			tren += a[i].duoi;
			duoi += a[i].tren;
		}
	}
	dochenh = abs(tren - duoi);
	if (dochenh < cl)
	{
		cl = dochenh;
		for (int k = 1; k <= n; k++)
			ttluu[k] = tt[k];
		cout << "\ncl=: " << cl;
	}
}

void Xuat() {
	int dem = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ttluu[i] == 1)
		{
			dem++;
		}
		cout << ttluu[i] << "   ";
	}
	cout << "\nSo lan xoay: " << dem;
}

void Thu(int i) {
	int k;
	for (k = 0; k <= 1; k++)
	{
		tt[i] = k;
		if (i < n) {
			i++;
			Thu(i);
		}
		else	KiemTra();
		tt[i] = 0;
	}
}


int main()
{
	int data;
	ifstream co;
	co.open("F:\thực tập cơ sở\bt5.txt");
	co >> n;
	for (int i = 1; i <= n; i++)
	{
		co >> data;
		a[i].tren = data;
		co >> data;
		a[i].duoi = data;
	}
	co.close();
	//	NhapCo(n);
	cout << "\nn= " << n;
	Thu(1);
	Xuat();
}

