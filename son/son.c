#include<stdio.h>
#include<string.h>
int main()
{    
     freopen("son.in","rt+",stdin);    
     freopen("son.out","wt+",stdout);    
     int n,i,j,a,b,m,p,x,c;
     int fun (int x ,int y);
     long num[4];
     scanf("%d",&n);
     //for(i=0;i<n;i++)
     //{
     //                for(j=0;j<=3;j++)
      //              {
     //                                 scanf("%d",&num[j][i]);
     //                }
     //}
     //for(i=0;i<n;i++)
     //{
     //                for(j=0;j<=3;j++)
     //                {
     //                                 printf("%d ",num[j][i]);
     //                }
     //                printf("\n");
     //}
     //printf("********************************************\n");
     for(i=0;i<n;i++)
     {
                     scanf("%d",&num[0]);
                     scanf("%d",&num[1]);
                     scanf("%d",&num[2]);
                     scanf("%d",&num[3]);
                     //printf("i=%d\n",i);
                     m=0;
                     p=num[3]/num[2];
                     for(x=p;x<=num[3];x++)
                     {
                                  a=fun(x,num[0]);
                                  b=(x*num[2])/fun(x,num[2]);
                                  if(b==num[3]&&a==num[1])
                                  {
                                                                m++;
                                                                //printf("x=%d\n",x);
                                  }
                     
                     }
                     printf("%d\n",m);
                     //printf("********************************************\n");

     }
                                  
                                  
                     




return(0);
}



int fun(int x,int y)
{
    int t,z;
    if(x<y)
    {
           t=x;
           x=y;
           y=t;
    }
    if(x%y==0)return(y);
    else 
    {
         z=fun(y,(x%y));
         return(z);
    }
}
