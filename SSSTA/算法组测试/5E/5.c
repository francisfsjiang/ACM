#include<stdio.h>
int data[100005][4],num[100005],spfa[200000],sum[100005],in[100005];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,k,head,end,temp,a,b,c,summer,t,n,m,now;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
                    summer=0;
                    scanf("%d%d",&n,&m);
                    for(i=0;i<=n;i++)sum[i]=2147483640;
                    for(i=0;i<=n;i++)num[i]=-1;
                    for(i=0;i<=n;i++)in[i]=0;
                    for(i=0;i<m;i++)
                    {
                                    scanf("%d%d%d",&data[i][0],&data[i][1],&data[i][2]);
                                    data[i][3]=num[data[i][0]];
                                    num[data[i][0]]=i;
                    }
                    /*for(i=0;i<m;i++)printf("%3d ",i);
                    printf("\n");
                    for(i=0;i<m;i++)printf("%3d ",data[i][0]);
                    printf("\n");
                    for(i=0;i<m;i++)printf("%3d ",data[i][1]);
                    printf("\n");
                    for(i=0;i<m;i++)printf("%3d ",data[i][2]);
                    printf("\n");
                    for(i=0;i<m;i++)printf("%3d ",data[i][3]);
                    printf("\n");
                    for(i=0;i<n;i++)printf("%3d ",num[i]);
                    printf("\n");*/
                    end=1;
                    head=0;
                    spfa[0]=0;
                    sum[0]=0;
                    in[0]=1;
                    for(;head<end;)
                    {
                                   now=num[spfa[head]];
                                   for(;now!=-1;)
                                   {
                                          //printf("%d\n",now);
                                          //data[i][0] data[i][1]
                                          if(sum[data[now][0]]+data[now][2]<sum[data[now][1]])
                                          {
                                                  sum[data[now][1]]=sum[data[now][0]]+data[now][2];
                                                  if(in[data[now][1]]==0)
                                                  {
                                                                       spfa[end]=data[now][1];
                                                                       end++;
                                                                       in[data[now][1]]=1;
                                                  }
                                          }
                                          now=data[now][3];
                                   }
                                   in[spfa[head]]=0;
                                   head++;
                    }
                    for(i=1;i<=n;i++)if(sum[i]!=2147483640)summer+=sum[i];
                    /*for(i=1;i<=n;i++)printf("%d ",sum[i]);
                    printf("\n");*/
                    printf("%d\n",summer);
    }
    return 0;
}
