#include<stdio.h>
int s,t,m,x,p=0;
int f[100000]={0};
int r[120]={0};
int map[100000]={0};
main()
{
      int l,k;
      int i,j,min;
      int quicksort(int date[],int s,int t);
      freopen("river.in","rt+",stdin);
      freopen("river.out","wt+",stdout);
      scanf("%ld%d%d%d",&l,&s,&t,&m);
      for(i=1;i<=m;i++)scanf("%ld",&r[i]);
      quicksort(r,1,m);
      for(i=1;i<=m;i++)
      {
                       l=r[i]-r[i-1];
                       if(l%t==0)k=t;
                       else k=1%t;
                       k+=t;
                       if(l<k)k=l;
                       p+=k;
                       map[p]=1;
      }
      for(i=1;i<=p+t;i++)
      {
                         min=101;
                         for(j=i-t;j<=i-s;j++)
                         {
                                              if(j<0)continue;
                                              if(f[j]<min)min=f[j];
                         }
                         f[i]=min+map[i];
      }
      min=101;
      for(i=p+1;i<=p+t;i++)if(f[i]<min) min=f[i];
      printf("%d\n",min);
}

int quicksort(int date[],int s,int t)
{
     int i,j,y,temp;
     i=s;
     j=t+1;
     y=date[s];
     for(;i<j;)
     {
                 for(i++;date[i]<y;i++);
                 for(j--;date[j]>y;j--);
                 if(i<j)
                 {
                        temp=date[i];
                        date[i]=date[j];
                        date[j]=temp;
                 }
     }
     date[s]=date[j];
     date[j]=y;
     if(s<j-1)quicksort(date,s,j-1);
     if(j+1<t)quicksort(date,j+1,t);
}
