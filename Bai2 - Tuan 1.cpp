# include <stdio.h>
# include <iostream>
# include <string.h>
using namespace std;
struct Xe{
	char MSXe[10];
	char LoaiXe[30];
	char HieuXe[30];
	Xe *tx;
};
struct Con{
	char MaNKC[10];
	char HoTen[30];
	char GioiTinh[5];
	Con *tc;
};
struct Ho{
	char SoHK[10];
	char MaNK[10];
	char TenChuHo[30];
	char DiaChi[50];
	Xe *dsxe;
	Con *dscon;
	Ho *th;
};
void NhapXe (Xe *&dsxe)
{
	char tam[10];
	Xe *p, *q;
	do
	{
		cout<<"Nhap so xe, ket thuc 0: ";
		cin.get(tam,10);
		cin.sync();
		if (strcmp(tam,"0") != 0)
		{
			p = new Xe;
			strcpy(p->MSXe,tam);
			cout << "Nhap loai xe: ";
			cin.get(p->LoaiXe, 30);
			cin.sync();
			cout << "Nhap hieu xe: ";
			cin.get(p->HieuXe, 30);
			cin.sync();
			p->tx = NULL;
			if (dsxe == NULL)
				dsxe = p;
			else
				q->tx = p;
			q = p;
		}
	}
	while (strcmp(tam,"0") != 0);
}
void NhapCon (Con *&dscon)
{
	char tam[10];
	Con *p, *q;
	do
	{
		cout<<"Nhap ma nhan khau con, ket thuc 0: ";
		cin.get(tam,10);
		cin.sync();
		if (strcmp(tam,"0") != 0)
		{
			p = new Con;
			strcpy(p->MaNKC,tam);
			cout<<"Nhap ho ten: ";
			cin.get(p->HoTen,30);
			cin.sync();
			cout<<"Nhap gioi tinh: ";
			cin.get(p->GioiTinh,5);
			cin.sync();
			p->tc = NULL;
			if (dscon == NULL)
				dscon = p;
			else
				q->tc = p;
			q = p;
		}
	}
	while (strcmp(tam,"0") != 0);
}
void NhapHK (Ho *&dshk)
{
	char tam[10];
	Ho *p, *q;
	do
	{
		cout<<"Nhap so ho khau , ket thuc 0: ";
		cin.get(tam,10);
		cin.sync();
		if (strcmp(tam,"0") != 0)
		{
			p = new Ho;
			strcpy(p->SoHK,tam);
			cout<<"Nhap ma nhan khau: ";
			cin.get(p->MaNK,10);
			cin.sync();
			cout<<"Nhap ten chu ho: ";
			cin.get(p->TenChuHo,30);
			cin.sync();
			cout<<"Nhap dia chi: ";
			cin.get(p->DiaChi,50);
			cin.sync();			
			p->dscon = NULL;
			p->dsxe = NULL;
			NhapCon(p->dscon);
			NhapXe(p->dsxe);
			p->th = NULL;
			if (dshk == NULL)
				dshk = p;
			else
				q->th = p;
			q = p;
		}
	}
	while (strcmp(tam, "0") != 0);
}
void XuatXe (Xe *dsxe)
{
	if (dsxe != NULL)
	{
		cout<< dsxe->MSXe << " " << dsxe->LoaiXe << " " << dsxe->HieuXe << endl;
		XuatXe(dsxe->tx);
	}
}
void XuatCon (Con *dscon)
{
	if (dscon != NULL)
	{
		cout << dscon->MaNKC << " "<< dscon->HoTen << " " << dscon->GioiTinh << endl;
		XuatCon(dscon->tc);
	}
}
void XuatHK(Ho *dshk, char x[10])
{
	Ho *p;
	p = dshk;
	while ((p != NULL) && (strcmp(p->SoHK, x) != 0))
	{
		p = p->th;
	}
	if (p == NULL)
		cout << "Khong tim thay ho can tim";
	else
	{
		cout << p->SoHK << " " << p->MaNK << " " << p->TenChuHo << " " << p->DiaChi << endl;
		cout << "Thong tin xe: " << endl;
		XuatXe(p->dsxe);
		cout << "Thong tin con: " << endl;
		XuatCon(p->dscon);
	}
}
int DemXe(Xe *dsxe, char h[30])
{
	if (dsxe == NULL)
		return 0;
	else
		if( strcmp(dsxe->HieuXe, h) == 0)
			return 1 + DemXe(dsxe->tx, h);
		else
			return DemXe(dsxe->tx, h);
}
void TimXe(Ho *dshk, char h[30])
{
	if (dshk != NULL)
	{
		if (DemXe(dshk->dsxe, h) >= 1)
		{
			cout << dshk->SoHK<<" "<< dshk->MaNK << " " << dshk->TenChuHo << " " << dshk->DiaChi << endl;
			cout << "Thong tin con: " << endl;
			XuatCon(dshk->dscon);
			cout << endl;
		}
		TimXe (dshk->th, h);
	}
}
void XoaXe(Ho *dshk, char x[10], char y[10])
{
	Ho *p;
	p = dshk;
	while ((p != NULL) && (strcmp(p->SoHK,x) != 0))
	{
		p = p->th;
	}
	if (p == NULL)
		cout << "Khong tim thay ho can tim";
	else
	{
		Xe *q, *t;
		q = p->dsxe;
		while ((q != NULL) && (strcmp(q->MSXe, y) != 0))
		{
			t = q;
			q = q->tx;
		}
		if (q == NULL)
			cout << "Khong tim thay xe can tim";
		else
		{
			if (q == p->dsxe)
			{
				p->dsxe = q->tx;
				delete q;
			}
			else
			{
				t->tx = q->tx;
				delete q;
			}
		}
	}
}
Ho *dau;
void Khoitao(Ho *&dau){
	dau = NULL;
}
int main(){
	Khoitao(dau);
	NhapHK(dau);
	char x[10];
	char h[30];
	cout << endl << "Truoc khi xoa: " << endl;
	XuatHK(dau,"1");
	cout << endl << "Sau khi xoa: "<< endl;
	XoaXe(dau, "1", "X1");
	XuatHK(dau, "1");
}
