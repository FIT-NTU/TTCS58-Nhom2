# include <stdio.h>
# include <conio.h>

int a[5][5]={10,5,6,4,7,
             2,9,8,6,3,
			  8,10,5,7,8,
			 11,7,9,12,6,
			 12,9,10,11,10};
void inxoan(int a[5][5],int k,int n)
{ int i;
  if (k==n) printf ("%3d",a[k][k]);
  else
   { for (i=k;i<=n;i++)   printf("%3d",a[k][i]);    
     for (i=k+1;i<=n;i++) printf("%3d",a[i][n]);   
     for (i=n-1;i>=k;i--)printf("%3d",a[n][i]);  
     for (i=n-1;i>=k+1;i--) printf("%3d",a[i][k]);    
     inxoan(a,k+1,n-1);
   }
  
}
int main()
{ inxoan(a,0,4);
  getch();
  return 0;
}
