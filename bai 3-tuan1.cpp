#include<iostream>
using namespace std;
struct nut{
	int info;
	nut *right,*left;
};
typedef nut Node ;
Node *goc;
//---------------khoi tao cho nut--------------------------------//
void khoitao(Node *&goc){
	goc == NULL;
}
//----------------moc nut --------------------------//
void mocnut(Node *&goc,int x){
	if (goc == NULL){
		goc = new Node;
		goc -> info=x;
		goc -> left = NULL;
		goc -> right = NULL; 
	}
	else 
	if (goc ->info >=x)
			mocnut (goc -> left,x);
		else 
			mocnut (goc -> right,x);
} 
//------------tao cay nhi phan-----------------//
void taocay(Node *&goc ){
	int tam;
	do {
		cout << "nhap 1 so nguyen: " ;
		cin >> tam;
		if (tam!=0) 
		mocnut(goc,tam);
	}
	while (tam!=0);
}
//-------------------- duyet cay LRN------------------//
void duyetLRN(Node *goc){
	if (goc != NULL){
		duyetLRN(goc->left );
		cout << goc->info;
		duyetLRN(goc->right);
	}
}
int inchieucao (nut *goc)
{
	if (goc == NULL)
		return 0;
	else
		if (goc->left == NULL && goc->right == NULL)
			return 1;
		else
			return 1 + max(inchieucao(goc->left), inchieucao(goc->right));
}
void ini (nut *goc, int h, int i)
{
	if (goc != NULL)
		if (h == i)
			printf("gia tri :%d",goc->info);
		else
		{
			ini(goc->left,h+1,i);
			ini(goc->right,h+1,i);
		}
}
int main(){
	khoitao(goc);
	taocay(goc);
	duyetLRN(goc);
}
