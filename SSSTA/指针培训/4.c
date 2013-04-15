#include<stdio.h>
#include<string.h>
int main()
{
    char *stMatching(char *a,char b[]);
    char s1[1000],s2[1000];
    //while(scanf("%s%s",s1,s2)!=EOF)
   // {
    scanf("%s %s",s1,s2);
        printf("%s\n",stMatching(s1,s2));
   // }
    return 0;
}

char *stMatching(char *a,char b[])
{
    int l1,l2,sign=0,i,j;
    l1=strlen(a);
    l2=strlen(b);
    for(i=0;i<=l1-l2;i++)
    {
        for(j=0;j<l2;j++)
        {
            //printf("%d %d\n",i,j);
            if(a[i+j]!=b[j]) break;
        }
        if(j==l2)
        {
        sign=1;
        break;
        }
    }
    if(sign==1)return ("YES");
    else return ("NO");
}
