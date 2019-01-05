#include<stdio.h>
#include<iostream>
using namespace std;
struct nut{
	int gt;
	nut *left, *right;
};
nut *goc;
nut *goc2;
void MocNut (nut *&goc, int x)
{
	if (goc == NULL)
	{
		goc = new nut;
		goc->gt = x;
		goc->left = NULL;
		goc->right = NULL;
	}
	else
		if (goc->gt >= x)
			MocNut(goc->left,x);
		else
			MocNut(goc->right,x);
}
void TaoCay (nut *&goc)
{
	int tam;
	do
	{
		cout<<"Nhap gia tri cho nut, 0 dung: ";
		cin>>tam;
		if (tam != 0)
			MocNut(goc,tam);
	}
	while (tam != 0);
}
void LNR (nut *goc)
{
	if (goc != NULL)
	{		
		LNR(goc->left);
		cout<<goc->gt<<" ";
		LNR(goc->right);
	}
}
void NLR (nut *goc)
{
	if (goc != NULL)
	{		
		cout<<goc->gt<<" ";
		NLR(goc->left);		
		NLR(goc->right);
	}
}
int ChieuCao (nut *goc)
{
	if (goc == NULL)
		return 0;
	else
		if (goc->left == NULL && goc->right == NULL)
			return 1;
		else
			return 1 + max(ChieuCao(goc->left), ChieuCao(goc->right));
}
void InI (nut *goc, int h, int i)
{
	if (goc != NULL)
		if (h == i)
			cout<<goc->gt<<" ";
		else
		{
			InI(goc->left,h+1,i);
			InI(goc->right,h+1,i);
		}
}
void copy (nut *originT,nut *&newT)
{
	if (originT == NULL)
		newT = NULL;
	else
	{
		newT = new nut;
		newT->gt = originT->gt;
		copy(originT->left,newT->left);
		copy(originT->right,newT->right);
	}
}
void copyTree (nut *goc, int goc1)
{
	nut *p = goc;
	while((p != NULL) && (p->gt != goc1))
	{
		if (p->gt > goc1)
			p = p->left;
		else
			p = p->right;
	}
	if (p == NULL)
		cout<<"Khong tim thay nut";
	else
	{
		copy(p,goc2);		
	}
}
void Xoanut (nut *goc,int x)
{
	nut *p = goc, *q;
	while((p != NULL) && (p->gt != x))
	{
		q = p;
		if (p->gt > x)
			p = p->left;
		else
			p = p->right;
	}
	if (p == NULL)
		cout<<"Khong tim thay nut";
	else 
	{
		if (p->left == NULL && p->right == NULL)
		{
			if (q->left == p)
				q->left = NULL;
			else
				if (q->right == p)
					q->right = NULL;
			delete p;
		}
		else
			if (p->left != NULL && p->right == NULL)
			{
				if (q->left == p)
					q->left = p->left;
				else
					if (q->right == p)
						q->right = p->left;
				delete p;
			}
			else
				if (p->left == NULL && p->right != NULL)
				{
					if (q->left == p)
						q->left = p->right;
					else
						if (q->right == p)
							q->right = p->right;
					delete p;
				}
				else
				{
					nut *t =p->left, *s = t;
					while (t->right != NULL)
					{
						s = t;
						t = t->right;
					}
					p->gt = t->gt;
					if (s->right == t)
						s->right = t->left;
					else
						p->left = t->left;												
					delete t;							
				}
	}
}
void Khoitao(nut *&goc)
{
	goc = NULL;
}
int main()
{
	Khoitao(goc);
	TaoCay(goc);
	LNR(goc);
	cout<<endl<<"Chieu cao cua cay: "<<ChieuCao(goc);
	cout<<endl<<"Cac nut o muc 2: "<<endl;
	InI(goc,0,2);
	int goc1;
	int x;
	cout<<endl<<endl<<"Nhap nut can xoa: ";
	cin>>x;
	Xoanut(goc,x);
	NLR(goc);
}
