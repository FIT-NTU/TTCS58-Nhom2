#include<iostream>
#include<stdlib.h>
#include<vector>
#include<fstream>
#include<string.h>
using namespace std;
ifstream f("D:/58131283-tuan2/input3.txt");
class quanli{
	private:
	string ma, hoten,chucvu,soluong;
	int hsluong,hschucvu,thang,nam;
	public:
		friend class quanlids;
		void nhap();
		void xuat();
		int luong();
	
};
void quanli::nhap(){
	string s;
			getline(f,s);ma = s;
			getline(f,s);hoten =s;
			getline(f,s);chucvu=s;
			getline(f,s);hsluong=atoi(s.c_str());
			getline(f,s);hschucvu=atoi(s.c_str());
			getline(f,s);thang=atoi(s.c_str());
			getline(f,s);nam=atoi(s.c_str());
}
void quanli::xuat(){
			cout <<"\nma:"<<ma<<endl;
			cout <<"\nho ten:"<<hoten<<endl;
			cout <<"\nchuc vu:"<<chucvu<<endl;
			cout <<"\nhe so luong:"<<hsluong<<endl;
			cout <<"\nhe so chuc vu:"<<hschucvu<<endl;
			cout <<"\nthang:"<<thang<<endl; 
			cout <<"\nnam:"<<nam<<endl;
			int l=luong(); 
			cout <<"\n luong :"<<l<<endl;
}
int quanli::luong(){
	int luong=0,luongcb=2000;
	return luong=luongcb*(hsluong+hschucvu);
}
class quanlids{
			private:
				int n;
			vector<quanli>ds;
				public :
					void nhapds(){
						string s;
						getline(f, s); 
						n = atoi(s.c_str());
			 			ds.resize(n);
			  			cout << n << endl;
			
			 		for (int i = 0; i < ds.size(); i++) {
			 					ds[i].nhap();
							}
						f.close();
					};
					void xuatds(){
						for (int i = 0; i < n; i++) {
			 					ds[i].xuat();
							}
							xoa();
						}
					void sapxep(){
							for (int i=0;i<ds.size()-1;i++)
								for (int j=i+1;j<ds.size();j++){
									if (ds[i].luong()<ds[j].luong())
										swap(ds[i],ds[j]);
									}
									for (int i=0;i<ds.size();i++)
										ds[i].xuat();		
					}
					void timkiem ()

					{
						string  maso;
						cout<<"Nhap ma so nhan vien can xoa: ";
    					getline(cin, maso);
						for (int i = 0; i < ds.size(); i++)
							if (ds[i].ma == maso){
									ds[i].xuat();
							break;
							}
					}	
					void xoa(){
						string  maso;
						cout<<"Nhap ma so nhan vien can tim: ";
    					getline(cin, maso);
						for (int i=0;i<ds.size();i++)
							if (ds[i].ma ==maso){
								ds.erase(ds.begin()+i);
								n--;
							}
							for (int i=0;i<ds.size();i++)
										ds[i].xuat();
							
					}
		};
		
int main(){
	quanlids ql;
	ql.nhapds();
	ql.xuatds();
	
}
