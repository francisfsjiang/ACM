#include<stdio.h>
int n,sum=0;
int put[1000],date[1000];
main()
{
      freopen("hh.in","rt+",stdin);
      freopen("hh.out","wt+",stdout);
      int i,j;
      int search(int x,int y);
      int check(int a,int b);
      memset(put,0,sizeof(put));
      memset(date,0,sizeof(date));
      scanf("%d",&n);
      for(i=1;i<=n;i++)for(j=1;j<=n;j++)search(i,j);
      return(0);
}

int search(int x,int y)
{
    int i,j,s;
    //if(sum==0)
    //{
    //printf("search(%d,%d)\n",x,y);
    //for(i=1;i<=n;i++)printf("%d ",put[i]);
    //printf("\n");
    //for(i=1;i<=n;i++)printf("%d ",date[i]);
    //printf("\n");
    for(i=x;i<=n;i++)
    {
                       if(put[i]!=0)
                       {
                                    date[put[i]]=0;
                                    //printf("date[%d]=0\n",put[i]);
                                    put[i]=0;
                                    //printf("put[%d]=0\n",i);
                       }
    }
    s=check(x,y);
    if(s==1&&x==n)
    {
                  put[x]=y;
                  sum=1;
                  for(i=1;i<=n;i++)
                  {
                                   for(j=1;j<=n;j++)
                                   {
                                                    if(put[i]==j)printf("1 ");
                                                    else printf("0 ");
                                   }
                                   printf("\n");
                  }
                  printf("\n");
    }
    else if(s==1)
    {
         put[x]=y;
         date[y]=1;
         for(i=1;i<=n;i++)
         {
                          if(date[i]==0)search(x+1,i);
         }
    }
//}
}


int check(int a,int b)
{
    int i,j,d=1; 
    for(i=a,j=b;i>=1&&j>=1;i--,j--)if(put[i]==j){d=0;break;}//向左上搜索
    if(d==1)for(i=a,j=b;i<=n&&j<=n;i++,j++)if(put[i]==j){d=0;break;}//向右下搜索
    if(d==1)for(i=a,j=b;i>=1&&j<=n;i--,j++)if(put[i]==j){d=0;break;}//向右上搜索
    if(d==1)for(i=a,j=b;i<=n&&j>=1;i++,j--)if(put[i]==j){d=0;break;}//向左下搜索
    if(d==1)return(1);
    else return(0);
}

