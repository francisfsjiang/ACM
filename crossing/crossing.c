#include<stdio.h>
int m,n,date[1000][100],sum[1000],temp[1000],summer;
main()
{
      freopen("crossing.in","rt+",stdin);
      freopen("crossing.out","wt+",stdout);
      int i,j,k,a,b;
      int sch(int x,int y);
      scanf("%d%d",&m,&n);
      for(i=0;i<n;i++)
      {
                      scanf("%d%d",&a,&b);
                      date[a][b]=1;
      }
      for(i=1;i<=m;i++)
      {
                      for(j=1;j<=n;j++)printf("%d ",date[i][j]);
                      printf("\n");
      }
      temp[1]=1;
      sch(1,1);
      for(i=1;i<=m;i++)printf("%d ",sum[i]);
      printf("\nsummer=%d\n",summer);
      for(i=2;i<m;i++)if(sum[i]==summer)printf("%d ",i);
      return(0);
}


int sch(int x,int y)
{
    int i,j;
    printf("sch(%d,%d)\n",x,y);
    for(i=1;i<=m;i++)printf("%d ",temp[i]);
    printf("\n");
    if(y==m)
    {
            
            summer++;
            for(i=1;i<=m;i++)sum[temp[i]]++;
            return;
    }
    else
    {
        for(i=1;i<=m;i++)
        {
                        if(date[y][i]==1)
                        {
                                         temp[x+1]=i;
                                         sch(x+1,i);
                                         temp[x+1]=0;
                        }
        }
    }
}
