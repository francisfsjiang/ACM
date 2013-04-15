#include<stdio.h>
#include<string.h>
char s[101][71];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int now,end,l;
    char temp[71];
    now=0;
    end=0;
    while(1)
    {
        scanf("%s",temp);
        if(temp[0]=='Q')
        {
            return 0;
        }
        else if(temp[0]=='V')
        {
            now++;
            scanf("%s",s[now]);
            printf("%s\n",s[now]);
            end=now;
        }
        else if(temp[0]=='B')
        {
            //if(now==end)now-=2;
            //else now--;
            now--;
            //printf("%d\n",now);
            if(now==0)
            {
                printf("http://www.acm.org/\n");
            }
            else if(now<0)
            {
                printf("Ignored\n");
                now=0;
            }
            else printf("%s\n",s[now]);
        }
        else if(temp[0]=='F')
        {
            now++;
            if(now>end)
            {
                now=end;
                printf("Ignored\n");
            }
            else printf("%s\n",s[now]);
        }
    }
    return 0;
}

