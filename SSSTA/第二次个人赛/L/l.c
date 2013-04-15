#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int len,line,i;
    char s[20000];
    line=0;
    while(scanf("%s",s)!=EOF)//, 44 _32  new 10
    {
        if(s[0]=='<')
        {
            if(s[1]=='b')
            {
                printf("\n");
                line=0;
            }
            else
            {
                if(line!=0)printf("\n");
                for(i=0;i<80;i++)printf("-");
                printf("\n");
                line=0;
            }
        }
        else
        {
            len=strlen(s);
            if(line+len+1>80)
            {
                printf("\n%s",s);
                line=len+1;
            }
            else
            {
                if(line!=0)printf(" ");
                printf("%s",s);
                line+=len+1;
            }
        }
    }
    printf("\n");
    return 0;
}
