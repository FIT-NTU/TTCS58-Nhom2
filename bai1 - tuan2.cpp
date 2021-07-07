#include<stdio.h>
#include<stdlib.h>
void nhapmang(int a[100][100],int n1,int n2){
	for (int i=0;i<n1;i++)
		for (int j=0;j<n2;j++)
			{
				a[i][j]=0+rand()%100;
			}
	
}
void xuatmang(int a[][100],int n1,int n2)
{
	for (int i=0;i<n1;i++)
		{
			for (int j=0;j<n2;j++)
			{
				printf("%4d",a[i][j]);
				
			}
				printf("\n");
		}
}
void xoadongi(int a[][100],int n1,int n2)
{
		int d;
 		printf("xoa dong thu : ");
 		scanf("%d",&d);
 		for (int i=d;i<n1;i++)
 			for (int j=0;j<n2;j++){
 				a[i][j]=a[i+1][j];
 			}
 			n1--;
 		xuatmang(a,n1,n2);
}
void xoacotj(int a[][100],int n1, int n2){
	int c;
	printf("xoa cot thu :");
	scanf("%d",&c);
	 		for (int i=0;i<n1;i++)
 				for (int j=c;j<n2;j++){
 					a[i][j]=a[i][j+1];
 				}
 			
 					n2--;
 		
 				xuatmang(a,n1,n2);
}
int sohoanghau (int a[][100], int n1, int n2, int vtd, int vtc)

{

	int x = a[vtd][vtc];

	//Kiem tra lon nhat tren cot

	for (int i = 0; i < n1; i++)

		if (a[i][vtc] > x)

			return 0;

	//Kiem tra lon nhat tren hang

	for (int j = 0; j < n1; j++)

		if (a[vtd][j] > x)

			return 0;

	//Kiem tra lon nhat tren duong cheo chinh

	int vtd1 = vtd + 1;

	int vtc1 = vtc + 1;

	while (vtd1 < n1 && vtc1 < n2)

	{

		if (a[vtd1][vtc1] > x)

			return 0;

		vtd1++;

		vtc1++;

	}

	vtd1 = vtd - 1;

	vtc1 = vtc - 1;

	while (vtd1 >= 0  && vtc1 >= 0)

	{

		if (a[vtd1][vtc1] > x)

			return 0;

		vtd1--;

		vtc1--;

	}

	//Kiem tra lon nhat tren duong cheo phu

	vtd1 = vtd + 1;

	vtc1 = vtc - 1;

	while (vtd1 < n1  && vtc1 >= 0)

	{

		if (a[vtd1][vtc1] > x)

			return 0;

		vtd1++;

		vtc1--;

	}

	vtd1 = vtd - 1;

	vtc1 = vtc + 1;

	while (vtd1 >= 0  && vtc1 < n2)

	{

		if (a[vtd1][vtc1] > x)

			return 0;

		vtd1--;

		vtc1++;

	}

	return 1;

}

void dshoanghau (int a[100][100], int n1, int n2)

{


	for (int i = 0; i < n1; i++)

		for (int j = 0; j < n1; j++)

			if (sohoanghau(a,n1,n2,i,j) == 1)

			{

				printf("%d",a[i][j]);

			}

}
void ghiketqua(int a[][100],int n1,int n2)
{
    FILE *f;
    f=fopen("D:/58131283-tuan2/output1.txt","wt");
    for(int i = 0 ; i < n1 ; i++)
    	for (int j = 0 ; j < n2 ; j++)
    	if (sohoanghau(a,n1,n2,i,j) == 1)

			{

				fprintf(f,"%3d",a[i][j]);

			}
    fclose(f);
}
int main(){
	int a[100][100],n1,n2;
	while(n1<3||n1>10&&n2<3||n2>10){
	printf("nhap so dong n1 :");
	scanf("%d",&n1);
	printf("\nnhap so cot n2 :");
	scanf("%d",&n2);
	}
	nhapmang(a,n1,n2);
	printf("mang truoc la : \n");
	xuatmang(a,n1,n2);
	printf("so hoang hau  la:");
	sohoanghau(a,n1,n2,1,3);
	ghiketqua(a,n1,n2);
	//printf("\nmang xoa dong :\n");
	//xoadongi(a,n1,n2);
	printf("\nmang xoa cot :\n");
	xoacotj(a,n1,n2);
	
}
