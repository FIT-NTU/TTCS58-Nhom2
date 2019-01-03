#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
struct Xe{
	char SoXe[12];
	char LoaiXe[6];
	char HieuXe[10];
	Xe *tx;// nut tiep xe
};
struct Con{
	char MaSC[9];// ma so con
	char HoTen[30];
	char GioiTinh[4];
	Con *tc;// nut tiep con
};
struct HoGD{
	char SoHK[5];
	char MaHK[9];
	char Ten[20];
	char DiaChi[20];
	Xe *DSX;// xe -> DS xe
	Con *DSC;// Con -> DScon
	HoGD *th;// tiep ho gd
};
HoGD *dau;
void KhoiTao(HoGD *&dau){
	dau = NULL;
}
void NhapXe(Xe *&dx){
	char SoXeT[12];
	char LoaiXeT[6];
	char HieuXeT[10];
	Xe *p,*q;
	do{
		fflush(stdin);
		cout << "Nhap bien so xe (enter de dung): ";
		gets(SoXeT);
		if((strcmp(SoXeT,"\0")!=0)){
			p = new Xe;
			strcpy(p->SoXe,SoXeT);
			cout << "Nhap loai xe: ";
			fflush(stdin);
			gets(LoaiXeT);
			cout << "Nhap hieu xe: ";
			fflush(stdin);
			gets(HieuXeT);
			strcpy(p->LoaiXe,LoaiXeT);// gan loai xe tam -> loai xe
			strcpy(p->HieuXe,HieuXeT);// gan hieu xe tam-> hieu xe
			p-> tx = NULL;
				// MOC VAO DS Xe
				if(dx==NULL)
					dx = p;
				else
					q -> tx=p;
					q=p	;
		}
		
	}
	while (strcmp(SoXeT,"\0")!=0);
}
void NhapCon(Con *&dc){
	char MaSCT[9]; // ma so con tam
	char HoTenT[30];
	char GioiTinhT[4];
	Con *p,*q;
	do{
		fflush(stdin);
		cout << "Nhap ma so con (enter de dung): ";
		gets(MaSCT);
		if((strcmp(MaSCT,"\0")!=0)){
			p = new Con;
			strcpy(p->MaSC,MaSCT);
			cout << "Nhap ho ten con: ";
			fflush(stdin);
			gets(HoTenT);
			cout << "Nhap gioi tinh con: ";
			fflush(stdin);
			gets(GioiTinhT);
			strcpy(p->HoTen,HoTenT);
			strcpy(p->GioiTinh,GioiTinhT);
			p-> tc= NULL;
				// MOC VAO DS CON
				if(dc==NULL)
					dc = p;
				else
					q -> tc=p;
					q=p	;
		}
		
	}
	while (strcmp(MaSCT,"\0")!=0);
}
void NhapHo(HoGD *& DSH){
	char SoHKT[5];
	char MaHKT[9];
	char TenT[20];
	char DiaChiT[20];
	HoGD *p,*q;
	do{	
		cout << "Nhap So Ho khau ";
		fflush(stdin);
		gets(SoHKT);
		if (strcmp(SoHKT,"\0")!=0){
			p = new HoGD;
			strcpy(p -> SoHK,SoHKT);
			cout << "Nhap ma ho khau :";
			fflush(stdin);
			gets(MaHKT);
			cout << "Nhap ten chu ho :";
			fflush(stdin);
			gets(TenT);
			cout << "Nhap dia chi :";
			fflush(stdin);
			gets(DiaChiT);
				strcpy(p->MaHK,MaHKT);
				strcpy(p->Ten,TenT);
				strcpy(p->DiaChi,DiaChiT);
				p->DSC=NULL;
				p->DSX=NULL;
				NhapXe(p->DSX);
				NhapCon(p->DSC);
			if (DSH == NULL)
				DSH= p;
			else
				q->th = p;
				q=p;
		}		
	}
	while (strcmp(SoHKT,"\0")!=0);// dieu kien dung
}
void DanhSachC(Con *dc)
{
	if(dc!=NULL)
	{
		cout << "Ma nhan khau: " << dc->MaSC << endl;
		cout << "Ho ten con: "<< dc->HoTen << endl;
		cout << "gioi tinh: "<< dc->GioiTinh <<endl;
		DanhSachC(dc->tc);
	}
}
void TimHK(HoGD *dau)
{
	char SoHKT[5];
	HoGD *p;
	cout << "Nhap ho khau can tim : ";
	fflush(stdin);
	gets(SoHKT);
	p=dau;
		while((p!=NULL) && (strcmp(p->SoHK,SoHKT)!=0))
			p=p->th;
		if(p==NULL)
			cout << " Khong co ho khau nay!";
		else
			DanhSachC(p->DSC);		
}
int main(){
	KhoiTao(dau);
	NhapHo(dau);
	TimHK(dau);
}
