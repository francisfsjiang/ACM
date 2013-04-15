#include<stdio.h>
int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int m,r,d,j,i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
                    scanf("%d%d%d",&m,&r,&d);
                    if(m>=r+d)
                    {
                              printf("%d\n",r+d);
                    }
                    else
                    {
                        if(m%2==0)printf("%d\n",r);
                        else printf("%d\n",d);
                    }
    }
    return 0;
}
