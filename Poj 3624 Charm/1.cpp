#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int data[13000];
int main()
{
    freopen("1.in","r",stdin);
    int n,m,w,d;
    scanf("%d%d",&n,&m);
    memset(data,0,sizeof(data));
    for(int j=0;j<n;j++)
    {
        scanf("%d%d",&w,&d);
        for(int i=m;i>=w;i--)
        {
            if(data[i]<data[i-w]+d)data[i]=data[i-w]+d;
        }
    }
    printf("%d\n",data[m]);
    return 0;
}
