#include<stdio.h>
#include<math.h>
main()
{
      freopen("Peanut.in","rt+",stdin);
      freopen("Peanut.out","wt+",stdout);
      int m,n,k,i,j,p=0,tmp,max,sum,x,y,s;
      int date[21][21],temp[4020][3];
      scanf("%d%d%d",&m,&n,&k);
      for(i=1;i<=m;i++)
      {
                       for(j=1;j<=n;j++)
                       {
                                        scanf("%d",&date[i][j]);
                                        if(date[i][j]!=0)
                                        {
                                                         temp[p][0]=date[i][j];
                                                         temp[p][1]=i;
                                                         temp[p][2]=j;
                                                         p++;
                                        }
                       }
      }
      //for(j=0;j<3;j++)
      //{
      //                 for(i=0;i<p;i++)printf("%3d",temp[i][j]);
      //                 printf("\n");
      //}
      for(i=0;i<p-1;i++)
      {
                      for(j=i;j<p-1;j++)
                      {
                                        if(temp[j][0]<temp[j+1][0])
                                        {
                                                                   //printf("j=%d\n",j);
                                                                   tmp=temp[j][0];
                                                                   temp[j][0]=temp[j+1][0];
                                                                   temp[j+1][0]=tmp;
                                                                   tmp=temp[j][1];
                                                                   temp[j][1]=temp[j+1][1];
                                                                   temp[j+1][1]=tmp;
                                                                   tmp=temp[j][2];
                                                                   temp[j][2]=temp[j+1][2];
                                                                   temp[j+1][2]=tmp;
                                        }
                      }
      }
      //for(j=0;j<3;j++)
      //{
      //                 for(i=0;i<p;i++)printf("%3d",temp[i][j]);
      //                 printf("\n");
      //}
      if(k<(2*temp[0][1]+2))printf("0");
      else
      {
          k=k-temp[0][1]-1;
          sum=temp[0][0];
          p=1;
          for(;;)
          {
                 s=abs(temp[p][1]-temp[p-1][1])+abs(temp[p][2]-temp[p-1][2])+1+temp[p][1];
                 //printf("p=%d  k=%d s=%d\n",p,k,s);
                 if(k>s)
                 {
                        sum+=temp[p][0];
                        k-=abs(temp[p][1]-temp[p-1][1])+abs(temp[p][2]-temp[p-1][2])+1;
                 }
                 else break;
                 p++;
                 
          }
          printf("%d",sum);
      }
      return(0);
}
                                        
