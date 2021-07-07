#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//---------------------------------//
void hoanvi(int a,int b){
	int c;
	c=a;
	a=b;
	b=c;
}
void taomangngaunhien(int a[100],int n){
	for (int i=0;i<n;i++)
	a[i] = 1+rand()%10;
}
void xuatmang(int a[],int n){
	for (int i=0;i<n;i++)
	printf("%5d",a[i]);
}
void chinhheap(int a[100],int n,int i){
	
	while(i<=n/2-1){
		int c1 = 2*i+1;
		int c2 = 2*i+2;
		int max = c1;
		if ((c2<n )&& (a[c2]>a[max])) 
		max = c2;
		if (a[i]<a[max]){
		hoanvi(a[i],a[max]);
		i=max;
		}
			
	}

}
void xayheap(int a[100],int n){
	for (int i=n/2-1;i>=0;i--)
		
		chinhheap(a,n,i);
}

void heapsort(int a[100],int n){
	xayheap(a,n);
	for (int i=n-1;i>0;i--){
		hoanvi(a[0],a[i]);// hoan doi phan tu cuoi voi phan tu dau
		chinhheap(a,i,0); 
	}
}

//--------------------------------//
int main(){
	int a[100],n=10;
	printf("mang truoc :");
	taomangngaunhien(a,n);
	xuatmang(a,n);
	printf("\n");
	printf("mang sau :");
	heapsort(a,n);
	xuatmang(a,n);
	
}


