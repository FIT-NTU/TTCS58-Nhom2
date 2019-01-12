#include <stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include <iostream>

using namespace std;


struct nut{
	int info;
	nut *left,*right;
};

typedef nut node;
node *goc,*goc2;
//-------------------------------------------------------------
void khoitao(node *&goc);
void mocnut(node *&goc,int x);
void taocay(node *&goc);
void cayrand(node *&goc);
void duyetLNR(node *goc);
void duyetcay(node *goc);
int max(int a,int b);
int chieucao(node *goc);
void Xuat(node *c, int k);
void Copy( node *&goc2,node *&goc );
void timphantuthemangphainhatcaycontrai(node *&p, node *&q);
void xoanode(node *&t, int x);

//-------------------------------------------------------------
int main()
{
	khoitao(goc);
	khoitao(goc2);
	//taocay(goc);
	cayrand(goc);
	Copy(goc2,goc);
	duyetLNR(goc);
	printf("\nchieu cao cua cay = %d",chieucao(goc));
	printf("\nTao cay goc 2:\n");
	duyetLNR(goc2);
	printf("\n");
	int k;
	printf("\nNhap muc k can xuat:");
	scanf("%d",&k);
	printf("\nCac nut muc k la:\n");
	Xuat(goc,k);
	int x;
	printf("\nNhap nut can xoa:");
	scanf("%d",&x);
	xoanode(goc,x);
	printf("\nCay sau khi xoa:\n");
	duyetcay(goc);
	
	
	
}

//---------------------------------------

void khoitao(node *&goc)
{
	goc = NULL;
}

//---------------------
void mocnut(node *&goc,int x)
{
	if(goc==NULL)
	{
		goc = new node;
		goc->info=x;
		goc->left=NULL;
		goc->right=NULL;
	}
	else
	{
		if(goc->info >=x)
			mocnut(goc->left,x);
		else
			mocnut(goc->right,x);
	}
}

//------------------------------------

void taocay(node *&goc)
{
	int tam;
	do
	{
		printf("nhap 1 nut va nhap 0 dung lai:");
		scanf("%d",&tam);
		if(tam!=0)
			mocnut(goc,tam);
	}
	while(tam!=0);
}
//------------------------------------

void cayrand(node *&goc)
{
	int tam;
	do
	{
		tam = rand()%51;
		if(tam!=0)
			mocnut(goc,tam);
	}
	while(tam!=0);
}

//---------duyet LNR-------------------

void duyetLNR(node *goc)
{
	if(goc!=NULL)
	{
		duyetLNR(goc->left);
		printf("%d\t",goc->info);
		duyetLNR(goc->right);
	}
	
}
//-------------------
void duyetcay(node *goc)
{
	if(goc!=NULL)
	{
		printf("%d\t",goc->info);
		duyetcay(goc->left);
		duyetcay(goc->right);
		
	}
	
}

//-------------chieu cao cay-------------------------
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int chieucao(node *goc)
{
	if(goc==NULL)
		return 0;
	else
		return 1+max(chieucao(goc->left),chieucao(goc->right));
}
//--------------------in muc k------------------------

void Xuat(node *c, int k)
{
    if (c!=NULL)
    {
        k--;
        if (c->left != NULL)
            Xuat(c->left,k);
        if (k==0)
            printf("%4d\t", c->info);
        if (c->right != NULL)
            Xuat(c->right,k);
    }
}


//----------coppy----------------------
void Copy( node *&goc2,node *&goc )
{
  if(goc == NULL )
     goc2 = NULL;
  else
      {
	goc2 = new node;
	goc2->info = goc->info;

	Copy(goc2->left,goc->left);
	Copy(goc2->right,goc->right);
      }
}
//// hàm tìm nut the mang
//void timnutthemang(node *&X, node *&Y) 
//{	
//	// tim nut phai nhat cua cay con trai
//	if (Y->right != NULL)
//	{
//		timnutthemang(X, Y->right);// tìm ra nut phai nhat
//	}
//	else // tìm ra dc nut phai nhat
//	{
//		X->info = Y->info; 
//		X = Y; 
//		Y = Y->left;	
//	}
//}
//
////------xoa mot nut-----------------
//
//void xoanut(node *&goc,int x)
//{
//	node *p;
//	p = goc;
//	if(p==NULL)
//		return ;
//	else if(p!=NULL)
//	{
//		if(x < p->info)
//		{
//			xoanut(p->left,x);
//		}
//		else if( x>p->info )
//		{
//			xoanut(p->right,x);
//		}
//			else if(x==p->info) // gia tri == info ..
//			{
//				node *T =p;
//				if(p->left == NULL)// cay con phai vi cay con trai == NULL
//				{
//					p = p->right;// tro toi cay con phai 
//				}
//				else if(p->right==NULL)//cay con trai
//					{
//						p=p->left;
//					}
//					else if(p->left != NULL && p->right != NULL) // nut co ca hai con
//						{
//							timnutthemang(T,p);
//						}
//			delete T;// xoa nut can xoa
//			}
//		
//	}
//}
//-------------------------------------


void timphantuthemangphainhatcaycontrai(node *&p, node *&q)
{
	if (q->right != NULL)
	{
		timphantuthemangphainhatcaycontrai(p, q->right);
	}
	else
	{
		p->info = q->info;
		p = q;
		q = q->left;
	}



}
void xoanode(node *&t, int x)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (t->info > x)
		{
			xoanode(t->left, x);
		}
		else if(t->info<x)
		{
			xoanode(t->right, x);
		}
		else
		{
			node *p = t;
			if (t->left == NULL)
			{
				t = t->right;
			}
			else if(t->right==NULL)
			{
				t = t->left;
			}
			else
			{

				timphantuthemangphainhatcaycontrai(p, t->left);
			}

			delete p;
       }
   }

}

