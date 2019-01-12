#include<iostream>
using namespace std;
void In(int a[5][5],int m , int n){
	int i;
	if(m==n)
		cout << a[n][n];
	else 
		for( i=m ; i<=n ; i++)
			cout << a[m][i] << " ";
		for(i=m+1 ; i<=n ;i++)
			cout << a[i][n] << " ";
		for(i = n-1 ; i>=m ; i--)
			cout << a[n][i] << " ";
		for(i=n-1 ; i>=m+1 ; i--)
			cout<< a[i][m] << " ";
		In(a,m+1,n-1);
}
int main(){
	int a[5][5]={1,2,3,4,5,
				16,17,18,19,6,
				15,24,25,20,7,
				14,23,22,21,8,
				13,12,11,10,9};
	cout << "Hinh xoan oc  cua ma tran la :";
	In(a,0,4);
	return 0;
}

