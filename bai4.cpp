#include <iostream>
#include  <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void nhapmang(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("nhap vao ptu thu a[%d]:",i);
		scanf("%d",&a[i]);
	}
}
void nhaprand(int a[], int n)
{
	for(int i=0;i<n;i++)
	do
	{
		a[i]=rand()%51;
	}while(a[i]==0);
}
void xuatmang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
//----------------------------------
void hoanvi(int &a,int &b)
{
	int tam;
	tam = a;
	a=b;
	b=tam;
}
//--------------------------------------
void chinhheap(int a[], int n, int i)
{
	int L=2*(i+1)-1;
	int R=2*(i+1);
//	int L=2*(i)+1;
//	int R=2*(i) +2;
	int tami=i;
//	cout << "tam1: "<< tami << " " << endl;	
	if(L<n&&a[i]<a[L])
		tami = L;	
	if(R<n&&a[tami]<a[R])
		tami = R;
//	cout << "left: " << a[L] << endl;
//	cout << "tam1: "<< tami << " " << endl;	

	if(i!=tami)
	{
		hoanvi(a[i],a[tami]);
		chinhheap(a,n,tami);
	}	
}
//------------------------------------
void xaycay(int a[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		chinhheap(a,n,i);
	}
}
//-----------------------
void heapsort(int a[],int n)
{
	xaycay(a,n);
	
	for(int i =n-1;i>0;i--)
	{
		swap(a[0],a[i]);
		chinhheap(a,i,0);
	}
}

//--------------------------------
int main()
{
	int a[100];
	int n;
	printf("nhap so phan tu:");
	scanf("%d",&n);
//	nhapmang(a,n);
	nhaprand(a,n);
	xuatmang(a,n);
//	printf("\n xay cay:\n");
//	xaycay(a,n);
	//chinhheap(a, n, 1);
	//xuatmang(a,n);
	heapsort(a,n);
	printf("\n mang sau keu heapsort:\n");
	xuatmang(a,n);
}
