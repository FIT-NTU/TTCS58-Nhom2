# include <stdio.h>
# include <iostream>
# include <string.h>
# include <vector>
# include <fstream>
# include <stdlib.h>
# include <math.h>
# include <conio.h>
# include <Windows.h>
# include <sstream>
using namespace std;
fstream f("input3-2.txt");
struct O{
	char gt[10];
	int vt;
};
void ResizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void GotoXY(short x,short y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x,y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
class Nhanvien{
	private:
		string Maso, Hoten, chucvu;
		int hesoluong, hesochucvu, thang, nam;
		int luongcb;
		friend class DSNV;
	public:
		void Nhap()
		{
			string s;
		    string line;		
		    stringstream ss;	
		    getline(f, line);
		    ss.str(line);
			getline(ss, s,'\t'); Maso = s;
			getline(ss, s,'\t'); Hoten = s;
			getline(ss, s,'\t'); hesoluong = atoi(s.c_str());
			getline(ss, s,'\t'); chucvu = s;
			getline(ss, s,'\t'); hesochucvu = atoi(s.c_str());
			getline(ss, s,'\t'); thang = atoi(s.c_str());
			getline(ss, s,'\t'); nam = atoi(s.c_str());
			luongcb = 10000;
		}
		int Luong()
		{
			return luongcb * (hesoluong + hesochucvu);
		}
		void Xuat()
		{
			cout<<Maso<<" "<<Hoten<<" "<<hesoluong<<" "<<chucvu<<" "<<hesochucvu<<" "<<thang<<" "<<nam<<endl;
			cout<<"Luong: "<<Luong()<<endl;
		}
		
};
class DSNV{
	public:
		int n;
		vector <Nhanvien> dsnv;
	public:
		void NhapDS()
		{
			if (f.fail())
				cout << "Failed to open this file!" << endl;
			else
			{
				string s;
				getline(f, s); n = atoi(s.c_str());
				dsnv.resize(n);
				for (int i = 0; i < dsnv.size(); i++)
					dsnv[i].Nhap();
			}
		}
		void XuatDS()
		{
			for (int i = 0; i < dsnv.size(); i++)
			{
					dsnv[i].Xuat();
					cout<<endl;
			}
		}
		void Sapxepluong()
		{
			for (int i = 0; i < dsnv.size() - 1; i++)
				for (int j = i + 1; j < dsnv.size(); j++)
					if (dsnv[i].Luong() > dsnv[j].Luong())
						swap (dsnv[i],dsnv[j]);
		}
		void Timkiem ()
		{
			string ms;
			cout<<"Nhap ma so nhan vien can tim: ";
    		getline(cin, ms);
			for (int i = 0; i < dsnv.size(); i++)
				if (dsnv[i].Maso == ms)
				{
					dsnv[i].Xuat();
					break;
				}
		}
		void Xoa()
		{
			string ms;
			cout<<"Nhap ma so nhan vien can xoa: ";
    		getline(cin, ms);
    		for (int i = 0; i < dsnv.size(); i++)
				if (dsnv[i].Maso == ms)
				{
					dsnv.erase(dsnv.begin() + i);
					n--;
					break;
				}
		}
};
//Tao cac nut lenh
void Khoitao (O dso[5])
{
	strcpy(dso[0].gt,"Nhap");
	dso[0].vt = 0;
	strcpy(dso[1].gt,"Xuat");
	dso[1].vt = 1;
	strcpy(dso[2].gt,"Sap xep");
	dso[2].vt = 2;
	strcpy(dso[3].gt,"Tim kiem");
	dso[3].vt = 3;
	strcpy(dso[4].gt,"Xoa");
	dso[4].vt = 4;
}
//Hien thi cac nut lenh
void display (O dso[5], int k)
{
	GotoXY(10,1);
		for (int i = 0; i < 5; i++){
			if (dso[i].vt == k)
				SetColor(12);
			else
				SetColor(9);
			cout<<"    "<<dso[i].gt<<"    ";
		}
}
int main() {
	ResizeConsole(1280,600);
	O dso[5];
	Khoitao(dso);	
	int k = 0;	//Xem con tro dang chi vao nut lenh nao
	char c;
	DSNV ds;
	int x = 0, y = 3;	//Vi tri toa do hien tai cua con tro
	int ktds = 0;	//Bien kiem tra nhap danh sach chua, neu chua thi 0, neu roi thi 1
	do
	{
		SetBGColor(10);
		display(dso,k);
        c = getch();
        if(c == -32){
            c = getch();
            switch (c)
            {
            	case 77:	//Mui ten phai
            		k = (k+1)%5;
            		break;
            	case 75:	//Mui ten trai
            		k = (k-1)%5;
            		if (k < 0)
            			k = k + 5;
            		break;           	
			}          
        }
        else
        	if (c == 13)	//Phim enter de thuc hien nut lenh
        	{
            	SetBGColor(0);
            	SetColor(15);
				if (k == 0)
				{
					ds.NhapDS();
					ktds = 1;
					f.seekg(0,ios::beg);	//Sau khi nhap xong dua con tro file ve dau file de co the ghi de du lieu trong file vao lai
				}					
				if (k == 1)
				{
					GotoXY(x,y);
					if (ktds == 1)
					{
						ds.XuatDS();
						y += ds.n*3 + 2;
					}					
				}
				if (k == 2)
				{
					if (ktds == 1)
						ds.Sapxepluong();
				}
					
				if (k == 3)	
				{
					GotoXY(x,y);
					if (ktds == 1)
					{
						ds.Timkiem();
						y += 5;
					}					
				}
				if (k == 4)
				{
					GotoXY(x,y);
					if (ktds == 1)
					{
						ds.Xoa();
						if (ds.n == 0)		//Da xoa het danh sach
							ktds = 0;
						y += 4;
					}												
				}
			}
    }
    while(c != 27);		//Ket thuc chuong trinh khi nhan esc
    GotoXY(x,y);
	SetColor(15);
	SetBGColor(0);	
}
