#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Nhap (int a[], int &n){
	for (int i = 0; i < n; i++){
		cout << "a["<<i<<"]= ";
		cin >> a[i];
	}
}
void RanN(int a[], int n){
	for (int i = 0; i< n; i++)
		a[i] = rand()%50;
}
void Xuat (int a[], int n){
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
}

/*void TaoDong(int a[], int n){
	for (int i = 0; i < n; i++){
		for (int j = 2*i + 1; j < n ; j++)
			if (a[i] < a[j])
				swap(a[i], a[j]);
	}
}*/
void ChinhHeap(int a[], int k, int i){
	int lnode, rnode, bnode;
	lnode = 2*k;
	rnode = 2*k+ 1;
	if (lnode <= i && a[lnode] > a[k]){
		bnode = lnode;
	}
	else{
		bnode = k;
	}
	if (a[rnode] > a[bnode] && a[rnode] > a[k]){
		bnode = rnode;
	}
	if (bnode != k){
		swap (a[bnode], a[k]);
		ChinhHeap(a, bnode, i);
	}
}
void TaoHeap (int a[], int n){
	int k, i;
	i = n - 1;
	for ( k = n/2; k >= 0; k--){
		ChinhHeap(a, k, i);
	}
}
int main(){
	int n; int a[50];
	cout << "Nhap n: ";
	cin >> n;
	Nhap(a,n);
	Xuat(a, n);
	cout << endl;
	TaoHeap (a,n);
	Xuat (a, n);
}
