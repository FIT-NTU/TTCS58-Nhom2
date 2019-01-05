#include "BigNum.h"
#include<iostream>
#include<string>

using namespace std;

void BigNum::Nhap(){
	string str;
	getline(cin, str);
	n = str.size();
	for(int i = 0; i <= n -1 ; i++)
		data[i] = str.at(i) - '0';
	cout<<endl;
}

void BigNum::Xuat(){
	int dem = 0;
	for(int i = 0; i <= n-2; i++)
		if(data[i] == 0)	
			dem+=1;
		else 
			break;
	for(int i = dem; i <= n-1; i++)
		cout<<data[i];
	cout<<endl;
}


void BigNum::Cong(BigNum a, BigNum b){
	if(a.n > b.n)
		{
			n = a.n;
			for(int i = n - 1; i >= n - b.n; i--)
				b.data[i] = b.data[i - (n - b.n)];
			for(int i = 0; i < n - b.n; i++)
				b.data[i] = 0;
		}
	else
		{
			n = b.n;
			for(int i = n - 1; i >= n - a.n; i--)
				a.data[i] = a.data[i - (n - a.n)];
			for(int i = 0; i < n - a.n; i++)
				a.data[i] = 0;
		}
	int nho = 0, tg;
	for(int i = n - 1; i >= 0; i--)
		{
			tg = a.data[i] + b.data[i] + nho;
			nho = tg/10;
			tg = tg%10;
			data[i] = tg;
		}
	cout<<endl;
}

bool BigNum::KiemTra(BigNum a){
	if(n > a.n)
		return 1;
	if(n < a.n)
		return 0;
	else
		for(int i=0; i <= n -1; i++)
			{
				if(data[i] > a.data[i])
					return 1;
				if(data[i] < a.data[i])
					return 0;
			}
}

void BigNum::Tru(BigNum a, BigNum b){
	if(a.KiemTra(b) == 1)
		{
			n = a.n;
			if(a.n > b.n)
			{
				for(int i = n - 1; i >= n - b.n; i--)
					b.data[i] = b.data[i - (n - b.n)];
				for(int i = 0; i < n - b.n; i++)
					b.data[i] = 0;
			}

			int nho = 0;
			for(int i = n - 1; i >= 0; i--)
			{
				b.data[i] += nho;
				if(a.data[i] < b.data[i])
					{
						a.data[i] += 10;
						data[i] = a.data[i] - b.data[i]; 
						nho = 1;
					}
		
				else{
						data[i] = a.data[i] - b.data[i];
						nho = 0;
					}
			}
			cout<<endl;				
		}
	else
		{
			n = b.n;
			if(b.n > a.n)
			{
				for(int i = n - 1; i >= n - a.n; i--)
					a.data[i] = a.data[i - (n - a.n)];
				for(int i = 0; i < n - a.n; i++)
					a.data[i] = 0;
			}
			int nho = 0, tg;
			for(int i = n - 1; i >= 0; i--)
			{
				a.data[i] += nho;
				if(b.data[i] < a.data[i])
					{
						b.data[i] += 10;
						data[i] = b.data[i] - a.data[i]; 
						nho = 1;
					}
		
				else{
						data[i] = b.data[i] - a.data[i];
						nho = 0;
					}
			}
			for(int i = 0; i <= n -1; i++)
				if(data[i] != 0)
					{
						data[i] = data[i]*(-1);
						return;
					}
			cout<<endl;	
		}
}

void BigNum::Nhan(BigNum a, BigNum b){
	n = a.n + b.n;
	int *luu;
	luu = new int[n];
	for(int i = 0; i <= n-1; i++)
		luu[i] = 0;
	for(int i = a.n - 1; i >= 0; i--)
			for(int j = b.n - 1; j >= 0; j--)
				luu[i+j+1] += a.data[i] * b.data[j];
	for(int i = n-1; i >= 0; i--)
		if(luu[i] > 9)
			{
				luu[i-1] += luu[i]/10;
				luu[i] = luu[i]%10;
			}
	for(int i = 0; i <= n-1; i++)
		data[i] = luu[i];	
}
