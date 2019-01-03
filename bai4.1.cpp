#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
 
 
 //------------
 void chinhHeap(int *a, int n, int i){
		while(i <= n/2 - 1){
			int c1= 2*i +1;
			int c2 = 2*i + 2;
			int lc = c1;
			if (c2 < n && a[c2]> a[lc])
			 lc = c2;
			 if (a[i]< a[lc])
			 	swap(a[i], a[lc]);
			 	i = lc;
		}
 }
 //-----------------
 void xayHead(int *a, int n){
 	for (int i= n/2 -1; i >= 0; i--)
 		chinhHeap(a,n,i);
 }
 //------------
 void HeadSort(int *a, int n){
 	xayHead(a,n);
 	for (int i = n -1; i >=0; i--){
 		swap(a[0], a[i]);
 		chinhHeap(a,i,0);
	 }
 }
void ngaunhien(int a[], int &n){
	cout << "nhap so phan tu: ";
	cin >> n;
	for (int i = 0; i <n; i++){
		do {
			a[i]= rand()%51;
		}while(a[i] == 0);
	}

}
void xuat(int a[], int n){
	for(int i = 0; i < n; i++){
		cout << a[i]<<"\t";
	}
}
 int main(){
 	int a[100];
 	int n;
 	ifstream infile;
 	infile.open("F:\\bai4.txt");
 	infile >> n;
 	cout<< n <<endl;
 	for (int i = 0; i < n; i++){
	 
 		infile >> a[i];
 		cout << a[i] << "\t";}
 	infile.close();
// 	ngaunhien(a,n);
// 	xuat(a,n);
	cout << "\n---------------";
 	cout << "\nkhi chua sap xep:\n ";
 	xayHead(a,n);
 	xuat(a,n);
 	cout << "\n------------------";
 	cout << "\nda sap xep xong:\n ";
 	HeadSort(a, n );
 	xuat(a,n);
 }
