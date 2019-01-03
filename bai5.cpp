#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;


struct co {
	int tren, duoi;
};
//---------- du lieu luu cac con co aaaaaaaaaaaaaaaaaaaa
co a[29];

//------------------- trang thai cac con co 0 or 1
int tt[29];
int ttluu[29]; //------- luu tt cac con co
//---------------- so luong con co can xu ly

int n;
int cl = 168;//--- chenh lech cao nhat
//-----------

void nhapco(int &n){
		int i;
		printf ("\n nhap so luong quan co: ");
		scanf("%d", &n);
		for (i = 1; i<= n ; i++){
			printf ("\n quan co thu %d: \n", i);
			printf ("\nmat tren: ");
			scanf("%d", &a[i].tren);
			printf("\nmat duoi: ");
			scanf("%d", &a[i].duoi);
		}
}
//-------------------------

//------------------
void ktra(){
	int sumt = 0, sumd = 0;
	int dochenh;
	int k;
	for (k = 1; k<=n; k++){
	
		if (tt[k]== 0)
		{
			sumt = sumt + a[k].tren;
			sumd = sumd + a[k].duoi;
		}
		else
		{
			sumt = sumt + a[k].duoi;
			sumd = sumd + a[k].tren;
	}	}
	dochenh = abs(sumt-sumd);
	if (cl > dochenh){
		cl = dochenh;
		for (k = 1; k <= n; k++){
			ttluu[k] = tt[k];
		}
	}
}
//--------------------
void kqua(){
	int k, dem = 0;
	for (k = 1; k <= n; k++){
		if (ttluu[k] == 1){
			dem++;
		}
	}
	printf ("\nso lan quay de duoc do chenh nho nhat : %d\n", dem);
	printf("\n do chenh nho nhat la: %d\n", cl);
	printf ("\n trang thai ung coi do lech be nhat: \n");
		for (k = 1; k <= n; k++)
		printf ("%d", ttluu[k]);
}
//-------------------------
void thu (int i){
	int k;
	for (k = 0 ; k <= 1; k++){
		tt[i] = k;
		if (i < n) thu(i +1);
		else
			ktra();
			tt[i] = 0;
}
}
int main(){
	ifstream infile;
	infile.open("F:\\input.txt");
		infile >> n;
		cout << n << endl;
		for (int i = 1; i <= n; i++){
		
			infile >> a[i].tren >>a[i].duoi;
			cout << endl;
			cout << a[i].tren<<"\t"<<a[i].duoi<<endl;
}
	infile.close();
	//nhapco(n);
//	ofstream outfile;
//		outfile.open("F:\\output.txt");
//		thu(1);
//		outfile <<kqua();
//		outfile.close();
	thu (1);
	kqua();
}

