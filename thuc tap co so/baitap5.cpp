#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

struct co{
	int tren,duoi;
};

co a[29]; // du lieu cac quan co
int tt[29]; // trang thai cac quan co
int ttluu[29]; // trang thai luu cac quan co

int n; // so quan co can xu ly;
int cl = 168;

void NhapCo(int &n){
	int i;
	do{
	cout<<"Nhap so luong quan co: ";
	cin>>n;
	}while(n < 1 || n > 20);
	for( i = 0 ; i < n ; i++){
		cout<<"\n Quan co thu :";
		cin>>i;
		cout<<"\n Mat tren : ";
		cin>>a[i].tren;
		cout<<"\n Mat duoi: ";
		cin>>a[i].duoi;
	}
}
void XuatCo(int &n){
	cout<<"Tong so quan co:"<<n;
	for(int i = 1;i <= n; i++){
		cout<<"\n quan co thu: "<<i;
		cout<<"\n Quan co phia tren: "<<a[i].tren;
		cout<<"\n Quan co phia duoi: "<<a[i].duoi;
	}
}
int ktra(){
	int k;
	int sumt = 0;
	int sumd = 0;
	int dochech = 0;
	for(k = 1; k <= n;k++){
		if(tt[k] == 0){
			sumt += a[k].tren;
			sumd += a[k].duoi;
		}
		else{
			sumt += a[k].duoi;
			sumd += a[k].tren;
		}
	}
	return sumt;
	return sumd;
	dochech = abs(sumt - sumd);
		if(dochech < cl){
			cl = dochech;
			for(k = 1; k <= n ; k++)
			ttluu[k] = tt[k];
		}
}
void thu(int i){
	int k;
	for(k = 0; k<= 1;k++){
		tt[i] = k;
		if(i < n) thu(i+1); //kiem tra i co nho hon n, neu dung ktra phan tu tiep theo; 
		else
			ktra(); // 
			tt[i] = 0;
	}
}
void ketqua(){
	int k;
	int dem = 0;
	cout<<"\n Do lech be nhat: "<<cl;
	//so luong quan co phai xoay;
	for(k = 1; k <= n; k++){
		if(ttluu[k] == 1)
		dem += 1;
	}
	cout<<"\n So luong quan co can phai xoay: "<<dem;
	cout<<"\n Trang thai ung voi do lech be nhat: ";
	for(k = 1; k <= n;k++)
	cout<<ttluu[k];
}
int main(){
	int n,i;
	FILE *f = fopen("dominobt5.txt","rt");
	fscanf(f,"%d",&n);
	for(int i = 1; i <= n ; i++){
		fscanf(f,"%d",&a[i].tren);
		fscanf(f,"%d",&a[i].duoi);
	}
	XuatCo(n);
	thu(i);
	ketqua();
	
	
}
