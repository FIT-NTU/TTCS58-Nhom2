#include<stdio.h>
#include<conio.h>
	int a[][10] = {
       10 ,5, 6, 4, 7,
       2 ,9, 8, 6, 3,
       8 ,10 ,5 ,7 ,8 ,
       11 ,7, 9, 12, 6,
       12 ,9 ,10 ,11 ,10
	   };
	void nhapmt(int a[][10],int n){
		for (int i = 0 ; i < n ; i++)
			for (int j = 0 ; j < n ; j++){
			
			
				printf("mang vua nhap :");
				scanf("a[%3d][%3d]",&a[i][j]);
				}
}
	
	void xuatmt(int a[][10],int n){
		for (int i = 0 ; i < n ; i++){
		
			for (int j = 0 ; j < n;j++){
				printf("%3d",a[i][j]);
			}
			printf("\n");
		}
	}
void docfile(int a[][10],int &n)
{
    FILE *f;
    f=fopen("D:/58131283-phamxuanvudat-tuan1/input1.txt","rt");
    fscanf(f,"%3d",&n);
    for(int i=0;i<n;i++)
    	for( int j=0;j<n;j++  )
        fscanf(f,"%3d",&a[i][j]);
    fclose(f);
}
void ghifile(int a[][10],int n)
{
    FILE *f;
    f=fopen("D:/58131283-phamxuanvudat-tuan1/input1.txt","wt");
    fprintf(f,"%3d",n);
    for(int i = 0 ; i < n ; i++)
    	for (int j = 0 ; j < n ; j++)
        fprintf(f,"%3d",a[i][j]);
    fclose(f);
}
//-------in cac phan tu cua ma tran theo duong xoan oc--------//
void xoanoc(int a[][10],int m,int n){
	// m la chi so hang , n la chi so cot 
	if( m == n) printf("%3d",a[m][m]);
	else
	{
		// in hang dau
		for (int i = m ; i <= n ; i++)
			printf("%3d",a[m][i]);
		//  in cot cuoi 
		for (int i = m + 1 ; i <= n ; i++ )
			printf("%3d",a[i][n]);
		// in dong cuoi (in nguoc)
		for (int i = n - 1 ; i >= m ; i--)
			printf("%3d",a[n][i]);
		// in cot dau (in nguoc)
		for (int i = n - 1 ; i >= m + 1 ; i--)
			printf("%3d",a[i][m]);
	 } 
	 	xoanoc(a,m + 1, n-1);
}
int main(){
	int a[10][10], n;

docfile(a,n);
xuatmt(a,n);
printf("\n");
xoanoc(a,0,4);

}
