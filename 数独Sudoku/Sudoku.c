#include<stdio.h>
int date[10][10];
int nine[10][10]=
{
{0,0,0,0,0,0,0,0,0,0},
{0,1,1,1,2,2,2,3,3,3},
{0,1,1,1,2,2,2,3,3,3},
{0,1,1,1,2,2,2,3,3,3},
{0,4,4,4,5,5,5,6,6,6},
{0,4,4,4,5,5,5,6,6,6},
{0,4,4,4,5,5,5,6,6,6},
{0,7,7,7,8,8,8,9,9,9},
{0,7,7,7,8,8,8,9,9,9},
{0,7,7,7,8,8,8,9,9,9}};
int recordh[10][10],records[10][10],record9[10][10];
int divide=0;
int sum[100000],sumn=1;
main()
{
      int i,j,k,tempx,tempy,w=0;
      int search(int x,int y);
      freopen("Sudoku.in","rt+",stdin);
      freopen("Sudoku.out","wt+",stdout);
      for(i=1;i<=9;i++)
      {
                       for(j=1;j<=9;j++)
                       {
                                        scanf("%d",&date[i][j]);
                       }
      }
      //for(i=1;i<=9;i++){for(j=1;j<=9;j++){printf("%d ",date[i][j]);}printf("\n");}
      //printf("\n");
      for(i=1;i<=9;i++)//记录数字使用状态 
      {
                       for(j=1;j<=9;j++)
                       {
                                        if(date[i][j]!=0)
                                        {
                                                         recordh[i][date[i][j]]=1;
                                                         records[j][date[i][j]]=1;
                                                         record9[nine[i][j]][date[i][j]]=1;
                                        }
                       }
      }
      //for(i=1;i<=9;i++){for(j=1;j<=9;j++){printf("%d ",recordh[i][j]);}printf("\n");}
      //printf("\n");
      //for(i=1;i<=9;i++){for(j=1;j<=9;j++){printf("%d ",records[i][j]);}printf("\n");}
      //printf("\n");
      //for(i=1;i<=9;i++){for(j=1;j<=9;j++){printf("%d ",record9[i][j]);}printf("\n");}
      //printf("\n");
      tempx=1;
      tempy=1;
      w=0;
      for(i=1;i<=9;i++)
      {
                       for(j=1;j<=9;j++)
                       {
                                        if(date[i][j]==0)
                                        {
                                                                         tempx=i;
                                                                         tempy=j;
                                                                         w=1;
                                                                         break;
                                        }
                       }
                       if(w==1)break;
      }
      //printf("%d\n",1);
      search(tempx,tempy);
      //for(i=sumn-1;i>=0;i--)printf("%d",sum[i]);
      //printf("\n");
      //for(i=1;i<=9;i++){for(j=1;j<=9;j++){printf("%d ",date[i][j]);}printf("\n");}
      //printf("\n");
      return(0);
}

int search(int x,int y)
{
    int i,j,tempx,tempy,w=0,m,n;
    //if(divide==1)return(0);
    //else
    //{
    for(i=1;i<=9;i++)
    {
                     if(recordh[x][i]==0&&records[y][i]==0&&record9[nine[x][y]][i]==0)
                     {
                                                                                  date[x][y]=i;
                                                                                  recordh[x][i]=1;
                                                                                  records[y][i]=1;
                                                                                  record9[nine[x][y]][i]=1;
                                                                                  if(x==9&&y==9)
                                                                                  {
                                                                                                //divide=1;
                                                                                                //sum[0]++;
                                                                                                //for(m=0;m<sumn;m++)
                                                                                                //if(sum[m]>9)
                                                                                                //{
                                                                                                //            if(m+1==sumn&&sum[sumn]==0){sumn++;printf("%d\n",sumn);}
                                                                                                //            sum[m]=0;
                                                                                                //            sum[m+1]++;
                                                                                                //}
                                                                                                //for(m=sumn-1;m>=0;m--)printf("%d",sum[m]);
                                                                                                //printf("\n");
                                                                                                //printf("%d\n",sum);
                                                                                                for(m=1;m<=9;m++){for(n=1;n<=9;n++){printf("%d ",date[m][n]);}printf("\n");}
                                                                                                printf("\n");
                                                                                  }
                                                                                  tempx=1;
                                                                                  tempy=1;
                                                                                  w=0;
                                                                                  for(m=1;m<=9;m++)
                                                                                  {
                                                                                                   for(n=1;n<=9;n++)
                                                                                                   {
                                                                                                                    if(date[m][n]==0)
                                                                                                                    {
                                                                                                                                     tempx=m;
                                                                                                                                     tempy=n;
                                                                                                                                     w=1;
                                                                                                                                     break;
                                                                                                                    }
                                                                                                   }
                                                                                                   if(w==1)break;
                                                                                  }
                                                                                  search(tempx,tempy);
                                                                                  date[x][y]=0;
                                                                                  recordh[x][i]=0;
                                                                                  records[y][i]=0;
                                                                                  record9[nine[x][y]][i]=0;
                     }
    }
    //}
}
