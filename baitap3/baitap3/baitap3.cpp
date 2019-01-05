#include "pch.h"
#include <iostream>
#include<algorithm>
using namespace std;

struct Node {
	int infor;
	Node *left;
	Node *right;
};

void KhoiTao(Node *&dau) {
	dau = NULL;
}

void MocNut(Node *&goc, int x) {
	if (goc == NULL)
	{
		goc = new Node;
		goc->infor = x;
		goc->left = NULL;
		goc->right = NULL;
	}
	else
	{
		if (x <= goc->infor) MocNut(goc->left, x);
		else MocNut(goc->right, x);
	}
}

void NhapCay(Node *&goc) {
	int x;
	do {
		cout << "Nhap gia tri x, 0 dung: ";
		cin >> x;
		if(x != 0)	MocNut(goc, x);
	} while (x != 0);
}

void XuatCayLNR(Node *goc) {
	if (goc != NULL)
	{
		XuatCayLNR(goc->left);
		cout << goc->infor << "   ";
		XuatCayLNR(goc->right);
	}
}

int ChieuCao(Node *goc) {
	if (goc == NULL)	return 0;
	else
		if (goc->left == NULL && goc->right == NULL) return 1;
		else
		{
			return 1 + max(ChieuCao(goc->left), ChieuCao(goc->right));
		}
}

void InMuc(Node *goc, int i, int m) {
	if (goc != NULL)
	{
		if (m == i)	cout << goc->infor<<"   ";
		else {
			InMuc(goc->left, i, m + 1);
			InMuc(goc->right, i, m + 1);
		}
	}
}

void SaoChep(Node *goc1, Node *&goc2) {
	if (goc1 != NULL)
	{
		goc2 = new Node;
		goc2->infor = goc1->infor;
		goc2->left = NULL;
		goc2->right = NULL;
		SaoChep(goc1->left, goc2->left);
		SaoChep(goc1->right, goc2->right);
	}
}

void TimNode(Node *&X, Node *&Y) {
	if (Y->left != NULL) {
		TimNode(X, Y->left);//Trỏ đến vị trí trái cuối của bên phải X
	}
	else
	{
		X->infor = Y->infor;//Đưa giá trị trái cùng của bên phải giá trị X lên thay thế.
		X = Y;//gán X = Y để khi xóa X thì Y cũng bị xóa
		Y = Y->right;//Gán Y = NULL
	}
}

void XoaNut(Node *&goc, int data) {
	if (goc == NULL)	return;//Neu rong ket thuc chuong trinh
	else
	{
		//Neu data nho hon gia tri goc
		if (data < goc->infor)
		{
			XoaNut(goc->left, data);//duyet sang trai
		}
		//Neu data lon hon gia tri goc
		else if (data > goc->infor)
		{
			XoaNut(goc->right, data);//duyet sang phai
		}
		else //data == goc->infor đã tiềm ra giá trị cần xóa
		{
			Node *X = goc;//trỏ X vào vị trí cần xóa là goc
			//Trường hợp cây có giá trị bên phải, bên trái NULL thì ta lấy giá trị bên phải gán cho giá trị bị xóa.
			if (goc->left == NULL)	goc = goc->right;//Gán giá trị goc = goc->right
			//Trường hợp cây có giá trị bên trái, bên phải NULL thì ta lấy giá trị bên trái gán cho giá trị bị xóa.
			else if (goc->right == NULL)	goc = goc->left;
			//Trường hợp hai giá trị trái phải đều không NULL , ta lấy giá trị trái cùng của bên phải giá trị bị xóa gán cho giá trị bị xóa.
			else {
				Node *Y = goc->right;//Tạo một con trỏ trỏ đến vị trí bên phải của giá trị cần xóa,, để ta tìm giá trị trái cùng bên phải của giá trị cần xóa.
				TimNode(X, Y);
			}
			delete X;//xóa đi giá trị cần xóa là gốc
		}
	}
}

int main()
{
	int i, data;
	Node *goc, *goc1;
	goc = new Node;
	goc1 = new Node;
	KhoiTao(goc);
	NhapCay(goc);
	cout << "Cay nhi phan vua nhap" << endl;
	XuatCayLNR(goc);
	cout<<endl << "Chieu cao cua cay nhi phan la: " << ChieuCao(goc);
	cout <<endl << "Nhap muc i can in: ";
	cin >> i;
	InMuc(goc, i, 1);
	SaoChep(goc, goc1);
	cout << endl << "Cay 2(duoc sao chep tu cay 1): ";
	XuatCayLNR(goc1);
	cout <<endl << "Nhap vao gia tri can xoa: ";
	cin >> data;
	XoaNut(goc, data);
	cout << endl << "Cay da xoa gia tri: ";
	XuatCayLNR(goc);
}

