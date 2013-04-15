#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    char xx[1000],s[1000];
    int i,j,n,max,temp,l,x,y;
    scanf("%d",&n);
    max=-9999999;
    for(i=1;i<=n;i++)
    {
        scanf("%s",xx);
        /*printf("%s\n",xx);
        l=strlen(xx);
        printf("%d\n",l);
        for(j=0;j<l;j++)printf("%c",xx[j]);
        printf("\n");*/
        scanf("%d%d",&x,&y);
        temp=x*100-y*50;
        scanf("%d",&x);
        temp+=x;
        scanf("%d",&x);
        temp+=x;
        scanf("%d",&x);
        temp+=x;
        scanf("%d",&x);
        temp+=x;
        scanf("%d",&x);
        temp+=x;
        //printf("%d\n",temp);
        if(temp>max)
        {
            l=strlen(xx);
            /*for(j=0;j<l;j++)printf("%d ",s[j]);
            printf("\n");
            for(j=0;j<l;j++)printf("%d ",xx[j]);
            printf("\n");*/
            for(j=0;j<l;j++)s[j]=xx[j];
            max=temp;
        }
    }
    //for(j=l;j<=30;j++)s[j]=0;
    for(j=0;j<l;j++)printf("%c",s[j]);
    return 0;
}
