#include <iostream> 
#include <iostream> 
#include <cstdlib> 
#include <ctime> 
using namespace std;

int main()
{
	int m,n;
	cout<<"nhap m:";
	cin>>m;
	int a[m];// mang co m phan tu
	do{
		cout<<"nhap n:";
		cin>>n;
	}while(n<1 || n>m);// nhap n so ngau nhiên tu 1 den m (n<m)
	// nhap nhau nhien n so;

	srand(time(0));//tao so ngau nhien khong trung lap
	for(int i=0;i<n;i++)
	{	
		a[i] = 1+ rand()%(m);// nhap so nau nhien voi so tu nhien tu 1->m ,1+...%(m)
	}
	//ham xuat mang
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
    system("pause");
    return 0;
}
