#include<stdio.h>
int j,date[70][10]={0};//物品编号，0附件数，1主件钱数，2主件收益，3附件1钱数 ，4附件1收益，5附件2钱数，6附件2收益 
main()
{
      freopen("budget.in","r",stdin);
      freopen("budget.out","w+",stdout);
      int f(int x,int y);
      int i,j,m,n,x,y,z;
      scanf("%d%d",&m,&n);
      for(i=0,j=0;i<n;i++)
      {
                      scanf("%d%d%d",&x,&y,&z);
                      //printf("%d %d %d\n",x,y,z);
                      if(z==0)
                      {
                              date[j][1]=x;
                              date[j][2]=x/10*y;
                              j++;
                      }
                      else
                      {
                          date[z-1][0]++;
                          date[z-1][date[z-1][0]*2+1]=x;
                          date[z-1][date[z-1][0]*2+2]=x/10*y;
                      }
      }
      //for(i=0;i<j;i++)printf("%d %d (%d %d) (%d %d) (%d %d)\n",i,date[i][0],date[i][1],date[i][2],date[i][3],date[i][4],date[i][5],date[i][6]);
      printf("%d\n",f(m,0)*10);
      return(0);
}

int f(int x,int y)
{
    int temp,max=0;
    if(y==5)return 0;
    temp=f(x,y+1);
    if(temp>max)max=temp;
    if(x-date[y][1]>=0)
    {temp=f(x-date[y][1],y+1)+date[y][2];
    if(temp>max)max=temp;}
    else return 0;
    if(date[y][0]>=1&&x-date[y][1]-date[y][3]>=0)
    {
                     temp=f(x-date[y][1]-date[y][3],y+1)+date[y][2]+date[y][4];
                     if(temp>max)max=temp;
    }
    if(date[y][0]==2)
    {
                     if(x-date[y][1]-date[y][3]-date[y][5]>=0)
                     {temp=f(x-date[y][1]-date[y][3]-date[y][5],y+1)+date[y][2]+date[y][4]+date[y][6];
                     if(temp>max)max=temp;}
                     if(x-date[y][1]-date[y][5]>=0)
                     {temp=f(x-date[y][1]-date[y][5],y+1)+date[y][2]+date[y][6];
                     if(temp>max)max=temp;}
    }
    //printf("f(%d,%d)=%d\n",x,y,max);
    return(max);
}
