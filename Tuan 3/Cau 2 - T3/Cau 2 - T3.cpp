#include<stdio.h>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<conio.h>
#include<sstream>
#include<string.h>
using namespace std;
ifstream f("Ghichu.txt");
/*
	Ham dinh dang kich thuoc man hinh hien thi
	Input: width - chieu dai man hinh
		   height - chieu cao man hinh
*/
void ResizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
/*Ham xoa man hinh*/
void ClearScreen()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
/*
	Ham thiet lap mau chu
	Input: color - gia tri mau sac tu 0 -> 15
	Output: Nhung chuoi, so se duoc xuat ra man hinh se duoc to mau
*/
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
/*
	Ham thiet lap mau nen
	Input: color - gia tri mau sac tu 0 -> 15
	Output: Nhung chuoi, so se duoc xuat ra man hinh se co nen duoc to mau
*/
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
/*
	Ham di chuyen con tro toi vi tri tren man hinh
	Input: x - toa do theo truc Ox
		   y - toa do theo truc Oy
	Output: Con tro man hinh se di chuyen toi vi tri duoc xac dinh
*/
void GotoXY(short x,short y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x,y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

/*Khai bao kieu du lieu Ghichu*/
struct Ghichu{
	int ngay;
	int thang;
	int nam;
	string nd;
};
/*
	Ham doc du lieu ghi chu tu file
	Input: gc[] - mang chua cac ghi chu
	 	   n - so luong ghi chu
	Output: Gia tri cac ghi chu va so luong ghi chu duoc gan vao gc[] va n
*/
void DocFile (Ghichu gc[], int &n)
{
	string s;	
	int i = 0;
	while (!f.eof())
	{
		
		string line;		
		stringstream ss;
		getline(f, line);
		ss.str(line);		
		getline(ss,s,','); 	gc[i].ngay = atoi(s.c_str());
		getline(ss,s,',');  gc[i].thang = atoi(s.c_str());
		getline(ss,s,',');  gc[i].nam = atoi(s.c_str());
		getline(ss,s,',');  gc[i].nd = s;
		n++;
		i++;
	}	
}
/*
	Ham tinh nam nhuan
	Input: nam - nam can kiem tra
	Output: 1 neu la nam nhuan, 0 neu la nam khong nhuan
*/
int NamNhuan(int nam){
	 if (((nam % 4)==0) && ((nam % 100)!=0)){
	  return 1;
	 }else if ((nam % 400)==0){
	  return 1;
	 }else {
	  return 0;
	 }
}
/*
	Ham hien thi thang
	Input: thang - thang can xet
	Output: Xuat ra ten tieng Anh cua thang do va tra ve so luong ky tu ma ten thang chiem
*/
int Hienthithang (int thang)
{
	int khoang;
	switch(thang)
	{
		case 1:
			cout<<"January, ";
			khoang = 7;
			break;
		case 2:
			cout<<"February, ";
			khoang = 8;
			break;
		case 3:
			cout<<"March, ";
			khoang = 5;
			break;
		case 4:
			cout<<"April, ";
			khoang = 5;
			break;
		case 5:
			cout<<"May, ";
			khoang = 3;
			break;
		case 6:
			cout<<"June, ";
			khoang = 4;
			break;
		case 7:
			cout<<"July, ";
			khoang = 4;
			break;
		case 8:
			cout<<"August, ";
			khoang = 6;
			break;
		case 9:
			cout<<"September, ";
			khoang = 9;
			break;
		case 10:
			cout<<"October, ";
			khoang = 7;
			break;
		case 11:
			cout<<"November, ";
			khoang = 8;
			break;
		case 12:
			cout<<"December, ";
			khoang = 8;
			break;
	}
	return khoang;
}
/*
	Ham tinh so ngay trong thang
	Input: thang - thang can xet
		   nam - nam can xet
	Output: So ngay trong thang do, nam do
*/
int NgayTrongThang (int thang, int nam)
{
	int n;
	switch(thang)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			 n = 31; break;		
		case 2: 
			if (NamNhuan(nam) == 1)
				n = 29;
			else
				n = 28;
			break;
		default: n = 30; break;
	}
	return n;
}
/*
	Ham tinh thu cua ngay, thang, nam
	Input: ngay - ngay dang xet
		   thang - thang dang xet
		   nam - nam dang xet
	Output: Tra ve thu 2 -> Chu nhat
*/
int LayThu(int ngay, int thang, int nam){
  int JMD;
   JMD = (ngay + ((153 * (thang + 12 * ((14 - thang) / 12) - 3) + 2) / 5) +
     (365 * (nam + 4800 - ((14 - thang) / 12))) +
     ((nam + 4800 - ((14 - thang) / 12)) / 4) - 
    ((nam + 4800 - ((14 - thang) / 12)) / 100) + 
    ((nam + 4800 - ((14 - thang) / 12)) / 400)  - 32045) % 7;
  int thu[] = {2,3,4,5,6,7,8};
  return thu[JMD];
}
/*
	Ham kiem tra ghi chu
	Input: ngay - ngay dang xet, thang - thang dang xet, nam - nam dang xet
		   gc[] - mang chua cac ghi chu
		   n - so luong ghi chu
	Output: Neu ngay, thang, nam dang xet co ghi chu thi tra ve 1, neu khong co thi tra ve 0
*/
int KTghichu (int ngay, int thang, int nam, Ghichu gc[], int n)
{
	for (int i = 0; i < n; i++)
		if (ngay == gc[i].ngay && thang == gc[i].thang && nam == gc[i].nam)
			return 1;
	return 0;
}
/*
	Ham hien thi lich
	Input: thang - thang dang xet, nam - nam dang xet
		   gc[] - mang chua cac ghi chu
		   n - so luong ghi chu
		   flag - bien co kiem tra xem co bat che do xem ghi chu khong
	Output: In ra man hinh thang, nam, cac ngay trong thang va cac thu cua 1 cuon lich, cac ngay co ghi chu duoc to mau do  
*/
void Hienthi (int thang, int nam, Ghichu gc[], int n, int flag)
{
	GotoXY(26,1);
	SetBGColor(9);
	SetColor(15);
	cout<<"----------------------------";
	GotoXY(26,2);	
	cout<<"|         CALENDAR         |";
	GotoXY(26,3);	
	cout<<"----------------------------";		
	GotoXY(26,5);
	cout<<"____________________________"<<endl;
	GotoXY(26,6);
	cout<<"       ";
	int khoang = Hienthithang(thang);
	cout<<nam;
	for (int i = 1; i <= 28-7-khoang-6; i++)
		cout<<" ";
	GotoXY(26,7);
	cout<<"____________________________"<<endl;
	GotoXY(26,8);
	cout<<"Mo  Tu  We  Th  Fr  Sa  Su  "<<endl;
	int DauThang = LayThu(1,thang,nam);
	GotoXY(26,9);
	for (int i = 2; i < DauThang; i++)
		cout<<"    ";
	int t = DauThang - 1;									//Bien luu tru so luong ngay trong tuan da nhap
	int SoNgay = NgayTrongThang(thang,nam);
	int Y = 9;
	for (int i = 1; i <= SoNgay; i++)
	{
		if (KTghichu(i,thang,nam,gc,n) == 1)
			SetColor(12);
		else
			SetColor(15);
		if (i < 10)
			cout<<"0"<<i;
		else
			cout<<i;
		cout<<"  ";
		t++;		
		if (t == 8)				//Neu da in ra het cac ngay trong tuan do thi xuong hang tiep theo
		{
			cout<<endl;
			t = 1;
			Y++;
			GotoXY(26,Y);
		}
		SetColor(15);			
	}
	if (t != 1)
		for (int i = t + 1; i <= 8; i++)
			cout<<"    ";
	SetBGColor(0);
	GotoXY(0,15);
	if (flag == 1)
		for (int i = 0; i < n; i++)						//Hien thi cac ghi chu len man hinh
			if(gc[i].thang == thang && gc[i].nam == nam)
				cout<<gc[i].ngay<<"/"<<gc[i].thang<<"/"<<gc[i].nam<<" : "<<gc[i].nd<<endl;
}
int main()
{
	int thang, nam;
	int key;
	Ghichu gc[100];
	int n = 0;
	int flag = 0;
	DocFile(gc,n);
	ResizeConsole(800,600);
	cout<<"Nhap vao thang, nam: ";
	cin>>thang>>nam;
	Hienthi(thang,nam,gc,n,flag);
	do
	{
		key = getch();
		switch (key)
	    {
	        case 77:	//Mui ten phai
	            thang++;
	            if(thang > 12)
	            {
	            	nam++;
	            	thang = 1;
				}				
	           	break;
	        case 75:	//Mui ten trai
	           	thang--;
	           	if(thang < 1)
	           	{
	           		nam--;
	           		thang = 12;
				}				
	           	break;
			case 's':
				if (flag == 0)
					flag = 1;
				else
					flag = 0;				
	           	break;           	
		}          
	    system("cls");
		ClearScreen();
		Hienthi(thang,nam,gc,n,flag);	    	
	}
	while (key != 27);
}
