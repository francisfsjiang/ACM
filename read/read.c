#include<stdio.h>//- 45  .46
#include<string.h>
main()
{
      freopen("read.in","rt+",stdin);
      freopen("read.out","wt+",stdout);
      int i,j,n,l,head,end;
      char s[1000];
      scanf("%s",s);
      if(s[0]==45)printf("F");
      l=strlen(s);
      for(i=0;i<l;i++)if(head==0&&s[i]<=57&&s[i]>=49)
      printf("%d %d",s[0],s[1]);
      return(0);
}
