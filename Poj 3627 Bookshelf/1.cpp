#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int data[20020];
bool cmp(const int& a,const int& b)
{
    return a>b;
}
int main()
{
    freopen("1.in","r",stdin);
    int n,m,sum;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)scanf("%d",&data[i]);
        sort(data,data+n,cmp);
        sum=0;
        for(int i=0;i<n;i++)
        {
            if(sum>=m)
            {
                printf("%d\n",i);
                break;
            }
            sum+=data[i];
        }
    }
}
