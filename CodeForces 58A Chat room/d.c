#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,i,l,sign;
    char s[1000];
    int data[10];
    scanf("%s",s);
    l=strlen(s);
    data[1]='h';
    data[2]='e';
    data[3]='l';
    data[4]='l';
    data[5]='o';
    sign=1;
    //printf("%s\n",s);
    for(i=0;i<l;i++)
    {
        if(s[i]==data[sign])
        {
            //printf("%d %d\n",data[sign],s[i]);
            sign++;
            if(sign==6)break;
        }
    }
    if(sign==6)printf("YES");
    else printf("NO");
    return 0;
}
