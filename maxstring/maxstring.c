#include<stdio.h>
#include<string.h>
const int SIZE=500;
main()
{
     freopen("maxstring.in","r",stdin);
     freopen("maxstring.out","w+",stdout);
     char c1[SIZE],c2[SIZE];
     int temp[SIZE][SIZE];
     int i,j,k,l1,l2,l=0;
     memset(temp,0,sizeof(temp));
     scanf("%s",c1);
     scanf("%s",c2);
     printf("%s\n",c1);
     printf("%s\n",c2);
     l1=strlen(c1);
     l2=strlen(c2);
     if(l1>l)l=l1;
     else l=l2;
     for(i=1;i<=l;i++)
     {
                      for(j=1;j<=l;j++)
                      {
                                       printf("%d",temp[j][i]);
                      }
                      printf("\n");
     }
     printf("\n");
     for(i=1;i<=l;i++)
     {
                      for(j=1;j<=l;j++)
                      {
                                       if(c1[i-1]==c2[j-1])temp[i][j]=temp[i-1][j-1]+1;
                                       else
                                       {
                                           if(temp[i][j-1]>temp[i-1][j])temp[i][j]=temp[i-1][j-1]+1;
                                           else temp[i][j]=temp[i-1][j];
                                       }
                      }
     }
     for(i=0;i<=l;i++)
     {
                      for(j=0 ;j<=l;j++)
                      {
                                       printf("%d",temp[j][i]);
                      }
                      printf("\n");
     }
     printf("\n");
     
      
      
}
