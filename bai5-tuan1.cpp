#include<stdio.h>
#include<math.h>
#include<fstream>
struct co{
	int tren,duoi;
};
co a[28]; //du lieu luu cac quan co
int tt[29]; // trang thai cac quan co
int ttluu [29]; // luu lai  trang thai cac quan co can tim
int n; //so quan co can xu li
int cl=168;
//----------------------------------
void nhapco(int &n){
	do{
		printf("nhap n:");
		scanf("%d",&n);
	}
	while(n<1||n>20);
	for ( int i = 0 ; i < n ; i++ )
		{
			printf("quan co thu  %d  ",i);
			printf("\n mat tren :");
			scanf("%d",&a[i].tren);
			printf("\n mat duoi :");
			scanf("%d",&a[i].duoi);
		}
}
//-----------------------------------
void kiemtra(){
	int sumtren=0,sumduoi=0;
	int dochech;
	for (int k=1;k<=n;k++)
		if(tt[k]==0){
		sumtren=a[k].tren+sumtren;
		sumduoi=a[k].duoi+sumduoi;
		}
		else 
		{
		sumtren=a[k].duoi+sumtren;
		sumduoi=a[k].tren+sumduoi;
		}
	dochech=abs(sumtren-sumduoi);
	if (dochech<cl){
		cl=dochech;
		for (int k=1;k<=n;k++)
		ttluu[k]=tt[k];
	}
	
}
//-------------------------------------
void thu(int i){
		int k;
		for (k=0;k<=1;k++){
			tt[i]=k;
			if(i<n) {
			thu(i+1);
			}
			else 
				kiemtra();
				tt[i]=0;
		}	
}

//-----------------------------------
void ketqua(){
	int dem=0;
	printf("\n do lech be nhat: %d",cl);
	// so luong quan co xoay
	for (int k=1;k<=n;k++)
	if (ttluu[k]==1) dem=dem+1;
	printf("\nso luong quan co phai quay:%d",dem);
	printf("\n trang thai ung voi do lech be nhat \n");
	for (int k=1;k<=n;k++)
	printf("%2d",ttluu[k]);
	}
	

//----------------------------------
int main(){
	int n,a[28];
	nhapco(n);
	ketqua();
	
}
