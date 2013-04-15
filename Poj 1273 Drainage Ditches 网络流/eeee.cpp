

#include <stdio.h>
int a[201][201];
int n,m;

int max()
{
     int list[100000];
int head,tail;
int jud[201]={0};
int pre[201]={0};
head=0;
tail=0;
jud[1]=1;
     list[head++]=1;
int tt,i,k=0;
int min=1000000;
while (tail<head)
{

    tt=list[tail];
for (i=1;i<=m;i++)
if (a[tt][i]>0 && !jud[i])
{
list[head++]=i;
jud[i]=1;
            pre[i]=tt;
if (i==m)
{k=1;break;}
}

tail++;
   if (k==1) break;

}

if (k==0) return 0;

while (pre[i]!=0)
{
if (a[pre[i]][i]<min) min=a[pre[i]][i];
i=pre[i];
}
i=m;
while (pre[i]!=0)
{
a[pre[i]][i]-=min;
a[i][pre[i]]=min;
i=pre[i];
}
     return min;
}

int main()
{
freopen("in.in","r",stdin);
freopen("out.out","w",stdout);
int sum=0;
int x;
    int i,j,k,tt;
while(scanf("%d%d",&n,&m)!=EOF)
{
        sum=0;
for (i=0;i<=200;i++)
for (j=0;j<=200;j++)
a[i][j]=0;
for (i=0;i<n;i++)
{
                scanf("%d%d",&j,&k);
scanf("%d",&tt);
                a[j][k]+=tt;
}
x=max();
while (x!=0) {
sum=sum+x;
    x=max();
}
printf("%d\n",sum);
}
return 0;
}
