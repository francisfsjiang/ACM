#include<stdio.h>
int w[900001][4];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t=0;
    int i,max=0;
    int n,m;
    scanf("%d",&t);
    for(;t>=1;t--)
    {memset(w,0,sizeof(w));
     max=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {scanf("%d",&w[i][0]);
     w[i][1]=1;
     w[i][2]=w[i][0];
     w[i][3]=w[i][0];}
    
    for(i=1;i<n;i++)
    if(w[i][0]-w[i-1][2]<=m&&w[i][0]-w[i-1][2]>=(-1)*m&&w[i][0]-w[i-1][3]<=m&&w[i][0]-w[i-1][3]>=(-1)*m)
    if(w[i][1]<w[i-1][1]+1)
    {w[i][1]=w[i-1][1]+1;
     if(w[i][0]>w[i-1][2]) w[i][2]=w[i-1][2];
     if(w[i][0]<w[i-1][3]) w[i][3]=w[i-1][2];  }
    
    for(i=0;i<n;i++)
    printf("%d-%d-%d-%d\n",w[i][0],w[i][1],w[i][2],w[i][3]);
    
    for(i=0;i<n;i++)
    if(w[i][1]>max) max=w[i][1];
    
    printf("%d\n",max);
}
    return 0;
}
