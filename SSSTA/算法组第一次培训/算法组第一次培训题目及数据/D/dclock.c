#include<stdio.h>
int move[10][10]={{4,1,2,4,5},
          {3,1,2,3},
          {4,2,3,5,6},
          {3,1,4,7},
          {5,2,4,5,6,8},
          {3,3,6,9},
          {4,4,5,7,8},
          {3,7,8,9},
          {4,5,6,8,9}};
int step[10];
int data[10];
int main()
{
          freopen("outclock.out","w",stdout);
          int XXOO(int x);
          memset(data,0,sizeof(data));
          memset(step,0,sizeof(step));
          XXOO(0);
          return 0;
}

int XXOO(int x)
{
int i,j,sum=0;
    if(x==9)
    {
      //for(i=1;i<=9;i++)printf("%d ",data[i]);
      //printf("\n");
      sum=0;
      for(i=1;i<=9;i++)if(data[i]%4==0)sum++;
      if(sum==8)
      {
                for(i=0;i<9;i++)printf("%d ",step[i]);
                printf("\n");
                for(i=1;i<=9;i++)if(data[i]%4!=0)printf("%d\n",i);
      }
      return ;
    }
      
      
      for(j=1;j<=3;j++)
      {
             for(i=1;i<=move[x][0];i++)
             {
                              data[move[x][i]]++;
             }
             step[x]++;
             XXOO(x+1);
             
      }
      for(i=1;i<=move[x][0];i++)
      {
                                data[move[x][i]]-=3;
      }
      step[x]-=3;
}
             
