#include<stdio.h>
#include<string.h>
int data[5120][5120]={0};
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    char s1[5120],s2[5120];
    int l1,l2,sum=0,i,j;
    scanf("%s",s1);
    scanf("%s",s2);
	l1=strlen(s1);
    l2=strlen(s2);
	for(i=1;i<=l1;++i)
	{
		for(j=1;j<=l2;++j)
		{
			if(s1[i-1]==s2[j-1])
			{
                data[i][j]+=data[i-1][j-1]+1;
                data[i][j]%=1000000007;
            }
			data[i][j+1]=data[i][j];
		}
		sum+=data[i][l2];
		sum=sum%1000000007;
	}
	/*printf("%c ",96);
	for(j=0;j<l2+1;++j)printf("%2c ",s2[j]);
	printf("%d\n");
	for(i=1;i<=l1;++i)
	{
        printf("%c ",s1[i-1]);
		for(j=1;j<=l2+2;++j)printf("%2d ",data[i][j]);
		printf("%d\n");
    }*/
    printf("%d\n",sum);
	return 0;
}
