#include<iostream>
using namespace std;
#include<stdlib.h>
#include <stdio.h>
#include <conio.h>
void Taongaunhien(int a[],int &n){
	int tam;
	cout << "Nhap so phan tu ngau nhien: ";
	cin >> n;
	for(int i=0;i<n;i++)
		do{
		a[i]= rand()%51;
		}while (tam == 0);
}
void Nhap(int a[], int &n){
	cout << "Nhap so phan tu mang:";
	cin >> n;
	for (int i=0;i<n;i++){
		cout << "Nhap phan tu thu " << i << ":" ;
		cin >> a[i];
	}
}
void Xuat(int a[], int n){
	for (int i=0 ; i<n ; i++){
		 cout << a[i]<<"\t";
	}
}
//--------------
void chinhHeap(int a[], int n, int cha){
	while (cha <= n/2 - 1){//dk dung cua cha
		int ct = 2*cha +1 ;
		int cp = 2*cha + 2;
		int tam = ct;
		if (cp < n && a[cp] > a[tam])
			tam = cp;
		if (a[cha]< a[tam])
		
			swap(a[cha],a[tam]);
			cha = tam;
	}
}
//--------------
int main(){
	int a[100];
	int n;
	Nhap(a,n);
	cout << "Mang vua nhap la: ";
	Xuat(a,n);
	cout << endl;
	Taongaunhien(a,n);
	cout << "Mang ngau nhien la: ";
	Xuat(a,n);
}

