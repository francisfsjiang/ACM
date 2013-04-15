#include<stdio.h>
int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    char s[400];
    int n,i;
    scanf("%d",&n);
    scanf("%s",s);
    for(i=1;i<=n/2;i++)
    {
        if(s[i-1]=='L')printf("%d %d\n",i,n/2+i);
        else printf("%d %d\n",n/2+i,i);
    }
    return 0;
}
