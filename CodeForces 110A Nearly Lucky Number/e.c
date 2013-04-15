#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    char s[10000];
    int l,i,sum,temp;
    scanf("%s",s);
    l=strlen(s);
    sum=0;
    for(i=0;i<l;i++)
    {
        if((s[i]-48)==7||(s[i]-48)==4)
        {
            sum++;
        }
    }
    if(sum==7||sum==4)
    {
        /*for(;;)
        {
            temp=sum%10;
            if(temp!=4&&temp!=7)
            {
                printf("NO");
                break;
            }
            else if(sum<10)
            {
                printf("YES");
                break;
            }
            sum=(sum-sum%10)/10;
        }*/
        printf("YES");
    }
    else printf("NO");
    return 0;
}
