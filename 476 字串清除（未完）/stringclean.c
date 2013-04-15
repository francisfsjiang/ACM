#include<stdio.h>
#include<string.h>
main()
{
      freopen("stringclean.in","r",stdin);
      freopen("stringclean.out","w+",stdout);
      char a[300],b[300];
      int move[300]={0},sum=0,i,j,k,la,lb,next[300]={0};
      scanf("%s%s",a,b);
      la=strlen(a);
      lb=strlen(b);
      for(i=1;i<la;i++)
      {
                       k=next[i-1];
                       if(a[k]==a[i])
                       {
                                     next[i]=k+1;
                                     continue;
                       }
                       for(;k>0;)
                       {
                                          k=next[k];
                                          if(a[k+1]==a[i])
                                          {
                                                          next[i]=k+1;
                                                          break;
                                          }
                       }
      }
      for(i=0;i<la;i++)printf("%d ",next[i]);
      printf("\n");
      j=0;
      i=0;
      while(j<lb)
      {
                 printf("%d %d\n",i,j);
                 if(a[i]==b[j])
                 {
                               i++;
                               if(move[j]==0)j++;
                               else j=move[j];
                               if(i==la)
                               {
                                        sum++;
                                        move[j-la-1]=j;
                                        printf("move[%d]=%d\n",j-la-1,j);
                                        j=j-la-la-1;
                                        if(j<0)j=0;
                                        printf("%d\n",j);
                                        i=0;
                                        for(k=0;k<lb;k++)
                                        {
                                                         if(move[k]==0)printf(" %c ",b[k]);
                                                         else {printf(" %c ",b[k]);k=move[k]-1;}
                                        }
                                        printf("\n");
                                        for(k=0;k<lb;k++)
                                        {
                                                         if(move[k]==0)printf("%2d ",k);
                                                         else {printf("%2d ",k);k=move[k]-1;}
                                        }
                                        printf("\n");
                                        continue;
                               }
                 }
                 else
                 {
                     i=next[i];
                 }
                 if(i<=0)
                 {
                        if(move[j]==0)j++;
                        else j=move[j];
                                   i++;
                 }
      }
      printf("%d",sum);
      return 0;
}
