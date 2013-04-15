#include<stdio.h>
#include<string.h>
#define MAX 50
char name[MAX][100];
double data[MAX][MAX];
double money[MAX];
int in[MAX];
int spfa[200000];
int n;
int search(char s[])
{
    int l1,l2,i,j;
    for(i=1;i<=n;i++)
    {
        l1=strlen(s);
        l2=strlen(name[i]);
        if(l1!=l2)continue;
        for(j=0;j<l1;j++)if(s[j]!=name[i][j])continue;
        return i;
    }
}

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,head,end,temp,m,sign,t;
    double x;
    char s1[MAX],s2[MAX];
    for(t=1;;t++)
    {
        scanf("%d",&n);
        if(n==0)break;
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)data[i][j]=0;
        for(i=1;i<=n;i++)scanf("%s",name[i]);
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            scanf("%s%lf%s",s1,&x,s2);
            data[search(s1)][search(s2)]=x;
        }
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)printf("%lf ",data[i][j]);
            printf("\n");
        }*/
        memset(in,0,sizeof(in));
        for(i=2;i<=n;i++)money[i]=0;
        head=0;
        end=1;
        spfa[head]=1;
        in[1]=1;
        money[1]=1;
        sign=0;
        while(head<end)
        {
            for(i=1;i<=n;i++)
            {
                if(data[spfa[head]][i]!=0&&money[spfa[head]]*data[spfa[head]][i]>money[i])
                {
                    money[i]=money[spfa[head]]*data[spfa[head]][i];
                    //printf("%d %lf\n",i,money[i]);
                    //for(j=1;j<=n;j++)printf("%lf ",money[j]);
                    //printf("\n");
                    if(!in[i])
                    {
                        spfa[end]=i;
                        end++;
                        in[i]=1;
                    }
                    if(money[1]>1)
                    {
                        sign=1;
                        break;
                    }
                }
            }
            if(sign==1)break;
            in[spfa[head]]=0;
            head++;
        }
        //for(i=0;i<end;i++)printf("%d ",spfa[i]);
        //printf("\n");
        if(sign==0)printf("Case %d: No\n",t);
        else printf("Case %d: Yes\n",t);
    }
    return 0;
}
