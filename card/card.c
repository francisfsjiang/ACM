#include<stdio.h>
int n,sum,s[101][4],ave;
main()
{
      freopen("card.in","rt+",stdin);
      freopen("card.out","wt+",stdout);
      int i,j,temp=0;
      int move(int x,int y);
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
                      scanf("%d",&s[i][0]);
                      sum+=s[i][0];
      }
      ave=sum/n;
      //printf("n=%d\nsum=%d\nave=%d\n",n,sum,ave);
      sum=0;
      for(i=0;i<n;i++)
      {
                      s[i][1]=s[i][0]-ave;
      }
      //for(i=0;i<4;i++){{for(j=0;j<n;j++)printf("%d ",s[j][i]);}printf("\n");}
      for(i=0,j=0;j<n;j++)
      {
                          temp=temp+s[j][1];
                          if(temp==0)
                          {
                                     move(i,j);
                                     i=j+1;
                          }
      }
      for(j=0;j<n;j++)if(s[j][2]<0)sum++; 
      for(j=0;j<n;j++)if(s[j][3]<0)sum++;
      printf("%d",sum);
      return(0);
}

int move(int x,int y)
{
    if(x==y)return;
    else
    {
        int i,j,max,t1,t2;
        s[0][2]=0;
        s[n-1][2]=0;
        for(i=1;i<n-1;i++)
        {
                        
                        s[i][2]=s[i-1][1]+s[i-1][2];
                        s[n-i-1][3]=s[n-i][1]+s[n-i][3];
        }
        //for(i=0;i<4;i++){{for(j=0;j<n;j++)printf("%d ",s[j][i]);}printf("\n");}
    }
}
