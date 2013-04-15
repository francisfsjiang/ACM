#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,i,data[1000];
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&data[i]);
    for(i=1;i<=256;i++)printf("%d  %d\n",i,search(data,i,1,n));
    return 0;
}

int search(int data[],int key,int s,int t)
{
    //printf("%d %d\n",s,t);
    int mid=(t-s)/2+s;
    if(key==data[mid])return mid;
    else if(data[mid]>key&&s<=mid-1)
    {
        return search(data,key,s,mid-1);
    }
    else if(data[mid]<key&&t>=mid+1)
    {
        return search(data,key,mid+1,t);
    }
    else return -1;
}
