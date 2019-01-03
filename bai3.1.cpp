#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct nut {
	int Info;
	nut *left;
	nut *right;
};


typedef nut Node;
Node *goc;
void khoitao(Node *&goc){
	goc = NULL;
}
//---------------------
void mocnut(Node *&goc, int x){
	if (goc == NULL){
		goc = new Node;
		goc->Info = x;
		goc->left = goc->right = NULL;
	}
	else 
		if (goc->Info >= x)
			mocnut(goc->left,  x);
		else 
			mocnut(goc->right, x);

}
//------------
void taonut(Node *&goc){
	int tam;
	do{
		printf ("nhap 1 so nguyen duong:");
		scanf("%d",&tam);
		if (tam != 0)
		mocnut(goc, tam);
	}while (tam != 0);
}
void duyetcay(Node *goc){
	if (goc != NULL){
		printf("%d \t", goc->Info);
		duyetcay(goc->left);
		duyetcay(goc->right);
	}
}
//--------LNR
void LNR(Node *goc){
	if (goc != NULL){
		LNR(goc->left);
		printf("%d ", goc->Info);
		LNR(goc->right);
	}
}

//--chieu cao
int max(int a, int b){
	if (a >= b)
		return a;
	else 
		return b;
}


int chieucao (Node *goc){
		if (goc == NULL){
			return 0;
		}
		else 
			if ((goc->left == NULL) && (goc->right == NULL))
				return 1;
			else
				return 1+ max(chieucao(goc->left), chieucao(goc->right));
}

//----------------
//int demnut (Node *goc){
//	if (goc == NULL)
//		return 0;
//	else
//		if ((goc->left == NULL) &&(goc->right) == NULL)
//				return 1;
//		else
//			return 1 + demnut(goc->left) + demnut(goc->right);		
//}

int dem(Node *goc, int k){
	if (goc != NULL)
	{
		k--;
		int a = dem(goc->left, k);
		int b = dem(goc->right,k);
		if (k==0){
			 return 1 + a + b;

		}
		return a + b;
	}
	return 0;
}
void Xuat(Node *goc, int k)
{
    if (goc!=NULL)
    {
        k--;
        if (goc->left != NULL)
            Xuat(goc->left,k);
        if (k==0)
            printf("%4d\t", goc->Info);
        if (goc->right != NULL)
            Xuat(goc->right,k);
    }
}
//void taocay(nut *&goc, int a[], int n){
//	for (int i = 0; i < n; i++){
//	mocnut(goc, a[i]);
//	}
//}

//---------------- xoa
void xoanut(Node *&goc, int x){
	if (goc == NULL){
		return;
	}
	else{
	
		if(x < goc->Info){
			xoanut(goc->left,x);
		}
		else 
			if(x > goc->Info){
				xoanut(goc->right,x);
			}
			else 
			{
				Node *tam = goc;
				if (goc->left == NULL){
					goc = goc->right;
				}
				else 
					if(goc->right == NULL)
						goc = goc->left;
						
					else{
						Node *p = goc, *q = p->left;
						while(q->right != NULL){
							p = q;
							q = q->right;
						}
						tam->Info = q->Info;
						p->right = q->right;
						delete q;
					}
			}
		}
}
//-------------- 6 
void copy(Node *goc, Node *goc2){
	if (goc == NULL)
		goc2 = NULL;
	else {
		goc2 = new Node;
		goc2->Info = goc->Info;
		copy(goc2->left,goc->left);
		copy(goc->right, goc->right);
	}
}

int main(){
	int x;
	khoitao(goc);
//	int a[] = { 40, 5, 35, 45, 15, 56, 48, 13, 16, 49, 47 };
//	int n = 11;
	taonut(goc);
//	printf("duyet cay: ");
//	duyetcay(goc);
	printf("\n--------------------\n");
	printf("LNR = ");
	LNR(goc);
	printf("\nchieu cao cua cay: %d", chieucao(goc));
	printf("\ncac nut: ");
	Xuat(goc,2);
	printf("\nnhap x: ");
	scanf("%d", &x);
	xoanut(goc,x);
	printf("duyetcay = ");
	duyetcay(goc);
	
}
