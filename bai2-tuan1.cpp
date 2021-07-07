#include<stdio.h>
#include<conio.h>
#include<string.h>
struct xe{	
	char soxe[11];
	char loaixe[15];
	char hieuxe[15];
	xe *tiep; // con tro chi den phan tu tiep theo
};
struct con{
	char maNK[5];
	char hotencon[20];
	char gioitinh[5];
	con *sau;
};
struct hokhau{
	char soHK[5];
	char maNKchuho[5];
	char tenchuho[20];
	char diachi[20];
	con *dscon;
	xe  *dsxe;
	hokhau *ke;
};

//-------------------------------------------------------------------------------//

//khoi tao mot ds rong
hokhau *dau;
void khoitao(hokhau*&dau){
	dau = NULL;
}
//--------------------------------------------------------------------------------//

// nhap du lieu 
void nhapxe(xe *& dsxe ){
	char soxet[11]; 
	xe *p,*q; // khai bao con tro p,q
	do{
		printf("nhap so xe , ket thuc enter:");
		fflush(stdin); // xoa ki tu thua
		gets(soxet); // nhap chuoi
		if (strcmp(soxet,"\0")!=0){
			p = new xe; // cap phat bo nho cho con tro p
			strcpy(p -> soxe,soxet); // ham tra ve con tro toi chuoi dich (tam)
			printf("nhap loai xe:");
			fflush(stdin);
			gets(p->loaixe); // nhap cac phan tu trong dsloaixe
			printf("nhap hieu xe:");
			fflush(stdin);
			gets(p->hieuxe);// nhap cac phan tu trong ds hieuxe
			p -> tiep=NULL; 
			if (dsxe == NULL)
				dsxe = p;
				else{
				q -> tiep = p;
				q=p;
				}
		}
	}
	while(strcmp(soxet,"\0")!=0); // so sanh hai chuoi tam va chuoi rong 
}
void nhapcon(con *&dscon){
	char tam[5];
	con *p,*q;
	do {
		printf("nhap maNK:");
		fflush(stdin);
		gets(tam);// nhap chuoi
		if (strcmp(tam,"\0")!=0){
			p = new con; // cap phat bo nho cho con tro p
			strcpy(p -> maNK,tam); // ham tra ve con tro p toi chuoi dich
			printf("nhap ho ten con:");
			fflush(stdin); // xoa ki tu thua
			gets(p->hotencon); 
			printf("nhap gioi tinh:");
			fflush(stdin);
			gets(p->gioitinh);
			p -> sau=NULL; 
			if (dscon == NULL)
				dscon = p;
				else{
				q -> sau = p;
				q=p;}
		}
	}
	while(strcmp(tam,"\0")!=0);
}
void nhaphokhau(hokhau *& dslk){
	char tam[5];
	hokhau *p,*q;
	do{
		printf("nhap so ho khau,enter->dung :");
		fflush(stdin);// xoa ki tu thua
		gets(tam); // nhap chuoi
		// strcmp : ham so sanh 2 chuoi
		// \0 : la ki tu rong
		if(strcmp(tam,"\0")!=0){
			p = new hokhau;
			// strcpy : ham tra ve con tro toi chuoi dich (tam)
			strcpy(p -> soHK,tam);// arrow (->) truy cap cac thanh vien trong ds sohk bang cong tro p 
			printf("ho ten chu ho:");
			gets(p->tenchuho);
			fflush(stdin);
			printf("dia chi:");
			gets(p->diachi);
			p->dsxe = NULL;
			nhapxe(p->dsxe);
			p->dscon = NULL;
			nhapcon(p->dscon);
			p->ke=NULL;
			if( dslk== NULL)
					dslk = p;
				else{
					q->ke = p;
					q=p;
				}
			}
		}
		while(strcmp(tam,"\0")!=0);
	}
	void hienthixe(xe *dau){
		if(dau != NULL){
		
		printf("so xe:");
		puts(dau->soxe);
		fflush(stdin);
		printf("loai xe:");
		puts(dau->loaixe);
		fflush(stdin);
		printf("hieu xe:");
		puts(dau->hieuxe);
		}
	}
	void hienthicon(con *dau){
		if(dau != NULL){
		fflush(stdin);
		printf("ho ten:");
		puts(dau->hotencon);
		fflush(stdin);
		printf("gioi tinh:");
		puts(dau->gioitinh);
		}
	}
void inds(hokhau *dau){
			printf("soHK :");
			puts(dau->soHK);
			fflush(stdin);
			printf("ho ten chu ho:");
			puts(dau->tenchuho);
			fflush(stdin);
			printf("dia chi:");
			puts(dau->diachi);
			fflush(stdin);
			printf("\n");
			printf("ds xe:");
			printf("\n");
			hienthixe(dau->dsxe);
			printf("\n");
			printf("ds con:");
			printf("\n");
			hienthicon(dau->dscon);
		}
int DemXe(xe *dsxe, char h[30])
{
	if (dsxe == NULL)
		return 0;
	else
		if( strcmp(dsxe->hieuxe,h) == 0)
			return 1 + DemXe(dsxe->tiep,h);
		else
			return DemXe(dsxe->tiep,h);
}
void timxe(hokhau *dslk, char h[30])
{
	if (dslk != NULL)
	{
		if (DemXe(dslk->dsxe,h) >= 1)
		{
			printf("soHK :");
			puts(dau->soHK);
			fflush(stdin);
			printf("ho ten chu ho:");
			puts(dau->tenchuho);
			fflush(stdin);
			printf("dia chi:");
			puts(dau->diachi);
			fflush(stdin);
			printf("\n");
			printf("ds xe:");
			printf("\n");
			hienthixe(dau->dsxe);
			printf("\n");
			printf("ds con:");
			printf("\n");
			printf("Thong tin con: ");
		}
		timxe (dslk->ke,h);
	}
}
void xoaxe(hokhau *dslk, char x[10], char y[10])
{
	hokhau *p;
	p = dslk;
	while ((p != NULL) && (strcmp(p->soHK,x) != 0))
	{
		p = p->ke;
	}
	if (p == NULL)
		printf("Khong tim thay ho can tim");
	else
	{
		xe *q, *t;
		q = p->dsxe;
		while ((q != NULL) && (strcmp(q->soxe,y) != 0))
		{
			t = q;
			q = q->tiep;
		}
		if (q == NULL)
			printf("Khong tim thay xe can tim");
		else
		{
			if (q == p->dsxe)
			{
				p->dsxe = q->tiep;
				delete q;
			}
			else
			{
				t->tiep = q->tiep;
				delete q;
			}
		}
	}
}

int main(){
	khoitao(dau);
	nhaphokhau(dau);
	printf("\n");
	printf("danh sach ho khau:");
	printf("\n");
	inds(dau);
	timxe(dau,"honda");
	xoaxe(dau,"234","fd");
	
}
