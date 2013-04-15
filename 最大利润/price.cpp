#include<stdio.h>
const int SIZE=105;

int main()
{    
     freopen("price.in","r",stdin);    
     freopen("price.out","w",stdout);    
     int n,m,i,j;
     int price[SIZE][SIZE];
     int max(int x,int y);
     scanf ("%d",&m);//项目数/行     
     scanf ("%d",&n);//money/列 
     for (i=0;i<m;i++)
     {
         for (j=0;j<n;j++)
         {
          scanf ("%d",&price[j][i]);
         }
     }
     printf("%d",max(m,n));
     return(0);
}


int max(int x,int y)//x项目数y钱数 
{
int a,b,c,pri,max2=0,max3,temp[SIZE][3];
int price[SIZE][SIZE];

if (x=1)
{
           pri=price[y][0];
           return(pri); 
}





else
{
for(c=1;c<=y;c++)
{
                 for (b=0;b<y;b++)
                 {
                     temp[b][0]=price[c][x-1]*c;                   
                     temp[b][1]=max(x-1,y-c);
                     temp[b][2]=temp[b][0]+temp[b][1];
                 }
}


for(c=0;c<=y;c++)
{
    if(temp[c][2]>max2)
    {
                      max2=temp[c][2];
                      max3=c;
    }
}
return(max2*max3);
}




}

