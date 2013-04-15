#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,l,sum;
    char s[300];
    while(scanf("%s",s)!=EOF)
    {
        l=strlen(s);
        sum=0;
        for(i=l-1;i>=0;i--)
        {
            if(s[i]<='z'&&s[i]>='p')
            {
                sum++;
            }
            else if(s[i]=='N')
            {
            }
            else if(s[i]=='C'||s[i]=='D'||s[i]=='E'||s[i]=='I')
            {
                sum--;
            }
            else
            {
                sum=-1;
            }
        }
        if(sum==1)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
