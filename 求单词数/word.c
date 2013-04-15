#include<stdio.h>
#include<string.h>
main()
{
      freopen("word.in","rt+",stdin);    
      freopen("word.out","wt+",stdout);
      char s[20000];
      int i,n=0,l;
      gets(s);
      l=strlen(s);
      for(i=0;i<l;i++)printf("%c",s[i]);
      for(i=0;i<l;i++)if((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122))n++;  //(s[i]<65||s[i]>90)&&(s[i]<97&&s[i]>122)
      printf("%d\n",l-n+1);
}
