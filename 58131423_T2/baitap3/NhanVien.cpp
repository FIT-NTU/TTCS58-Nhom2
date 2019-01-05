#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<conio.h>

using namespace std;
ifstream nv("data.txt");
int n;
class NhanVien{
	protected: 
		string manv, hoten, chucvu;
		int hesoluong, hesochucvu, luong, thang, nam;
		static int luongCB;
	public:
		~NhanVien(){
		}
		virtual void DocFile(){
			string data;
			getline(nv, data); manv = data;
			getline(nv, data); hoten = data;
			getline(nv, data); hesoluong = atoi(data.c_str());
			getline(nv, data); chucvu = data;
			getline(nv, data); hesochucvu = atoi(data.c_str());
			getline(nv, data); thang = atoi(data.c_str());
			getline(nv, data); nam = atoi(data.c_str());
			}
		virtual void Xuat(){
			cout<<"Ma: "<<manv<<"\t";
			cout<<"Ten: "<<hoten<<"\t";
			cout<<"Hsluong: "<<hesoluong<<"\t";
			cout<<"Chuc vu: "<<chucvu<<"\t";
			cout<<"HSLuongCV: "<<hesochucvu<<"\t";
			cout<<"Thang: "<<thang<<"\t";
			cout<<"Nam: "<<nam<<"\t";
			cout<<"Luong: "<<TinhLuong();
		}
		virtual int TinhLuong(){
			return luong = luongCB * (hesoluong + hesochucvu);
		}
		friend bool operator >(NhanVien a, NhanVien b){
			if(a.luong > b.luong)
				return true;
			else return false;
		}
		friend bool operator ==(string a, NhanVien b){
			if(a == b.manv)
				return true;
			else return false;
		}
};

int NhanVien::luongCB = 3000000;

class DSNhanVien: public NhanVien{
	public:
		vector<NhanVien> ds;
	void Nhapds(){
			string data;
			getline(nv, data); n = atoi(data.c_str());
			ds.resize(n);
			for(int i = 0; i < n; i++)
				{
					ds[i].DocFile();
				}
			nv.close();	
	}
	void Xuatds(){
		for(int i = 0;i < n; i++)	
			{
				ds[i].Xuat();
				cout<<endl;
			}
	}
	void SapXepds(){
		for(int i = 0; i < n; i++)
			for(int j = i; j < n; j++)
				if(ds[i] > ds[j])
					swap(ds[i], ds[j]);		
	}
	void TimKiem(string a){
		for(int i = 0; i < n; i++)
			if(a == ds[i])
				ds[i].Xuat();
	}
	void Xoa(string a){
		for(int i = 0; i < n; i++)
			if(a == ds[i])
				{
					ds.erase(ds.begin() + i);
					n--;
				}
	}
};

int main(){
	string find;
	DSNhanVien nv;
	int chon;
    do
    {
        system("cls");
        cout<<("\t\t\t 1. Doc File\n");
        cout<<("\t\t\t 2. Hien thi danh sach nhan vien\n");
        cout<<("\t\t\t 3. Sap xep tang dan theo luong\n");
        cout<<("\t\t\t 4. Tim kiem nhan vien\n");
        cout<<("\t\t\t 5. Xoa nhan vien\n");
        cout<<("\t\t\t 6. Thoat\n");
        cout<<("Ban chon: ");
        cin>>(chon);
        switch(chon)
        {
            case 1:
 				nv.Nhapds();
                break;
            case 2:
 				cout<<"\n--------------------------------------------DANH SACH NHAN VIEN---------------------------------------\n";
 				nv.Xuatds();
                break;
            case 3:
				nv.SapXepds();
				cout<<"\n-------------------------------------DANH SACH NHAN VIEN SAU SAP XEP-------------------------------------\n";
                nv.Xuatds();
				break;
            case 4:
 				cout<<"Nhap ma nhan vien can tim: ";
 				fflush(stdin);
 				getline(cin, find);
 				cout<<"\n-----------------------------------------NHAN VIEN CAN TIM-----------------------------------------------------\n";
 				nv.TimKiem(find);
                break;
            case 5:
    			cout<<"Nhap ma nhan vien can xoa: ";
    			fflush(stdin);
    			getline(cin, find);
    			nv.Xoa(find);
    			cout<<"\n-------------------------------------------DANH SACH NHAN VIEN SAU KHI XOA--------------------------------------\n";
    			nv.Xuatds();
                break;
            case 6:
                break;
            default:
                printf("Ban chon sai. Moi ban chon lai\n");
                break;
        }
        getch();
    }while(chon!=6);
}
