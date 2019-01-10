#include "tvcau1.h"

int main() {
	int n, m;
	int a[100][100];
	Nhap (a,n,m);
	Xuat (a,n,m);	
	Xoacot (a,n,m);
	cout<<endl;
	Xuat (a,n,m);
	Xoadong (a,n,m);
	cout<<endl;
	Xuat (a,n,m);
	if (Doixung(a,n,m) == 1)
		cout<<"Ma tran doi xung"<<endl;
	else
		cout<<"Ma tran khong doi xung"<<endl;
	DSSoHoangHau(a,n,m);
}
