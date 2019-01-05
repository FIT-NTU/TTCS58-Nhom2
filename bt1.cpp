#include<conio.h>
#include<iostream>
#include<fstream>
using namespace std;

int B[10][10] = 
{
	4,	7,	8,	9,	6,
	7,	5,	6,	3,	2,
	4,	8,	9,	5,	2,
	1,	5,	7,	8,	9,
	7,	8,	5,	6,	4,
};

void NhapMang(int n, int a[10][10]){
	for(int i = 0; i < n; i++)
		for(int j = 0; j< n; j++)
			{
			cout<<"Nhap vao phan tu A["<<i+1<<"]["<<j+1<<"]: ";
			cin>>a[i][j];
			}
}

void InXoanOc(int n, int a[10][10]){
	int d = 0, hang = n -1 , cot = n-1 ;
	while(d<=n/2)
	{
		for(int i = d; i <= cot; i++)
			cout<<a[d][i]<<"   ";
		for(int i = d+1; i <= hang; i++)
		 cout<<a[i][cot]<<"   ";
		for(int i = cot - 1; i >= d; i--)
		{
			cout<<a[hang][i]<<"   ";
		}	
		for(int i = hang - 1; i > d; i--)
			cout<<a[i][d]<<"   ";
		d++; hang--; cot--;
	}
}

void InXOFile(int n, int A[10][10]){
	int d = 0, hang = n -1 , cot = n-1 ;
	ofstream matrix;
	matrix.open("kqbt1.txt");
	matrix<<"    MA TRAN "<<endl;
	for(int i = 0; i < n; i++)
		{
		for(int j = 0; j< n; j++)
			{
				matrix<<A[i][j];
				matrix<<"   ";
			}
		matrix<<endl;
		}
	matrix<<endl<<"OUTPUT theo hinh xoan oc: ";
	while(d<=n/2)
	{
		for(int i = d; i <= cot; i++)
			matrix<<A[d][i]<<"   ";
		for(int i = d+1; i <= hang; i++)
		 matrix<<A[i][cot]<<"   ";
		for(int i = cot - 1; i >= d; i--)
		{
			matrix<<A[hang][i]<<"   ";
		}	
		for(int i = hang - 1; i > d; i--)
			matrix<<A[i][d]<<"   ";
		d++; hang--; cot--;
	}
	matrix.close();
}

void inmang(int n, int a[10][10]){
	for(int i = 0; i < n; i++)
		{
		for(int j = 0; j< n; j++)
			cout<<"   "<<a[i][j]<<"   ";
		cout<<endl;
		}
}

int main(){
	int n, m, A[10][10], C[10][10],hang = 0, cot = 0, data;
	ifstream matrix;
	matrix.open("bt1.txt");
	matrix>>data;
	n = data;
	for(int i = 0; i< n*n; i++)
		{
			matrix>>data;
			A[hang][cot] = data;
			if(cot == n - 1)	{
				hang++;
				cot = 0;
			}
			else cot++;
		
		}
	matrix.close();
	ofstream matrixx;
	matrix.open("bt1.txt");
	matrixx<<endl<<"OUTPUT theo hinh xoan oc: ";
	matrixx.close();
	InXOFile(n, A);
	cout<<"In File thanh cong!!!"<<endl;
	cout<<"Nhap cap ma tran: ";
	cin>>m;
	NhapMang(m, C);
	cout<<"  MA TRAN VUA NHAP"<<endl;
	inmang(m, C);
	cout<<"OUPUT theo hinh xoan oc "<<endl;
	cout<<"Du lieu nhap tu ban phiem: ";
	InXoanOc(m, C);
	cout<<endl<<"Du lieu co san: ";
	InXoanOc(5, B);
	
	getch();
}
