#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
using namespace std;
struct con{
	char msc[9];
	char htc[30];
	char gt[4];
	con *tc;
};
struct xe{
	char soxe[12];
	char loaixe[6];
	char hangsx[15];
	xe *tx;
};
struct ho{
	char mh[6];
	char msnk[9];
	char htch[30];
	char dchi[30];
	xe *dsx;
	con *dsc;
	ho *th;
};
//-------------------------------------
ho *dau;
void khoitao (ho *&dau){
	dau = NULL;
}
//-------------------------
void nhapcon(con *&dc){
	char msct[9]; char htct[30]; char gtt[4];
	con *p, *q;
	do{
		printf("\n Nhap ma so con, enter -> dung:");
		fflush(stdin); gets(msct);
		if (strcmp(msct,"\0")!= 0){
			p = new con;
			strcpy(p->msc, msct);
			printf("\n Nhap ho ten con: ");
			fflush(stdin); gets(htct);
			printf("\n Nhap gioi tinh con: ");
			fflush(stdin); gets(gtt);
			strcpy(p->htc, htct);
			strcpy(p->gt, gtt);
			p->tc = NULL;
				//Moc vao danh sach con
				if (dc == NULL)
					dc=p;
				else
					q->tc = p;
					q = p;
		}
	}
	while(strcmp(msct,"\0")!= 0);
}
//-------------------------------------
void nhapxe(xe *&dx){
	char soxet[12]; char loaixet[6]; char hangsxt[15];
	xe *p, *q;
	do{
		printf("\n Nhap ma so xe, enter -> dung:");
		fflush(stdin); gets(soxet);
		if (strcmp(soxet,"\0")!= 0){
			p = new xe;
			strcpy(p->soxe, soxet);
			printf("\n Nhap loai xe con: ");
			fflush(stdin); gets(loaixet);
			printf("\n Nhap hang san xuat: ");
			fflush(stdin); gets(hangsxt);
			strcpy(p->loaixe,loaixet);
			strcpy(p->hangsx, hangsxt);
			p->tx = NULL;
				//Moc vao danh sach con
				if (dx == NULL)
					dx=p;
				else
					q->tx = p;
					q = p;
		}
	}
	while(strcmp(soxet,"\0")!= 0);
}
//------------------------------------------------
void nhapho(ho *&dsh){
	char mht[6];
	char msnkt[9];
	char htcht[30];
	char dchit[30];
	ho *p, *q;
do{
	printf("\n nhap so ho khau: ");
	fflush(stdin); gets(mht);
		if(strcmp(mht,"\0")!=0){
			p = new ho;
			strcpy(p->mh,mht);
			printf("\n nhap ma chu ho: ");
			fflush(stdin); gets(msnkt);
			printf("\n nhap ho ten chu ho: ");
			fflush(stdin); gets(htcht);
			printf("\n nhap dia chi: ");
			fflush(stdin); gets(dchit);
				strcpy(p->msnk,msnkt);
				strcpy(p->htch,htcht);
				strcpy(p->dchi,dchit);
				p->dsc = NULL; p->dsx = NULL;
			printf ("\n Nhap xe: \n");
				nhapxe(p->dsx);
			printf ("\n Nhap con \n");
				nhapcon(p->dsc);
		if (dsh == NULL)
			dsh = p;
		else
			q->th = p;
			q = p;
		}
}
while(strcmp(mht,"\0") != 0);
}
//---------------------------------------------Xuat
void Xuatcon(con *dc){
	if(dc != NULL){
	cout<<"\n Ho ten con :" << dc->htc;
	Xuatcon(dc->tc);
	}
}
void Xuatds(ho *dau){
	ho *p;
	p = dau;
	char mht[6];
	cout << "Nhap so ho khau:";
	fflush(stdin);
	cin.get(mht,6);
	strcmp(p->mh,mht);
	Xuatcon(p->dsc);
}
//---------------------------------------------------------------
int kiemxe(xe *dx, char hangsxt[15]){
	int a = 0;
	xe *p;
	if (strcmp(hangsxt,p->hangsx))
		return a;
}
void Xuathang(ho *dau){
	char hangxet[15];
	cout << "Nhap hang xe";
	cin.get(hangxet,15);
	ho *p;
	p = dau;
	if (strcmp(kiemxe(p->dsx, hangxet[15])))
		cout << "ma ho:" << p->mh;
	
}
//---------------------------------------------------------
int main(){
	khoitao(dau);
		printf ("\n Nhap xong du lieu\n");
	Xuatds(dau);
	Xuathang(dau);
		getch();
} 
