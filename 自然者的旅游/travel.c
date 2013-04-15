#include<stdio.h>
unsigned long int date[1000][1002],step[1002][1002],stepsum[1002][1002];
int main()
{    
     freopen("travel.in","rt+",stdin);
     freopen("travel.out","wt+",stdout);
     unsigned long int n,m,k,w,money;
     int i,j,p,minner;
     unsigned long int min;
     unsigned long int rc[1002];
     scanf("%ld %ld %ld %ld",&n,&m,&k,&w);
     printf("%ld %ld %ld %ld",n,m,k,w);
     printf("\n");
     memset(step,0,sizeof(step));
     memset(date,0,sizeof(date));
     memset(stepsum,0,sizeof(stepsum));
     memset(rc,0,sizeof(rc));
     for(i=1;i<=m;i++)
     {
                     for(j=1;j<=n;j++)
                     {
                                     scanf("%ld",&date[i][j]);
                     }
     }
     printf("date\n");
     for(i=0;i<=m;i++)
     {
                     for(j=0;j<=n;j++)
                     {
                                     printf("%ld ",date[i][j]);
                     }
                     printf("\n");
     }
     for(i=2;i<=n;i++)
     {
                     printf("------------------------------------------------------------\n");
                     min=4294967290;
                     minner=5000;
                     for(p=1;p<=m;p++)
                     {
                                     
                                     if(step[p][i-1]==p||i==2)money=date[p][i-1];
                                     else money=date[p][i-1]+w;
                                     if(money<min&&stepsum[p][i-1]<k)
                                     {
                                                                            min=money;
                                                                            minner=p;
                                     }
                     }
                     printf("minner=%d\n",minner);
                     printf("min=%d\n",min);
                     for(j=1;j<=m;j++)
                     {
                                     date[j][i]=min+date[j][i];
                                     step[j][i]=minner;
                                     if(minner==j)stepsum[j][i]=stepsum[j][i-1]+1;
                     }
                     printf("------------------------------------------------------------\n");
     }
     printf("\n");
     printf("final date\n");
     for(i=0;i<=m;i++)
     {
                     for(j=0;j<=n;j++)
                     {
                                     printf("%ld ",date[i][j]);
                     }
                     printf("\n");
     }
     printf("\n");
     printf("step\n");
     for(i=0;i<=m;i++)
     {
                     for(j=0;j<=n;j++)
                     {
                                     printf("%ld ",step[i][j]);
                     }
                     printf("\n");
     }
     printf("\n");
     printf("stepsum\n");
     for(i=0;i<=m;i++)
     {
                     for(j=0;j<=n;j++)
                     {
                                     printf("%ld ",stepsum[i][j]);
                     }
                     printf("\n");
     }
     min=date[1][n];
     minner=1;
     for(p=2;p<=m;p++)
     {
                      if(date[p][n]<min)
                      {
                                        min=date[p][n];
                                        minner=p;
                      }
     }
     rc[n+1]=minner;
     printf("minner=%d\n",minner);
     printf("min=%d\n",min);
     for(i=n;i>0;i--)rc[i]=step[minner][i];minner=step[minner][i];
     for(i=2;i<=n+1;i++)printf("%d ",rc[i]);
     return(0);
}

