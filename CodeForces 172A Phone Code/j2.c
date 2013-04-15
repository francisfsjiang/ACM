#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,l,i,datal,k;
    int data[100];
    char s[100];
    scanf("%d",&n);
    scanf("%s",s);
    l=strlen(s);
    datal=l;
    for(i=0;i<l;i++)data[i]=s[i];
    for(k=2;k<=n;k++)
    {
        scanf("%s",s);
        for(i=0;i<datal&&s[i]==data[i];i++);
        datal=i;
    }
    printf("%d",datal);
    return 0;
}
