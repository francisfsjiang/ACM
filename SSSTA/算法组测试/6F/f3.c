#include<stdio.h>
int left[5000005],right[5000005],mid[5000005],max[5000005],min[5000005];
int data[5000005];
int remax,remin;
int main()
{
      freopen("input.txt","r",stdin);
      freopen("out.out","w",stdout);
      int build(int n,int x,int y);
      int father(int x);
      int tleft(int x);
      int tright(int x);
      int searchb(int n,int x,int y);
      int searchs(int n,int x,int y);
      int t,i,j,k,n,m;
      int maxx,minn,sum;
      scanf("%d",&t);
      for(;t>0;t--)
      {
            scanf("%d%d",&n,&m);
            for(i=1;i<=n;i++)scanf("%d",&data[i]);
            build(1,1,n);
            int end=1;
            sum=0;
            for(i=1;i<=n;i++)
            {
                  maxx=searchb(1,i,end);
                  minn=searchs(1,i,end);
                  for(j=end+1;j<=n;j++)
                  {
                        if(data[j]<minn)
                        {
                              if(maxx-data[j]<=m)minn=data[j];
                              else
                              {
                                    end=j-1;
                                    if(end-i+1>sum)sum=end-i+1;
                                    break;
                              }
                        }
                        else if(data[j]>maxx)
                        {
                              if(data[j]-minn<=m)maxx=data[j];
                              else
                              {
                                    end=j-1;
                                    if(end-i+1>sum)sum=end-i+1;
                                    break;
                              }
                        }

                  }
                  if(j==n+1&&end==1)
                  {
                                    sum=j-n;
                                    break;
                  }
                  if(end<=i)end=i+1;
            }
            printf("%d\n",sum);
      }
      return 0;
}

int father(int x)
{
    if(x%2==0)return x/2;
    else return (x-1)/2;
}

int tright(int x)
{
    return 2*x+1;
}

int tleft(int x)
{
    return 2*x;
}
int build(int n,int x,int y)//建树
{
      if(x==y)
      {
            left[n]=x;
            right[n]=y;
            mid[n]=x;
            max[n]=data[x];
            min[n]=data[x];
            return;
      }
      else if((y-x)%2==0)
      {
            left[n]=x;
            right[n]=y;
            mid[n]=x+(y-x)/2;
      }
      else
      {
            left[n]=x;
            right[n]=y;
            mid[n]=x+(y-x-1)/2;
      }
      build(tleft(n),left[n],mid[n]);
      build(tright(n),mid[n]+1,right[n]);
      if(max[tleft(n)]>max[tright(n)])max[n]=max[tleft(n)];
      else max[n]=max[tright(n)];
      if(min[tleft(n)]<min[tright(n)])min[n]=min[tleft(n)];
      else min[n]=min[tright(n)];
}

int searchb(int n,int x,int y)//查询最大值
{
      int max1,max2;
      if(x==right[n]&&y==left[n])return max[n];
      if(x<=mid[n])
      {
            if(y>mid[n])
            {
                  max1=searchb(tleft(n),x,mid[n]);
                  max2=searchb(tright(n),mid[n]+1,y);
                  if(max1>max2)return max1;
                  else return max2;
            }
            else
            {
                  return searchb(tleft(n),x,y);
            }
      }
      else
      {
                  return searchb(tright(n),x,y);
      }
}

int searchs(int n,int x,int y)//查询最小值
{
      int max1,max2;
      if(x==right[n]&&y==left[n])return min[n];
      if(x<=mid[n])
      {
            if(y>mid[n])
            {
                  max1=searchs(tleft(n),x,mid[n]);
                  max2=searchs(tright(n),mid[n]+1,y);
                  if(max1<max2)return max1;
                  else return max2;
            }
            else
            {
                  return searchs(tleft(n),x,y);
            }
      }
      else
      {
                  return searchs(tright(n),x,y);
      }
}
