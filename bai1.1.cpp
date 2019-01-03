#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int NhapMang(int n, int a[][10]){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << "nhap: a["<<i<<"]["<<j<<"]= ";
			cin >> a[i][j];
		}
	}
}
int XuatMang(int n, int a[][10]){
	for (int i = 0; i < n; i++){
		cout << "\n";
		for (int j = 0; j < n; j++){
			cout <<"\t" << a[i][j];
		}
	}
}
int Xoanoc(int n, int a[][10]){
	int d = 0,gt = 1 ,cot = n-1, hang = n-1;
	while(d <= n/2){
			for (int i = d; i <= cot; i++ ){
				cout << a[d][i]<<"\t";
			}
			for(int i = d + 1; i<= hang; i++){
				cout<< a[i][cot]<<"\t";
			}
			for(int i = cot - 1 ; i >= d ; i--){
				cout<< a[hang][i]<<"\t";
			}
			for( int i = hang - 1 ; i > d; i--){
				cout<< a[i][d]<<"\t";
			}
			d++;
			cot--;
			hang--;
		}
	}

int main(){
//	int n;
//	int a[10][10]= {
//		{10,5,6,4,7},
//		{2,9,8,6,3},
//		{8,10,5,7,8},
//		{11,7,9,12,6},
//		{12,9,10,11,10}
//	};
//	cout << "nhap n: ";
//	cin >> n;
////	NhapMang(n, a);
////	XuatMang(n,a);
//	cout<<"\n------------------------\n";
	ifstream  f;
	f.open("F:\\file.txt");
	int a[10][10];
	int n;
	 f >> n;
	 cout <<n<<endl;
	for (int i = 0; i <n; i++){
		for(int j = 0; j < n; j++){
			f >> a[i][j];
			cout << "\t"<< a[i][j];
		}
		cout << endl;
	}
	f.close();
	cout <<endl;
	Xoanoc(n,a);
}
