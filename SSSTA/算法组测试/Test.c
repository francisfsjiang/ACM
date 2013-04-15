#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",)
}

qsort(int data,int x,int y)
{
          int i,j,temp,d;
          d=data[x];
          i=x;
          j=y+1;
          for(;i<j;)
          {
                    for(i++;i<d;i++);
                    for(i--;j>d;j--);
                    if(i<j)
                    {
                           temp=data[i];
                           data[i]=data[j];
                           data[j]=temp;
                    }
          }
          data[x]=data[j];
          data[j]=d;
          if(x<j-1)qsort(data,x,j-1);
          if(j+1<y)qsort(data,j+1,y);
}
