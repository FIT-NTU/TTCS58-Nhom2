#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<stdlib.h>
#include<conio.h>
using namespace std;
/*Khoi tao lop KhachHang*/
class KhachHang{
	public:
		char makh[5], tenkh[30];
		int sodutien;		
};
/*Khoi tao lop GiaoDich*/
class GiaoDich{
	public:
		char makh[5];
		char loaigd[2];			//"g": gui tien - "r": rut tien
		int tiengiaodich;
};
/*Khoi tao lop XuLy gom 1 danh sach khach hang va 1 danh sach giao dich*/
class XuLy{
	public:
		vector <KhachHang> dskh;
		vector <GiaoDich> dsgd;
		bool ThemKH (KhachHang kh);
		int ThuchienGD (char makh[5], char loaigd[2], int tiengiaodich);
		void InDSKH();
		void InSaoke (char makh[5]);
		void DocKH();
		void DocGD();
		void GhiKH(KhachHang kh);
		void GhiGD(GiaoDich gd);
		void CapNhatKH();
};
/*
	Phuong thuc doc danh sach khach hang tu file customer
	Output: Du lieu doc tu file customer se luu vao vector dskh
*/
void XuLy::DocKH()
{
	FILE *f = fopen("customer.dat","rb");
	int i = 0;
	KhachHang tam;
	dskh.clear();
	while (!feof(f))
	{
		fread(&tam,sizeof(KhachHang),1,f);
		dskh.insert(dskh.begin()+i, tam);
		i++;
	}
	dskh.pop_back();	
	rewind(f);
	fclose(f);
}
/*
	Phuong thuc doc danh sach giao dich tu file trans
	Output: Du lieu doc tu file trans se luu vao vector dsgd
*/
void XuLy::DocGD()
{
	FILE *g = fopen("trans.dat","rb");
	int i = 0;
	GiaoDich tam;
	dsgd.clear();
	while (!feof(g))
	{
		fread(&tam,sizeof(GiaoDich),1,g);
		dsgd.insert(dsgd.begin()+i, tam);
		i++;
	}
	dsgd.pop_back();	
	rewind(g);
	fclose(g);
}
/*
	Phuong thuc ghi du lieu 1 khach hang vao file customer
	Input: Thong tin 1 khach hang
	Output: Du lieu 1 khach hang duoc ghi vao cuoi file customer
*/
void XuLy:: GhiKH(KhachHang kh)
{
	FILE *f = fopen("customer.dat","ab");
	fwrite(&kh,sizeof(KhachHang),1,f);
	fclose(f);
}
/*
	Phuong thuc ghi du lieu 1 giao dich vao file trans
	Input: Thong tin 1 giao dich
	Output: Du lieu 1 giao dich duoc ghi vao cuoi file trans
*/
void XuLy:: GhiGD(GiaoDich gd)
{
	FILE *f = fopen("trans.dat","ab");
	fwrite(&gd,sizeof(GiaoDich),1,f);
	fclose(f);
}
/*
	Phuong thuc cap nhat file customer
	Output: Du lieu tu vector dskh ghi de vao file customer
*/
void XuLy::CapNhatKH()
{
	FILE *f = fopen("customer.dat","wb");
	for (int i = 0; i < dskh.size(); i++)
		fwrite(&dskh[i],sizeof(KhachHang),1,f);
	fclose(f);
}
/*
	Phuong thuc them 1 khach hang vao danh sach khach hang
	Input: Thong tin 1 khach hang
	Output: Thong tin 1 khach hang duoc them vao cuoi danh sach khach hang
*/
bool XuLy::ThemKH (KhachHang kh)
{
	int size = dskh.size();
	for (int i = 0; i < size; i++)
		if (strcmp(dskh[i].makh,kh.makh) == 0)
			return false;
	dskh.insert(dskh.begin()+dskh.size(), kh);
	GhiKH(kh);
	return true;	
}
/*
	Phuong thuc xu ly qua trinh giao dich
	Input: makh[5] - ma khach hang se giao dich
		   loaigd[2] - hinh thuc giao dich ("g": gui tien, "r": rut tien)
		   tiengiaodich - so tien giao dich
	Output: 0 - khong tim thay khach hang trong danh sach
			1 - khach hang khong du tien rut
			2 - giao dich thanh cong
*/
int XuLy::ThuchienGD (char makh[5], char loaigd[2], int tiengiaodich)
{
	GiaoDich gd;
	strcpy(gd.makh,makh);
	strcpy(gd.loaigd,loaigd);
	gd.tiengiaodich = tiengiaodich;
	KhachHang kh;
	int i;
	for (i = 0; i < dskh.size(); i++)
		if (strcmp(makh,dskh[i].makh) == 0)
		{
			strcmp(kh.makh,dskh[i].makh);
			strcmp(kh.tenkh,dskh[i].tenkh);
			kh.sodutien = dskh[i].sodutien;
			break;
		}
	if(i==dskh.size())	
		return 0;// khong co khach hang
	if(strcmp(loaigd,"r") == 0)	
		if(kh.sodutien < tiengiaodich)
			return 1; //khong du tien rut
		else
		{
			kh.sodutien -= tiengiaodich;
			dskh[i].sodutien = 	kh.sodutien;
			dsgd.insert(dsgd.begin() + dsgd.size(), gd);
			GhiGD(gd);
			CapNhatKH();
		}			
	else
	{
		kh.sodutien += tiengiaodich;
		dskh[i].sodutien = 	kh.sodutien;
		dsgd.insert(dsgd.begin() + dsgd.size(), gd);
		GhiGD(gd);
		CapNhatKH();
	}
	return 2; //giao dich thanh cong			
}
/*
	Phuong thuc in ra danh sach khach hang
	Output: Danh sach khach hang duoc in ra man hinh
*/
void XuLy::InDSKH()
{
	for (int i = 0; i < dskh.size(); i++)
		cout<<dskh[i].makh<<"\t"<<dskh[i].tenkh<<"\t"<<dskh[i].sodutien<<endl;
}	
/*
	Phuong thuc in ra sao ke cho 1 khach hang
	Input: makh[5] - ma khach hang can tim
	Output: Cac giao dich ma 1 khach hang da thuc hien duoc in ra man hinh
*/
void XuLy::InSaoke (char makh[5])
{
	for (int i = 0; i < dsgd.size(); i++)
		if(strcmp(dsgd[i].makh, makh) == 0)
			if (strcmp(dsgd[i].loaigd,"g") == 0)
				cout<<dsgd[i].makh<<"\tGui tien\t"<<dsgd[i].tiengiaodich<<endl;	
			else
				cout<<dsgd[i].makh<<"\tRut tien\t"<<dsgd[i].tiengiaodich<<endl;	
}	
/*
	Ham nhap thong tin 1 khach hang tu ban phim
	Output: Tra ve thong tin 1 khach hang
*/
KhachHang NhapKH()
{
	KhachHang kh;
	cin.sync();
	cout<<"Nhap ma khach hang: ";
	cin.get(kh.makh,5);
	cin.sync();
	cout<<"Nhap ten khach hang: ";
	cin.get(kh.tenkh,30);
	cin.sync();
	cout<<"Nhap so du tien: ";
	cin>>kh.sodutien;
	cin.sync();
	return kh;	
}
/*
	Ham nhap thong tin 1 giao dich tu ban phim
	Output: Tra ve thong tin 1 giao dich
*/
GiaoDich NhapGD()
{
	GiaoDich gd;
	cin.sync();
	cout<<"Nhap ma khach hang: ";
	cin.get(gd.makh,5);
	cin.sync();
	cout<<"Nhap tien giao dich: ";
	cin>>gd.tiengiaodich;
	cin.sync();
	return gd;
}
int main()
{
	XuLy xl;
	int key;
	KhachHang kh;
	GiaoDich gd;
	xl.DocKH();
	xl.DocGD();
	cout<<"Nhap key de thuc hien chuc nang: "<<endl;
	cout<<"---------------------------------"<<endl;
	cout<<"1. Them moi khach hang"<<endl;
	cout<<"2. Cho phep khach hang gui tien"<<endl;
	cout<<"3. Cho phep khach hang rut tien"<<endl;
	cout<<"4. In danh sach khach hang"<<endl;
	cout<<"5. In sao ke cho mot khach hang"<<endl;
	cout<<"0. Ket thuc"<<endl;
	cout<<"---------------------------------"<<endl;
	do
	{
		cout<<"Nhap key: ";
		cin>>key;
		switch(key)
		{
			case 1:
				kh = NhapKH();
				xl.ThemKH(kh);
				break;
			case 2:
				gd = NhapGD();
				strcpy(gd.loaigd,"g");
				xl.ThuchienGD(gd.makh,gd.loaigd,gd.tiengiaodich);
				xl.DocKH();
				break;
			case 3:
				gd = NhapGD();
				strcpy(gd.loaigd,"r");
				xl.ThuchienGD(gd.makh,gd.loaigd,gd.tiengiaodich);
				xl.DocKH();				
				break;
			case 4:
				xl.InDSKH();
				break;
			case 5:
				cin.sync();
				cout<<"Nhap ma khach hang can liet ke: ";
				cin.get(gd.makh,5);
				xl.InSaoke(gd.makh);
				break;
		}
		cout<<endl;
	}
	while (key != 0);
}
