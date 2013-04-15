#include<stdio.h>
#include<string.h>
main()
{
      freopen("missile.in","rt+",stdin);
      freopen("missile.out","wt+",stdout);
      int i,j,n,s[10001][2],max,sys[10001],sysn=0;
      while(scanf("%d",&n)!=EOF)
      {
      sysn=0;
        memset(s,0,sizeof(s));
        memset(sys,0,sizeof(sys));
        for(i=0;i<n;i++)
        {
                      scanf("%d",&s[i][0]);
                      max=0;
                      for(j=i-1;j>=0;j--)
                      {
                                         if(s[j][0]>s[i][0])if(max<s[j][1])max=s[j][1];
                      }
                      s[i][1]=max+1;
                      for(j=0;j<=sysn;j++)
                      {
                                          if(sys[j]==0)
                                          {
                                                       sys[j]=s[i][0];
                                                       sysn++;
                                                       break;
                                          }
                                          else if(s[i][0]<sys[j])
                                          {
                                               sys[j]=s[i][0];
                                               break;
                                          }
                      }

        }
        for(i=0;i<n;i++)printf("%2d ",s[i][0]);
        printf("\n");
        for(i=0;i<n;i++)printf("%2d ",s[i][1]);
        printf("\n");
        for(i=0;i<n;i++)printf("%2d ",sys[i]);
        printf("\n");
        max=0;
        for(i=0;i<n;i++)if(max<s[i][1])max=s[i][1];
        printf("%d\n",sysn);
    }
      return(0);
}
