#include "BigNum.h"
#include<iostream>
#include<conio.h>

using namespace std;
BigNum a, b, c;
int chon, x;
int main(){
    do
    {
        system("cls");
        cout<<("\t\t\t 1. Nhap so nguyen A B\n");
        cout<<("\t\t\t 2. A + B\n");
        cout<<("\t\t\t 3. A - B\n");
        cout<<("\t\t\t 4. A*B\n");
        cout<<("\t\t\t 5. Thoat\n");
        cout<<("Ban chon: ");
        cin>>(chon);
        switch(chon)
        {
            case 1:
            	cout<<"Nhap so nguyen A: ";
            	fflush(stdin);
             	a.Nhap();
            	cout<<"Nhap so nguyen B: ";
            	fflush(stdin);
                b.Nhap();
                break;
            case 2:
 				c.Cong(a, b);
 				cout<<"A + B = ";
 				c.Xuat();
                break;
            case 3:
 				c.Tru(a, b);
 				cout<<"A - B = ";
 				c.Xuat();
                break;
            case 4:
    			c.Nhan(a, b);
				cout<<"A * B = ";
    			c.Xuat();
                break;
            case 5:
                break;
            default:
                printf("Ban chon sai. Moi ban chon lai\n");
                break;
        }
        getch();
    }while(chon!=5);
}
