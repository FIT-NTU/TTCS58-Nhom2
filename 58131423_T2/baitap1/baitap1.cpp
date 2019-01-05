
#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int A[10][10];
int n, hang, cot;

void NhapMT(int &n, int A[10][10]) {
	do
	{
		cout << "Nhap cap ma tran: ";
		cin >> n;
	} while (n < 3 || n > 10);
	hang = n; cot = n;
	srand(time(NULL));
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			A[i][j] = rand()%100 + 1;//rand()%101 +1 t? công th?c rand()%(b - a +1) + 1,, s? ng?u nhiên trong kho?ng [a, b]
		}
}

void XuatMT(int A[10][10]) {
	for (int i = 0; i < hang; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			cout << A[i][j] << "     ";
		}
		cout << endl;
	}
}

void XoaDong(int &hang,int A[10][10]) {
	int dong;
	cout << endl << "Nhap hang can xoa: ";
	cin >> dong;
	for(int index = 0; index < hang; index++)	
		if (dong == index)//tìm du?c dòng c?n xóa
		{
			for(int i = index; i < hang; i++)//vòng l?p for b?t d?u t? v? trí dòng c?n xóa
				for (int j = 0; j < cot; j++)
				{
					A[i][j] = A[i + 1][j];//gán giá tr? hàng i = i+1
				}
			hang--;//tr? di 1 hàng.
			return;
		}
}

void XoaCot(int &cot, int A[10][10]) {
	int m;
	cout << endl << "Nhap hang can xoa: ";
	cin >> m;
	for (int index = 0; index < cot; index++)
		if (m == index)//tìm du?c c?t c?n xóa
		{
			for (int i = 0; i < hang; i++)
				for (int j = index; j < cot; j++)//vòng lap for bat dau tu vi trí c?t can xóa
				{
					A[i][j] = A[i][j+1];//gán giá tr? hàng i = i+1
				}
			cot--;//tr? di 1 hàng.
			return;
		}
}

bool KiemTraDX(int hang, int cot, int A[10][10])
{
	if (hang != cot) return 0;//N?u ma tr?n không vuông thì ma tr?n không d?i x?ng
	for (int i = 0; i < cot - 1; i++)//xét t? hàng 0 d?n hàng n - 2, vì hàng n -1 ta không có giá tr? d? xét 
		for (int j = i + 1; j < cot; j++)//Xét 2 di?m d?i x?ng qua du?ng tr?c chính
			if (A[i][j] != A[j][i])//N?u không b?ng nhau thì xu?t 0 tuong duong c?i không d?i x?ng
				return 0;
	return 1;
}

void XuatDX() {
	if (KiemTraDX(hang, cot, A) == 0)
		cout << endl << "MA TRAN KHONG DOI XUNG!!!";
	else cout << endl << "MA TRAN NAY DOI XUNG!!!";
}

bool MaxCheo(int i, int j){
	int k, h;
	for (k = i, h = j; k >= 0 && h < cot; k--, h++)
		if (A[k][h] > A[i][j])
			return false;

	for (k = i + 1, h = j - 1; k < hang && h >= 0; k++, h--)
		if (A[k][h] > A[i][j])
			return false;

	for (k = i - 1, h = j - 1; k >= 0 && h >= 0; k--, h--)
		if (A[k][h] > A[i][j])
			return false;

	for (k = i + 1, h = j + 1; k < hang && h < cot; k++, h++)
		if (A[k][h] > A[i][j])
			return false;

	return true;
}

bool MaxDoc(int i, int j) {
	for (int k = 0; k < hang; k++)
		if (A[k][j] > A[i][j])
			return false;
	for (int k = 0; k < cot; k++)
		if (A[i][k] > A[i][j])
			return false;
	return true;
}

void KiemTraHH() {
	int dem = 0;//d?m s? lu?ng hoàng h?u
	cout << endl << "So hoang hau trong ma tran: ";
	for(int i = 0; i < hang; i++)
		for(int j = 0; j < cot;j++)
			if (MaxCheo(i, j) && MaxDoc(i, j))
			{
				cout << A[i][j] << "     ";
				dem++;
			}
}

int main() {
	NhapMT(n, A);
	XuatMT(A);
	XoaDong(hang, A);
	XuatMT(A);
	XoaCot(cot, A);
	XuatMT(A);
	XuatDX();
	KiemTraHH();
}
