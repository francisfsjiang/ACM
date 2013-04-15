#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int sticks[66];
int used[66];
int n,sum,OriginLength;
int main()
{
    int i;
    int quicksort(int data[],int s,int t);
    int search(int num,int length,int total);
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&sticks[i]);
            sum+=sticks[i];
            used[i]=0;
        }
        quicksort(sticks,0,n-1);//剪枝1：将所有小木棍按降序排序，加快搜索。
        //for(i=0;i<n;i++)printf("%d ",sticks[i]);
        //printf("\n");
        for(i=sticks[0];i<=sum;i++)
        {
            if(sum%i==0)//剪枝2：大木棍的长度必须是所有木棍总长的因数，并且不少于最长的小木棍。
            {
                OriginLength=i;
                if(i==sum||search(0,i,sum))
                {
                    printf("%d\n",i);
                    break;
                }
            }
        }
    }
    return 0;
}

int quicksort(int data[],int s,int t)
{
    int i,j,y,m,temp;
    m=rand()%(t-s+1)+s;
    temp=data[m];
    data[m]=data[s];
    data[s]=temp;
    y=data[s];
    i=s;
    j=t+1;
    for(;i<j;)
    {
        for(i++;y<data[i];i++);
        for(j--;y>data[j];j--);
        if(i<j)
        {
            temp=data[i];
            data[i]=data[j];
            data[j]=temp;
        }
    }
    data[s]=data[j];
    data[j]=y;
    if(s<j-1)quicksort(data,s,j-1);
    if(j+1<t)quicksort(data,j+1,t);
}

int search(int num,int length,int total)
{
    //printf("%d %d %d\n",num,length,total);
    int i;
    if(length==0)
    {
        total-=OriginLength;
        if(total==0)return 1;
        for(i=0;used[i];i++);//剪枝3：当一根大木棍被填满后，从头开始找到第一个没有用过的小木棍，使用它，也必须使用它。
        used[i]=1;
        if(search(i+1,OriginLength-sticks[i],total))return 1;
        used[i]=0;
        total+=OriginLength;
    }
    else
    {
        for(i=num;i<n;i++)
        {
            if(i>0&&(sticks[i-1]==sticks[i]&&!used[i-1]))continue;//剪枝4：如果当前搜索的小木棍长度和前一根长度相同，但前一根没有使用，说明这一根也不合适。
            if(!used[i]&&length>=sticks[i])//剪枝5：当前要填的小木棍必须不大于大木棍剩余长度。
            {
                length-=sticks[i];
                used[i]=1;
                if(search(i,length,total))return 1;
                used[i]=0;
                length+=sticks[i];
                if(sticks[i]==length)break;//剪枝6：如果当前搜索的木棍恰好能填满剩下的大木棍，而搜索失败，则应该回溯（威力巨大，无法直视）。
            }
        }
    }
    return 0;
}
