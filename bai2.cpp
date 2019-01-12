#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>

using namespace std;

struct xe {
	char soxe[10];
	char loaixe[20];
	char hieuxe[20];
	xe *tiepxe;
	
};

struct con {
	char mnk[5];
	char hoten[20];
	char gtinh[10];
	con *tiepcon;
};

struct hk {
	char sohk[5];
	char mnkch[10];
	char hotench[20];
	char dchi[20];
	xe *txe;
	con *tcon;
	hk *tiepho;
};

hk *dau;

void khoitao(hk *&dau)
{
	dau=NULL;
}

//nhap danh sach xe

void nhapxe(xe *&dx)
{
	xe *p,*q;
	char soxet[10];
	char lxt[20];
	char hieuxet[20];
	do
	{
		printf("\n nhap bang so xe: ");
		fflush(stdin);
		gets(soxet);
			if (strcmp(soxet,"\0")!=0)
			{
				p=new xe;
				strcpy(p->soxe,soxet);
				printf("\n Ten loai xe: ");
				fflush(stdin);
				gets(lxt);
				strcpy(p->loaixe,lxt);
				printf("\n hieu xe: ");
				fflush(stdin);
				gets(hieuxet);
				strcpy(p->hieuxe,hieuxet);
				p->tiepxe=NULL;
				if (dx==NULL)
					dx=p;
				else
					q->tiepxe=p;
				q = p;
			}
	}
	while (strcmp(soxet,"\0")!=0);
}

// nhap danh sanh con

void nhapcon(con *&dc)
{
	con *p,*q;
	char mnkt[10];
	char hotent[20];
	char gtinht[10];
	do
	{
		printf("\n nhap ma nhan khau con: ");
		fflush(stdin);
		gets(mnkt);
			if (strcmp(mnkt,"\0")!=0)
			{
				p=new con;
				strcpy(p->mnk,mnkt);
				printf("\n Ho ten con: ");
				fflush(stdin);
				gets(hotent);
				strcpy(p->hoten,hotent);
				printf("\n gioi tinh: ");
				fflush(stdin);
				gets(gtinht);
				strcpy(p->gtinh,gtinht);
				p->tiepcon=NULL;
				if (dc==NULL)
					dc=p;
				else
					q->tiepcon=p;
				q = p;
			}
	}
	while (strcmp(mnkt,"\0" )!= 0);
}

//nhap danh sach cac ho 

void nhapho(hk *&dau)
{
	hk *p,*q;
	char sohkt[5];
	char mnkcht[10];
	char hotencht[20];
	char dchit[20];
	do
	{
		printf("\n nhap so ho khau: ");
		fflush(stdin); // doc kieu chuoi
		gets(sohkt);
			if (strcmp(sohkt,"\0")!=0)
			{
				p=new hk;
				strcpy(p->sohk,sohkt);
				printf("\n nhap ma nhan khau chu ho: ");
				fflush(stdin);
				gets(mnkcht);
				strcpy(p->mnkch,mnkcht);
				printf("\n nhap ho ten chu ho: ");
				fflush(stdin);
				gets(hotencht);
				strcpy(p->hotench,hotencht);
				printf("\n nhap dia chi: ");
				fflush(stdin);
				gets(dchit);
				strcpy(p->dchi,dchit);
				p->tcon=NULL;//************
				p->txe=NULL;
				nhapcon(p->tcon);
				nhapxe(p->txe);
				if(dau==NULL)
					dau=p;
				else
					q->tiepho=p;
				q=p;
					
			}
	}
	while (strcmp(sohkt,"\0") != 0);
}

//--------------
//vong lap
void duyetxe(xe *dx)
{
	xe *p;
	p=dx;
		while(p!=NULL)
		{
			printf("\n So xe: %s",p->soxe);
			printf("\n Loai xe: %s",p->loaixe);
			printf("\n Hieu xe: %s",p->hieuxe);
			p=p->tiepxe;
		}
}

//---------------------------------
// de quy
void duyetcon(con *dc)
{
	if(dc!=NULL)
	{
		printf("\n Ma nhan khau: %s",dc->mnk);
		printf("\n Ho ten con: %s",dc->hoten);
		printf("\n gioi tinh: %s",dc->gtinh);
		duyetcon(dc->tiepcon);
	}
}

//----------------------------
void duyet(hk *dau)
{
	hk *p;
	p = dau;

		while(dau!=NULL)
		{
			printf("\n So ho khau: %s",p->sohk);
			printf("\n Ma nhan khau chu ho: %s",p->mnkch);
			printf("\n Ho ten chu ho: %s",p->hotench);
			printf("\n Dia chi: %s",p->dchi);
			printf("\n Danh sach cac con:");
			duyetcon(p->tcon);
			printf("\n Danh sach xe cua ho:");
			duyetxe(p->txe);
			
		}
		
}
//------------------
void duyethk(hk *dau)
{
	char sohkt[5];
	hk *p;
	printf("\n Nhap so ho khau can xem: ");
	fflush(stdin);
	gets(sohkt);
	p=dau;
		while((p!=NULL) && (strcmp(p->sohk,sohkt)!=0))
			p=p->tiepho;
		if(p==NULL)
			printf("\n Khong co ho nay!");
		else
		{
			printf("\n So ho khau: %s",p->sohk);
			printf("\n Ma nhan khau chu ho: %s",p->mnkch);
			printf("\n Ho ten chu ho: %s",p->hotench);
			printf("\n Dia chi: %s",p->dchi);
			printf("\n Danh sach cac con:");
			duyetcon(p->tcon);
		}
		
}
//-------cau c---------------------------
int kthieuxe(hk *&dau, char hieuxet[20])
{
	hk *p;
	p=dau;
	int dem = 0;
    while (p != NULL) {
        while(p->txe != NULL) {
            if (strcmp(p->txe->hieuxe,hieuxet)!=0)
            	dem ++;
//            {
//            	printf("\nHo co xe:");
//            	duyet(dau);
//			}
            p->txe = p->txe->tiepxe;
        }
        p = p->tiepho;
    }
    return dem;
	
}


//void Xoa(Node *&pHead, int x){
//	Node* tam = pHead;
//	while(tam != NULL){
//		// xoa Node dau tien.
//		if(tam == pHead && tam -> data == x){
//			Node *tam1 = tam;
//			pHead = tam -> next;
//			free(tam1);
//			return;
//		}
//		// xoa Node cuoi cung.
//		else if(tam -> data == x && tam -> next == NULL){
//			Node* tam1 = tam;
//			tam = NULL;
//			free(tam1);
//			return;
//		}
//		// xoa Node bat ky nhung khong phai la cuoi cung va dau tien.
//		else if(tam -> data == x){
//			Node* tam1 = tam;
//			tam = tam -> next;
//			free(tam1);
//			return;
//		}
//		tam = tam -> next;
//	}
//}
////---------------


int main()
{
	khoitao(dau);
	nhapho(dau);
	duyethk(dau);
	printf("\n");
	char hieuxet[20];
	printf("nhap hieu xe can tim ho:");
	fflush(stdin);
	gets(hieuxet);
	printf("co %d ho co hieu giong nhau!",kthieuxe(dau,hieuxet));
//	kthieuxe(dau,hieuxet);
//	duyet(dau);


	
	getch();
	return 0;
}

