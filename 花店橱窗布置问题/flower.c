#include<stdio.h>
int date[100][100],temp[100][100],step[100][100]; 
int m,n;
main()
{
      int i,j,k,stp;
      int tmp,p=0;
      int max(int x,int y);
      freopen("flower.in","rt+",stdin);
      freopen("flower.out","wt+",stdout);
      scanf("%d%d",&m,&n);
      for(i=0;i<m;i++)
      {
                      for(j=0;j<n;j++)
                      {
                                      scanf("%d",&date[i][j]);
                      }
      }
      for(i=0;i<m;i++){for(j=0;j<n;j++){temp[i][j]=-100;}}
      for(j=0;j<n;j++)temp[m-1][j]=date[m-1][j];
      for(i=0;i<=n-m;i++)
      {
                         tmp=max(0,i);
                         if(tmp>p)
                         {
                         p=tmp;
                         stp=i;
                         }
      }
      printf("%d\n",p);
      printf("%d ",stp+1);
      for(i=0;i<m-1;i++)
      {
                      printf("%d ",step[i][stp]+1);
                      stp=step[i][stp];
      }
      return(0);
}

max(int x,int y)
{
        int i,s=0,stp,tmp;
        if(temp[x][y]!=-100)return(temp[x][y]);
        else 
        {
             for(i=y+1;i<=x+n-m+1;i++)
             {
                                    tmp=max(x+1,i);
                                    if(tmp>s)
                                    {
                                             s=tmp;
                                             stp=i;
                                    }
             }
             step[x][y]=stp;
             temp[x][y]=s+date[x][y];
             return(temp[x][y]);
        }
}
