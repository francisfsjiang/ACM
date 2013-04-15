#include<stdio.h>
int minv[21];
int mins[21];
int N,M,best;
int main()
{
    int i;
    scanf("%d%d",&N,&M);
    int min(int x,int y);
    int XXOO(int step,int v,int s,int r,int h);
    mins[0]=0; minv[0]=0;
    for(i=1;i<=M;++i)
    {
                 mins[i]=mins[i-1]+2*i*i;
                 minv[i]=minv[i-1]+i*i*i;
    }
    /*for(i=0;i<=M;++i)
    {
                 printf("%d",mins[i]);
                 printf(" %d\n",minv[i]);
    }*/
    best=2147483640;
    XXOO(M,0,0,N,N);
    printf("%d\n",best);
    return 0;
}

int min(int x,int y)
{
    if(x>y)return y;
    else return x;
}

int XXOO(int step,int v,int s,int r,int h)
{
     if(step==0)
     {
                 if(v==N&&best>s)
                 best=s;
                 return 0;
     }
     if(s+mins[step-1]>=best||v+minv[step-1]>N||2*(N-v)/r+s>=best) return 0;
     int i,j,maxr,maxh;
     for(i=r-1;i>=step;--i)
     {
                           maxh=min((N-v-minv[step-1])/(i*i),h-1);
                           if(step==M) s=i*i;
                           for(j=maxh;j>=step;--j) XXOO(step-1,v+i*i*j,s+2*i*j,i,j);
     }
}
