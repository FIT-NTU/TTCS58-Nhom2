#include<stdio.h>
#include<math.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdlib.h>
using namespace std;
fstream f("dothi.txt");
fstream g("caykhungmin.txt");
/*Khai bao kieu du lieu canh*/
struct canh{
	int diemdau, diemcuoi;
	int trongso;
};
/*
	Ham nhap vao cac canh cua do thi vo huong
	Input: a[100] - mang luu tru cac canh
		   n - so luong dinh cua do thi
		   ncanh - so luong canh cua do thi
	Output: Du lieu cac canh cua do thi duoc nhap vao mang a[100]
*/
void NhapCanh (canh a[100], int n, int &ncanh)
{
	int tam;
	int i = 0;
	int flag = 0;
	do
	{
		cout<<"Nhap dinh thu nhat cua canh: ";
		cin>>tam;
		if (tam > 0 && tam <= n)
		{
			a[i].diemdau = tam;
			do
			{
				cout<<"Nhap dinh thu hai cua canh: ";
				cin>>a[i].diemcuoi;
			}
			while (a[i].diemcuoi <= 0 || a[i].diemcuoi > n || a[i].diemcuoi == a[i].diemdau);
			do
			{
				cout<<"Nhap trong so cua canh: ";
				cin>>a[i].trongso;
			}
			while (a[i].trongso <= 0);
			for (int j = 0; j < i; j++)
				if ((a[i].diemdau == a[j].diemdau && a[i].diemcuoi == a[j].diemcuoi) || (a[i].diemdau == a[j].diemcuoi && a[i].diemcuoi == a[j].diemdau))
				{
					flag = 1;
					break;
				}
			if (flag == 0)
			{
				ncanh++;
				i++;
			}
			else
				flag = 0;
			cout<<endl;
		}
	}
	while (tam > 0);
}
/*
	Ham luu do thi vao file
	Input: a[100] - mang luu tru cac canh
		   n - so luong dinh cua do thi
		   ncanh - so luong canh cua do thi
	Output: Du lieu cac canh va so luong dinh duoc dua vao file
*/
void GhiCanh (canh a[100], int n, int ncanh)
{
	f<<n<<endl;
	for (int i = 0; i < ncanh; i++)
		f<<a[i].diemdau<<"-"<<a[i].diemcuoi<<": "<<a[i].trongso<<endl;
}
/*
	Ham doc do thi tu file
	Input: a[100] - mang luu tru cac canh
		   n - so luong dinh cua do thi
		   ncanh - so luong canh cua do thi
	Output: Du lieu cua do thi duoc doc vao
*/
void DocCanh (canh a[100], int &n, int &ncanh)
{
	int i = 0;
	string s;
	stringstream ss;
	getline(f,s);	n = atoi(s.c_str());
	while (!f.eof())
	{
		string line;
		stringstream ss;
		getline(f,line);
		ss.str(line);
		getline(ss,s,'-'); 	a[i].diemdau = atoi(s.c_str());
		getline(ss,s,':'); 	a[i].diemcuoi = atoi(s.c_str());
		getline(ss,s,':'); 	a[i].trongso = atoi(s.c_str());
		i++;
	}
	ncanh = i - 1;	
}
/*
	Ham sap xep cac canh cua do thi theo thu tu tang dan trong so
	Input: a[100] - mang luu tru cac canh
		   ncanh - so luong canh cua do thi
	Output: Cac canh cua do thi duoc sap xep theo thu tu tang dan trong so
*/
void Sapxep (canh a[100], int ncanh)
{
	for (int i = 0; i < ncanh - 1; i++)
		for (int j = i + 1; j < ncanh; j++)
			if (a[i].trongso > a[j].trongso)
				swap (a[i],a[j]);
}
/*
	Ham tim cay khung be nhat cua do thi
	Input: a[100] - mang luu tru cac canh
		   goc[100] - mang luu tru dinh goc cua moi dinh trong do thi
		   n - so luong dinh cua do thi
		   ncanh - so luong canh cua do thi
	Output: Xuat ra cac canh cua cay khung be nhat va tong trong so cua cay khung vao file
*/
int Caykhungmin (canh a[100], int goc[100], int n, int ncanh)
{
	int sum = 0;
	int dem = 0;
	for (int i = 1; i <= n; i++)
		goc[i] = i;
	for (int i = 0; i < ncanh; i++)
	{
		int x = a[i].diemdau, y = a[i].diemcuoi;
		if (goc[x] != goc[y])
		{
			int tam1 = goc[x];
			int tam2 = goc[y];
			for (int j = 1; j <= n; j++)
				if (goc[j] == tam2)
					goc[j] = tam1;
			g<<a[i].diemdau<<"-"<<a[i].diemcuoi<<": "<<a[i].trongso<<endl;
			sum += a[i].trongso;
			dem++;
		}
		if (dem == n - 1)
			break;
	}
	return sum;
}
int main()
{
	int n;
	int ncanh = 0;
	canh a[100];
	int goc[100];
	/*cout<<"Nhap so dinh: ";
	cin>>n;
	NhapCanh(a,n,ncanh);
	GhiCanh(a,n,ncanh);*/
	DocCanh(a,n,ncanh);
	Sapxep(a,ncanh);
	g<<"Cac canh cua cay khung be nhat: "<<endl;
	int sum = Caykhungmin(a,goc,n,ncanh);
	g<<"Tong trong so cua cay khung be nhat: "<<sum;		
}
