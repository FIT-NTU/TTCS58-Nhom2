#include<iostream>
using namespace std;
#include<math.h>
#include<fstream>
 struct Co{
 	int tren;
 	int duoi;
 };
 Co a[29]; //du lieu luu cac quan co
 int tt[29];//trang thai cac quan co
 int n; // so quan co
 int ttluu[29];//luu trang thai
 int cl=168;
 // nhap cac quan co
 void Nhap(int &n){
 	cout << "Nhap so luong co: ";
 	cin >> n;
 	for( int i =1;i<=n;i++){
 		cout << "Nhap quan co thu :" <<i<<endl;
 		cout << "Nhap tren: ";
 		cin >>a[i].tren;
 		cout << "Nhap duoi: ";
 		cin >>a[i].duoi;
	 }
 }
 void Xuat(int &n){
 	for( int i =1;i<=n;i++){
 		cout << a[i].tren;
 		cout << ":";
 		cout << a[i].duoi << "   ";
	 }
 }
  void kt(){
  	int sumt=0, sumd = 0;
  	int k;
 	for(int k=1;k<=n;k++){
 		if(tt[k]=0){
 			sumt=sumt+a[k].tren;
 			sumd=sumd+a[k].duoi;
 		}
		 else{
		 	sumt=sumt+a[k].duoi;
		 	sumd=sumd+a[k].tren;	
		}
	 }
	 int dochenh=abs(sumt-sumd);
	 if(dochenh < cl)
	 	cl=dochenh;
	 	for(k=1;k<=n;k++)
	 		ttluu[k]=tt[k];
}
 void Thu(int i){
 	for(int k=0;k<=1;k++){
		tt[i]=k;
			if(i<n) Thu(i+1);
			else 
				kt();
				tt[i]=0;
	 }
 }
 void KQ(){
 	int k;
 	int dem=0;
 	cout << "Do lech be nhat: "<< cl<<endl;
 	//so luong quan co phai xoay
 	for(k=0;k<=n;k++)
 		if (ttluu[k]==1) dem=dem+1;
 	cout << "So luong quan co phai xoay:"<<dem<<endl;
 	cout << "Trang thai tuong uong voi do lech ve nhat:"<<endl;
 	for (k=1;k<=n;k++)
 		cout << ttluu[k];
 }
 int main(){
// 	Nhap(n);
// 	cout <<"Cac quan co da nhap:";
// 	Xuat(n);
// 	Thu(1);
// 	KQ();
 }
 
