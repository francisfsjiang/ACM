#include<stdio.h>
const int SIZE=105;
main()
{    
     freopen("price.in","r",stdin);    
     freopen("price.out","w+",stdout);    
     int n,m,i,j,k,stp,tmp2;
     float tmp,max=0;
     float price[SIZE][SIZE];
     float temp[SIZE][4][SIZE];//钱数/行数/第项目数 
     int step[SIZE][SIZE][2];
     memset(step,0,sizeof(step));
     memset(temp,0,sizeof(temp));
     memset(price,0,sizeof(price));
     scanf ("%d",&m);//项目数/行3     
     scanf ("%d",&n);//money/列 7
     for (i=1;i<=m;i++)
     {
         for (j=1;j<=n;j++)
         {
          scanf ("%f",&price[j][i]);
         }
     }
     for(i=1;i<=m;i++)
     {
                      for(j=0;j<=n;j++)
                      {
                                       temp[j][1][i]=temp[j][3][i-1];
                                       temp[j][2][i]=price[j][i];

                      }
                      for(j=0;j<=n;j++)
                      {                 
                                       for(k=0;k<=j;k++)
                                       {
                                                        tmp=temp[k][1][i]+temp[j-k][2][i];
                                                        if(tmp>temp[j][3][i])
                                                        {
                                                                             temp[j][3][i]=tmp;
                                                                             step[j][i][1]=j-k;
                                                                             step[j][i][2]=k;
                                                        }
                                       }
                      }
     }
     for(i=0;i<=m;i++)
     {
                      for(j=1;j<=3;j++)
                      {
                                       for(k=0;k<=n;k++)   printf("%f ",temp[k][j][i]);
                                       printf("\n");
                      }
                      printf("\n");
     }  
     
     
     for(i=1;i<=2;i++)
     {
                      for(j=0;j<=3;j++)
                      {
                                       for(k=0;k<=n;k++)   printf("%d ",step[k][j][i]);
                                       printf("\n");
                      }
                      printf("\n");
     }     
     
     for(i=1;i<=n;i++)
     {
                      if(temp[i][3][m]>max)max=temp[i][3][m];stp=i;
     }             
     for(i=m;i>=1;i--) 
     {
                       printf("项目%d资金%d万",i,step[stp][i][1]);
                       printf("\n");
                       tmp2=step[stp][i][2];
                       stp=tmp2;
     }
     printf("max=%f",max);
     return(0);
}




