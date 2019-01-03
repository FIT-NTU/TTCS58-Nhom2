#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


struct xe{
	char soxe[12];
	char loaixe[6];
	char hangsx[15];
	 xe *tx;
};

struct con{
	char msc[9];
	char htc[30];
	char gt[4];
	 con *tc;
};

struct ho {
	char mh[5];
	char msnk[9];
	char htch[30];
	char dchi[30];
	xe *dsx;
	con *dsc;
	ho *th;
	
};
//------------------------------------
ho *dau;
void khoitao(ho *&dau){
	dau = NULL;
}

//------------ nhap con

void nhapcon(con *&dc){
	char msct[9]; char htct[30]; char gtt[4];
	con *p, *q;
	
	do{
		printf ("\n nhap ma so con, enter -> dung: ");
		fflush(stdin);
		gets(msct);
		if (strcmp(msct, "\0") != 0){
		
		p = new con;
		strcpy(p->msc, msct);
		printf (" nhap ho ten con: ");
		fflush(stdin);
		gets(htct);
		printf (" nhap gioi tinh con: ");
		fflush(stdin);
		gets(gtt);
		strcpy(p->htc, htct);
		strcpy(p->gt, gtt);
		p->tc = NULL;
		//--- moc vao ds con
		if (dc == NULL)
			 dc = p;
		else
			q->tc = p;
			q = p;
	}}while(strcmp(msct, "\0") != 0);
}

///------- nhap xe
void nhapxe(xe *&dx){
	char soxet[12]; char loaixet[6]; char hangsxt[15];
	xe *p, *q;
	
	do{
		printf ("\n nhap so xe, enter -> dung: ");
		fflush(stdin);
		gets(soxet);
		if (strcmp(soxet, "\0") != 0){
		
		p = new xe;
		strcpy(p->soxe, soxet);
		printf (" nhap loai xe: ");
		fflush(stdin);
		gets(loaixet);
		printf (" nhap hang san xuat: ");
		fflush(stdin);
		gets(hangsxt);
		strcpy(p->loaixe,loaixet);
		strcpy(p->hangsx, hangsxt);
		p->tx = NULL;
		//--- moc vao ds con
		if (dx == NULL)
			 dx = p;
		else
			q->tx = p;
			q = p;
	}}while(strcmp(soxet, "\0") != 0);
}

//------------------ nhap ho
void nhapho(ho *&dsho){
	char mht[5];
	char msnkt[9];
	char htcht[30];
	char dchit[30];
	ho *p, *q;
	do {
		printf ("\n Nhap so ho khau: ");
		fflush(stdin);
		gets(mht);
		if (strcmp(mht,"\0") != 0)
			{
				p = new ho;
				strcpy(p->mh, mht);
				printf ("\n Nhap ma chu ho: ");
				fflush(stdin);
				gets(msnkt);
				printf ("\n Nhap ho ten chu ho: ");
				fflush(stdin);
				gets(htcht);
				printf ("\n Nhap dia chi: ");
				fflush(stdin);
				gets(dchit);
				strcpy(p->msnk, msnkt);
				strcpy(p->htch, htcht);
				strcpy(p->dchi, dchit);
				p->dsc = NULL;
				p->dsx = NULL;
				printf ("\n nhap xe: \n");
				nhapxe(p->dsx);
				printf ("\n nhap con: \n");
				nhapcon(p->dsc);
				if (dsho == NULL)
					dsho = p;
				else
					p->th = q;
					q = p;
			}
		}while(strcmp(mht, "\0") != 0);
} 

//------- in danh sach thanh vien cua 1 ho
int socon(con *tvcon){
	if (tvcon == NULL)
		printf (" \nhet\n");
	else {
		printf("\n%s%s%s%s",tvcon->htc, "\t",tvcon->msc,"\t",tvcon->gt);
		socon(tvcon->tc);}
}
void  thanhvien(ho *dau){
	char tam[5];
	fflush(stdin);
		printf ("\n nhap ma ho: ");
		gets(tam);
		if (dau != NULL){
			if((strcmp (dau->mh, tam)) == 0){
				printf ("\n %s", dau->mh);
				printf("\n");
				socon(dau->dsc);
		}		}
	
	
}

//----------------- tim xem ho co hang xe
//void timhang(xe *th){
//	int tam[15];
//	if (th != NULL){
//		fflush(stdin);
//		printf ("\n nhap hang xe:");
//		gets(tam);
//		if (strcmp(th->hangsx, tam)== 0){
//			printf("\n%s%s%s", th->hangsx, th->loaixe, th->soxe)
//		}
//		else{
//			printf ("khong co hang xe do: ");
//		}
//	}
//}

void hchx( ho *dau){
	char tam[15];
	if (dau != NULL){
		fflush(stdin);
		printf("\nnhap hang xe: ");
		gets(tam);
		if (strcmp(dau->dsx->hangsx, tam)==0){
			printf("\n%s%s", dau->mh, dau->htch);
			hchx(dau->th);
		}
	}
}

//------------xoa 1 xe cua chu ho
void xoaxe(xe *xxe){
	xe *p, *q;
	if (xxe == NULL){
		printf ("\n k co xe \n");
	}
	else
	{
		p = q->tx;
		q->tx = q->tx->tx;
		delete p;
		printf (" da xoa xong");
	}
}
void hoxoaxe(ho *dau){
	char tam[5];
	if (dau != NULL){
		fflush(stdin);
		printf("nhap ma ho: ");
		gets(tam);
		if(strcmp(dau->mh,tam)==0){
			xoaxe(dau->dsx);
		}
	}
}
//-----------------
int main(){
	
	khoitao(dau);
	nhapho(dau);
	printf("\n nhap xong du lieu: \n");
	getch();
	printf("-----------------------");
	thanhvien(dau);
	printf("-------------------");
	hchx(dau);
	hoxoaxe(dau);
}
