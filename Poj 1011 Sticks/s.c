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
        quicksort(sticks,0,n-1);//��֦1��������Сľ�����������򣬼ӿ�������
        //for(i=0;i<n;i++)printf("%d ",sticks[i]);
        //printf("\n");
        for(i=sticks[0];i<=sum;i++)
        {
            if(sum%i==0)//��֦2����ľ���ĳ��ȱ���������ľ���ܳ������������Ҳ��������Сľ����
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
        for(i=0;used[i];i++);//��֦3����һ����ľ���������󣬴�ͷ��ʼ�ҵ���һ��û���ù���Сľ����ʹ������Ҳ����ʹ������
        used[i]=1;
        if(search(i+1,OriginLength-sticks[i],total))return 1;
        used[i]=0;
        total+=OriginLength;
    }
    else
    {
        for(i=num;i<n;i++)
        {
            if(i>0&&(sticks[i-1]==sticks[i]&&!used[i-1]))continue;//��֦4�������ǰ������Сľ�����Ⱥ�ǰһ��������ͬ����ǰһ��û��ʹ�ã�˵����һ��Ҳ�����ʡ�
            if(!used[i]&&length>=sticks[i])//��֦5����ǰҪ���Сľ�����벻���ڴ�ľ��ʣ�೤�ȡ�
            {
                length-=sticks[i];
                used[i]=1;
                if(search(i,length,total))return 1;
                used[i]=0;
                length+=sticks[i];
                if(sticks[i]==length)break;//��֦6�������ǰ������ľ��ǡ��������ʣ�µĴ�ľ����������ʧ�ܣ���Ӧ�û��ݣ������޴��޷�ֱ�ӣ���
            }
        }
    }
    return 0;
}
