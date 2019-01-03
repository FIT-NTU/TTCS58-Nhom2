#include<iostream>
#include<stdlib.h>
using namespace std;
// khai báo câu trúc node
struct node{
	int data;// du lieu cua node
	node *pLeft; //	node ben trai cua cay <=> cay con trai
	node *pRight; // node ben phai
}; 
	node* root;
void KhoiTaoCay(node*&root);
void Moc(node *&,int x);
void TaoCay(node *&root);
void Taongaunhien(node *&root);
void DuyetLNR(node *root);
int Max(int a, int b);
int ChieuCao(node *root);

//------------------
int main(){
	
//	TaoCay(root);
	KhoiTaoCay(root);
	Taongaunhien(root);
	DuyetLNR(root);
	cout << endl;
	cout << "Chieu cao cua cay = "<<ChieuCao(root)<<endl;
//	node *P;
//	int x;
//    cout << "Nhap vao node can xoa: ";
//    cin >> x;
//    P = TimNode(root, x);
//    if (P != NULL) 
//	cout <<"Tim thay node "<< P->data;
//    else 
//	cout << " Node khong co trong cay :" << x;
//    cout <<" Cay sau khi xoa:"<< (Xoa(root, x));
//    cout << " Xoa thanh cong";
    return 0;
}
void KhoiTaoCay(node *&root){
	root = NULL;
}
void Mocnut(node *&root,int x){
	if(root==NULL){
		root = new node;// khoi tao 1 node de them vao cay
		root->data=x; // them du lieu x vao data 
		root->pLeft=NULL; 
		root->pRight=NULL;
		// neu chua co node thi x chinh la node goc
	}
	else{// cay co ton tai phan tu
		if(root->data >x)
			Mocnut(root->pLeft,x);
		else
			Mocnut(root->pRight,x);
	}
}
//3.2
void TaoCay(node *&root){
	int tam;
	do{
		cout << " Nhap 1 nut ( 0 de dung lai):";
		cin >> tam;
		if(tam!=0)
			Mocnut(root,tam);
	}
	while(tam!=0);
}
void Taongaunhien(node *&root){
	int tam;
		do{
			tam= rand()%51;
			if(tam!=0) Mocnut(root,tam);
		}while (tam!=0);
}
//3.3
void DuyetLNR(node *root){
   if (root!=NULL)
   {
	DuyetLNR(root->pLeft);	// duyet trai
	cout << root->data << " ";// xuat du lieu node
	DuyetLNR(root->pRight);    //duyet phai
   }	
}
//3.4
int Max(int a, int b) {
   if(a>b)
      return a;
   else 
      return b;
}
int ChieuCao(node *root){
	if(root==NULL)
		return 0;
	else{
		return Max(ChieuCao(root->pLeft),ChieuCao(root->pRight)) + 1;
	}
}
//3.7
//node* TimNode(node *root, int x)     // tim node x
//{
//    if (root!=NULL)
//    {
//        if (root->data == x) { node *P = root; return P;}
//        if (root->data > x) return TimNode(root->pLeft, x);
//        if (root->data < x) return TimNode(root->pRight, x);
//    }
//    return NULL;
//}
//int Xoa(node *root, int x)     // xoa node  x
//{
//    if (root==NULL) return 0;
//    else if (root->data > x) return Xoa(root->pLeft, x);
//    else if (root->data < x) return Xoa(root->pRight, x);
//    else
//    {
//        node *P = root;
//        if (root->pLeft == NULL) root = root->pRight;    // Node chi co cay con phai
//        else if (root->pRight == NULL) root = root->pLeft;   // Node chi co cay con trai
//        else // Node co ca 2 con
//        {
//            node *S = root, *Q = S->pLeft;
//            // S la cha cua Q, Q la Node phai nhat cua cay con trai cua P
//            while (Q->pRight != NULL)
//            {
//                S = Q;
//                Q = Q->pRight;
//            }
//            P->data = Q->data;
//            S->pRight = Q->pLeft;
//            delete Q;
//        }
//    }
//    return 1;
//}
