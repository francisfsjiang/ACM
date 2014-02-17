#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int data[20020];
int main()
{
    freopen("1.in","r",stdin);
    int n,m,sum,i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)scanf("%d",&data[i]);
        sort(data,data+n);
        i=0;
        j=n-1;
        sum=0;
        while(i<j)
        {
            while((data[i]+data[j]>m)&&i<j)j--;

            sum+=j-i;
            //cout<<i<<" "<<j<<endl;
            //cout<<sum<<endl;
            i++;
        }
        printf("%d\n",sum);
    }
}
