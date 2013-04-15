#include<stdio.h>
int main()
{
    int n,k,s=0;
	scanf("%d%d",&k,&n);
	while(n>k&&n%k==0)
	{
        s++;
        n=n/k;
    }
	if(n!=k)printf("NO\n");
	else printf("YES\n%d\n",s);
}
