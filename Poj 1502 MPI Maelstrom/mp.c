#include<stdio.h>
#include<string.h>
#define MAX 110
int data[MAX][MAX];
int spfa[2000000];
int in[MAX];
int re[MAX];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,k,temp,n,l,head,end,d,max;
    char s[200];
    while(scanf("%d",&n)!=EOF)
    {
        memset(data,0,sizeof(data));
        for(i=2;i<=n;i++)
        {
            for(j=1;j<i;j++)
            {
                scanf("%s",s);
                //printf("%s\n",s);
                if(s[0]=='x')
                {
                    data[i][j]=-1;
                    data[j][i]=-1;
                }
                else
                {
                    l=strlen(s);
                    temp=1;
                    data[i][j]=0;
                    for(k=l-1;k>=0;k--)
                    {
                        data[i][j]+=(s[k]-'0')*temp;
                        temp*=10;
                    }
                    data[j][i]=data[i][j];
                }
            }
        }
        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)printf("%d ",data[i][j]);
            printf("\n");
        }*/
        memset(in,0,sizeof(in));
        memset(re,-1,sizeof(re));
        head=0;
        end=1;
        spfa[head]=1;
        in[1]=1;
        re[1]=0;
        while(head<end)
        {
            d=spfa[head];
            for(i=1;i<=n;i++)
            {
                if(data[d][i]!=-1&&(re[i]==-1||re[i]>data[d][i]+re[d]))
                {
                    re[i]=data[d][i]+re[d];
                    if(!in[i])
                    {
                        spfa[end]=i;
                        end++;
                        in[i]=1;
                    }
                }
            }
            in[d]=0;
            head++;
        }
        //for(i=1;i<=n;i++)printf("%d ",re[i]);
        max=-999;
        for(i=1;i<=n;i++)if(re[i]>max)max=re[i];
        printf("%d\n",max);
    }
    return 0;
}
