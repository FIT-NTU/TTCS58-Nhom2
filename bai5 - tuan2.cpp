#include <stdio.h>
#include <math.h>
#include <winbgim.h>
#include <iostream>
#include <string.h>

using namespace std;

int Mx, My;
class toado{

	protected:

		int x, y;

		friend class duong;

		friend class chunhat;

		friend class vuong;

		friend class tron;

		friend class tamgiac;

	public:

		void nhap(){

			cout<<endl<<"Toa do x: ";

			cin>>x;

			cout<<"Toa do y: ";

			cin>>y;

		}

};

class duong{

	private:

		toado d1,d2;

	public:

		void nhapduong(){

			cout<<"Toa do diem thu nhat: ";

			d1.nhap();

			cout<<"Toa do diem thu hai: ";

			d2.nhap();

		}

		void veduong(){			

			line(d1.x+Mx/2, -d1.y+My/2, d2.x+Mx/2, -d2.y+My/2);

		}

};

class chunhat{

	private:

		toado trentrai, duoiphai;

	public:

		void nhapchunhat(){

			cout<<"Toa do diem tren trai: ";

			trentrai.nhap();

			cout<<"Toa do diem duoi phai: ";

			duoiphai.nhap();

		}

		void vechunhat(){			

			rectangle(trentrai.x+Mx/2, -trentrai.y+My/2, duoiphai.x+Mx/2, -duoiphai.y+My/2);

		}

};

class vuong{

	private:

		toado trentrai, duoiphai;

	public:

		void nhapvuong(){

			do

			{

				cout<<"Toa do diem tren trai: ";

				trentrai.nhap();

				cout<<"Toa do diem duoi phai: ";

				duoiphai.nhap();

				if (abs(trentrai.x-duoiphai.x) != abs(trentrai.y-duoiphai.y))

					cout<<"Khong phai hinh vuong"<<endl;

			}

			while (abs(trentrai.x-duoiphai.x) != abs(trentrai.y-duoiphai.y));

		}

		void vevuong(){			

			rectangle(trentrai.x+Mx/2, -trentrai.y+My/2, duoiphai.x+Mx/2, -duoiphai.y+My/2);

		}

};

class tron{

	private:

		toado tam;

		int bankinh;

	public:

		void nhaptron(){

				cout<<"Toa do tam: ";

				tam.nhap();

				cout<<"Nhap ban kinh: ";

				cin>>bankinh;

		}

		void vetron(){			

			circle(tam.x+Mx/2,-tam.y+My/2,bankinh);

		}

};

class tamgiac{

	private:

		toado t1, t2, t3;

	public:

		void nhaptamgiac(){

				cout<<"Toa do diem thu nhat: ";

				t1.nhap();

				cout<<"Toa do diem thu hai: ";

				t2.nhap();

				cout<<"Toa do diem thu ba: ";

				t3.nhap();

		}

		void vetamgiac(){			

			line(t1.x+Mx/2, -t1.y+My/2, t2.x+Mx/2, -t2.y+My/2);

			line(t1.x+Mx/2, -t1.y+My/2, t3.x+Mx/2, -t3.y+My/2);

			line(t2.x+Mx/2, -t2.y+My/2, t3.x+Mx/2, -t3.y+My/2);

		}	

};

int main(){

	int chon;

	duong dt;

	tamgiac tg;

	chunhat cn;

	vuong v;

	tron t;

	initwindow(1280, 700);

    cleardevice();

    Mx = getmaxx(), My = getmaxy();
    
    cout<<"Nhap lua chon tuong ung de thuc hien ve hinh"<<endl;

    cout<<"1. Ve duong thang"<<endl;

    cout<<"2. Ve tam giac"<<endl;

    cout<<"3. Ve hinh chu nhat"<<endl;

    cout<<"4. Ve hinh vuong"<<endl;

    cout<<"5. Ve hinh tron"<<endl;

    cout<<"0. Ket thuc ve"<<endl;

    do

    {

	    cout<<endl<<"Nhap lua chon: ";

	    cin>>chon;

		switch(chon)

		{

			case 1:

				setcolor(13);

				dt.nhapduong();

				dt.veduong();

				break;

			case 2:

				setcolor(10);

				tg.nhaptamgiac();

				tg.vetamgiac();

				break;

			case 3:

				setcolor(9);

				cn.nhapchunhat();

				cn.vechunhat();

				break;

			case 4:

				setcolor(14);

				v.nhapvuong();

				v.vevuong();

				break;

			case 5:

				setcolor(12);

				t.nhaptron();

				t.vetron();

				break;

			case 0:

				break;

		}

		delay(1000);

	}

    while (chon != 0);	

    while(!kbhit()) delay(1);

    return 0;

}
