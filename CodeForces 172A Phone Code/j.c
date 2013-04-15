#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,l,i,j,t1,t2,datal,max,maxn,k;
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
        memset(&temp[0][0],0,sizeof(temp));
        for(i=1;i<=l;i++)
        {
            for(j=1;j<=datal;j++)
            {
                if(s[i-1]==data[j-1])temp[i][j]=temp[i-1][j-1]+1;
            }
        }
        /*for(i=0;i<=l;i++)
        {
            for(j=0;j<=datal;j++)
            {
                printf("%d ",temp[i][j]);
            }
            printf("\n");
        }*/
        max=0;
        for(i=0;i<=l;i++)for(j=0;j<=datal;j++)
        {
            if(temp[i][j]>max)
            {
                max=temp[i][j];
                maxn=j;
            }
        }
        if(max==0)
        {
            printf("0");
            return 0;
        }
        datal=max;
        for(i=0;i<max;i++)
        {
            data[i]=data[maxn-max+i];
        }
        for(i=0;i<max;i++)printf("%d ",data[i]);
        printf("\n");
    }
    printf("%d",datal);
    return 0;
}
