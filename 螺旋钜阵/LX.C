#include<stdio.h>
int tmp[100][100];
int n;
main()
{    
     freopen("LX.in","rt+",stdin);    
     freopen("LX.out","wt+",stdout);
     int j,k;
     int lx(int a,int b,int c); 
     scanf("%d",&n);
     lx(1,0,n-1); 
     for(j=0;j<n;j++)
     {
                     for(k=0;k<n;k++)
                     {
                                     printf("%d ",tmp[k][j]);
                     }
                     printf("\n");
     }         
     return(0);     
}



int lx(int a,int b,int c)
{
    int i;
    if(b<c)
    { 
    for(i=b;i<=c;i++)tmp[b][i]=a++;
    for(i=b+1;i<c;i++)tmp[i][c]=a++;
    for(i=c;i>=b;i--)tmp[c][i]=a++;
    for(i=c-1;i>b;i--)tmp[i][b]=a++;
    lx(a,b+1,c-1);
    }
    else if(b==c)tmp[b][c]=n*n;
}
