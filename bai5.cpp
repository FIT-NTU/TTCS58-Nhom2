#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<fstream>

struct co{
	int tren,duoi;
};

co a[29];// luu tru co
int tt[29];// trang thai co
int ttluu[29];// luu trang thai cac quan co


int n; // so quan co su ly
int cl=168;// do chenh lech quan co

//-------------------
void nhapco(int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("\nNhap quan co thu %d:",i);
		printf("\n Nhap mat tren:");
		scanf("%d",&a[i].tren);
		printf("\n Nhap mat duoi:");
		scanf("%d",&a[i].duoi);
	}
}
//-------------------------------



void ktra()
{
	int k;
	int docl ;
	int sumt=0,sumd=0;
	for(k=1;k<=n;k++)
	{
		if(tt[k]==0)
		{
			sumt += a[k].tren;
			sumd += a[k].duoi;
		}
		else
		{
			sumt += a[k].duoi;
			sumd += a[k].tren;
		}
		docl = abs(sumt- sumd );
		if(cl > docl)
		{
			cl=docl;
			for(k=1;k<=n;k++)
			{
				ttluu[k]=tt[k];
			}
		}	
	}
	
}
//------------------------------
void kqua()
{
	int dem=0;
	printf("\nDo lech be nhat: %d",cl);
	for(int i=1;i<=n;i++)
	{
		if(ttluu[i]==1)
			dem++;
	}
	printf("\nSo luong quan co phai quay:%d",dem);
	printf("\nTrang thai ung voi do lech be nhat \n");
		for(int k=1;k<=n;k++)
			printf("%d",ttluu[k]);

}
//------------------------------

void thu(int i)
{
	int k;
	for(k=0;k<=1;k++)
	{
		tt[i]=k;
		if(i<n)
			thu(i+1);
		else 
			ktra();
		tt[i]=0;
	}
}

//------------------------------------
int main()
{
//	ifstream infile;
//	infile.open("D:\thuctapcoso\input.txt");
//	
	printf("\n Nhap so luong quan co:");
	scanf("%d",&n);
	nhapco(n);
	thu(1);
	kqua();
	getch();
}
