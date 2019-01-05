#include "pch.h"
#include <iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#define max 11
int A[max] = {0, 34, 36, 39, 41, 14, 32, 26, 39, 32, 43 };
using namespace std;
void heapsort(int a[], int n) {
	int i,j, ok, h;
	for (h = n/2; h >=1; h--)
	{
		i = h, ok =0;
		while ((i <= n / 2) && !ok) {
			if ((i == n/2) && 2 * i == n) j = 2 * i;
			else
			{
				if (a[2 * i] < a[2 * i + 1])	j = 2 * i;
				else j = 2 * i + 1;
			}
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
				i = j;
			}
			else ok = 1;
		}
	}

for (int k = n; k >= 2; k--)
	{
		swap(a[k], a[0]); i = 1, ok = 0;
		while ((i <= (k - 1) / 2) && !ok) {
			if ((i == (k - 1) / 2) && 2 * i == k - 1 ) j = 2 * i;
			else
			{
				if (a[2 * i] < a[2 * i + 1])	j = 2 * i;
				else j = 2 * i + 1;
			}
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
				i = j;
			}
			else ok = 1;
		}
	}
}

void NhapRand(int A[]) {
	srand(time(0));
	for (int i = 1; i <= max; i++)
	{
			A[i] = rand()%50;
	}
}

void XuatRand(int A[]) {
	cout << "Mang vua nhap";
	for (int i = 1; i < max; i++)
	{
		cout << A[i]<<"   ";
	}
}

int main()
{
	//NhapRand(A);
	XuatRand(A);
	cout << endl;
	heapsort(A, max);
	cout << "Mang da duoc sap xep: ";
	for (int i = 1; i < max; i++)
		cout << "   " << A[i];
}

