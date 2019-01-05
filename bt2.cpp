#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

struct Xe{//khai bao Xe
	string soxe;
	string loaixe, hieuxe;
	Xe *xnext;//dia chi cua vi tri tiep theo
};

struct Con{//Khai bao con
	string mank;
	string hoten, gioitinh;
	Con *cnext;//dia chi vi tri tiep theo
};

struct HoKhau{//khai bao ho khau
	string sohk, mank;
	string ten, diachi;
	HoKhau *hknext;//dia chi vi tri tiep theo
	Xe *xe;//dia chi cua xe thuoc ho khau
	Con *con;//dia chi cua con thuoc ho khau
};

void khoitao(Xe *&dau){
	dau = NULL;//gan cho gia tri NULL
}

void khoitao(Con *&dau){
	dau = NULL;//gan cho gia tri NULL
}

void khoitao(HoKhau *&dau){
	dau = NULL;//gan cho gia tri NULL
}

void NhapXe(Xe *&dau){
	Xe *p, *q;//tao 2 bien kieu xe de chua thong tin 
	string soxee;//mang thong tin soxe de xet dieu kien
	do{
		cout<<"Nhap so xe: ";
		getline(cin, soxee);
		if(soxee.compare("\0") != 0){
			p = new Xe;
			//nhap thong tin cho xe cho p
			p->soxe = soxee;
			cout<<"Loaioai xe: ";
			getline(cin, p->loaixe);
			cout<<"Hieu xe: ";
			getline(cin, p->hieuxe);
			//dua thong tin cua xe p vao danh sach lien ket
			if(dau == NULL)
				dau = p;//gan gia tri dau bang p
			else
				q->xnext = p;//chuyen dia chi cua p sang q
			q = p;//gan gia tri cua p sang q
		}
		cout<<endl;
		p->xnext = NULL;//gan gia tri cuoi bang NULL
	}while(soxee.compare("\0") != 0);
}

void NhapCon(Con *&dau){
	Con *p, *q;
	string mankk;
	do{
		cout<<"Nhap ma nhan khau: ";
		getline(cin, mankk);
		if(mankk.compare("\0") != 0){
			p = new Con;
			p->mank = mankk;
			cout<<"Ten nhan khau: ";
			getline(cin, p->hoten);
			cout<<"Gioi tinh: ";
			getline(cin, p->gioitinh);
			if(dau == NULL)
				dau = p;
			else
				q->cnext = p;
			q = p;
			p->cnext = NULL;
		}	
		cout<<endl;
	}while(mankk.compare("\0") != 0);
}

void NhapHK(HoKhau *&dau){
	HoKhau *p, *q;
	string sohkk;
	int i= 1;
	do{
		cout<<"Nhap thong tin chu ho thu "<<i<<endl;
		cout<<"Nhap so ho khau: ";
		getline(cin, sohkk);
		if(sohkk.compare("\0") != 0){
			p = new HoKhau;
			p->sohk = sohkk;
			cout<<"Ma nk chu ho: ";
			getline(cin, p->mank);
			cout<<"Ho ten chu ho: ";
			getline(cin, p->ten);
			cout<<"Dia chi: ";
			getline(cin, p->diachi);
			p->con = NULL;
			cout<<"Nhan khau(Con) thu "<<i<<endl;
			NhapCon(p->con);//Nhap thong tin con cua chu ho
			p->xe = NULL;
			cout<<"Nhap TT Xe thu "<<i<<endl;
			NhapXe(p->xe);//Nhap thong tin xe cua chu ho
			if(dau == NULL)
				dau = p;
			else
				q->hknext = p;
			q = p;
		}	
		cout<<endl;
		i++;
	}while(sohkk.compare("\0") != 0);
}

void InCon(Con *&dau){
	Con *tam;
	tam = dau;
	while(tam != NULL)
	{
		cout<<"Ho ten(Con): "<<tam->hoten<<endl;
		tam=tam->cnext;//chuyen toi vi tri tiep theo
	}
}

void InXe(Xe *&dau){
	Xe *tam;
	tam = dau;
	while(tam != NULL)
	{
		cout<<"So xe: "<<tam->soxe<<endl;
		cout<<"Loai xe: "<<tam->loaixe<<endl;
		cout<<"Hieu xe: "<<tam->hieuxe<<endl;
		tam=tam->xnext;//chuyen toi vi tri tiep theo
	}
}

void InHK(HoKhau *&dau){
	HoKhau *tam;
	tam = dau;
	if(tam==NULL)cout<<"\nkhong co ho nao";//rong
	while(tam != NULL)//khong rong
	{
		cout<<"\nSo ho khau: "<<tam->sohk;
		cout<<"\nTen chu ho: "<<tam->ten<<endl;
		cout<<"Dia chi: "<<tam->diachi<<endl;	
		InCon(tam->con);
		InXe(tam->xe);
		tam=tam->hknext;//chuyen den vi tri tiep theo de xet dieu kien
	}
}

void InHKTK(HoKhau *&dau, string sohk){//
	HoKhau *tam;
	tam = dau;
	if(tam==NULL)cout<<"\nkhong co ho nao";//rong
	while(tam != NULL)//khong rong
	{
		if(tam->sohk == sohk)//dieu kien tim kiem
			{
				cout<<"\nSo ho khau: "<<tam->sohk;
				cout<<"\nTen chu ho: "<<tam->ten<<endl;
				InCon(tam->con);
				cout<<"Dia chi: "<<tam->diachi;
			}
		tam=tam->hknext;//chuyen den vi tri tiep theo de xet dieu kien
	}
}

int TimXe(Xe *&dau, string hieuxe){//Tim kiem vi tri cua xe 
	Xe *tam;
	tam = dau;
	while(tam!=NULL)
	{
		if(tam->hieuxe == hieuxe)		
			{
				return 1;
				break;
			}
		tam = tam->xnext;
	}
}

void InHKXe(HoKhau *dau, string hieuxe){//In xe theo hieu xe
	HoKhau *tam;
	tam = dau;
	if(tam == NULL)	cout<<"Khong co ho khau nao!!";
	while(tam!=NULL)
	{
		if(TimXe(tam->xe, hieuxe) == 1)
			{
				cout<<"\nSo ho khau: "<<tam->sohk;
				cout<<"\nTen chu ho: "<<tam->ten;
			}
		tam= tam->hknext;
	}
}

void XoaXe(Xe *&dau){//Xoa xe
	if(dau != NULL)
	{
		dau = dau->xnext;
	}
}

void XoaXEHK(HoKhau *&dau){//Xoa xe cua mot ho khau
	if(dau!= NULL)
	{
		XoaXe(dau->xe);
	}
}

int main(){
	string sohk, hieuxe;
	HoKhau *hk;
	khoitao(hk);
	NhapHK(hk);
	cout<<"Nhap so hk can tim: ";
	getline(cin, sohk);
	cout<<"THONG TIN HO KHAU SO "<<sohk<<endl;
	InHKTK(hk, sohk);
	cout<<endl<<"Nhap hieu xe can tim: ";
	getline(cin,hieuxe);
	cout<<"THONG TIN HO KHAU CO HIEU XE: "<<hieuxe<<endl;
	InHKXe(hk,hieuxe);
	cout<<endl<<"DANH SACH HO KHAU"<<endl;
	InHK(hk);
	XoaXEHK(hk);
	cout<<"DANH SACH HO KHAU SAU KHI XOA";
	InHK(hk);
	getch();
}
 
 
