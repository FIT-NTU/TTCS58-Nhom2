#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
	input: nhap so luong phan tu va khoang gia tri cua so ngau nhien
	output: day so ngau nhien 
*/
void Songaunhien(int *A, int n, int m) {
    srand(time(NULL));
    int randNum = 0;
    for (int i = 0; i < n; i++) {
        randNum = 1+rand() % m;
        A[i] = randNum;
    }
}

int main() {
    int *A;
    int n ; /* so luong phan tu  */
    int m ; /* Moi phan tu có giá tri ngau nhiên nam trong khoang tu 0 den k */

	printf("nhap m:");
	scanf("%3d",&m);
	do{
		printf("\nnhap n:");
		scanf("%3d",&n);
	}
	while(n>m);
    A = new int[n]; // Cap phát bo nho cho mang A

    Songaunhien(A, n, m);

    /* Xuat mang */
    for (int i = 0; i < n; i++) {
        printf("%4d", A[i]);
    }
    printf("\n");

    delete[]A; // xoa vùng nho sau khi su dung
    return 0;
}
