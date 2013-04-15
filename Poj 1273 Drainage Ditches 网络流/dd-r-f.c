#include<stdio.h>
#include<string.h>
#define min(x,y) x>y?y:x
#define max(x,y) x>y?x:y
#define MAX 201

struct next
{
    int data,pre,next;//����������ǰָ�룬��ָ��
}next[MAX][MAX];

int e[MAX];//������
int height[MAX];//�߶�
int listb[MAX];//��������ǰָ��
int listn[MAX];//���������ָ��
int n;

void insert(int x,int y,int d)//�����
{
    next[x][y].data=d;
    next[x][next[x][0].pre].next=y;
    next[x][y].pre=next[x][0].pre;
    next[x][y].next=0;
    next[x][0].pre=y;
}

void deleted(int x,int y)//ɾ����
{
    next[x][next[x][y].pre].next=next[x][y].next;
    next[x][next[x][y].next].pre=next[x][y].pre;
    next[x][y].data=0;
}

void push(int x,int y)//ѹ��
{
    int p=min(e[x],next[x][y].data);
    next[x][y].data-=p;
    if(next[x][y].data==0)deleted(x,y);
    if(next[y][x].data==0)insert(y,x,p);
    else next[y][x].data+=p;
    e[x]-=p;
    e[y]+=p;
}

void relabel(int x)//�ر��
{
    int i,minn=9999999;
    for(i=next[x][0].next;i!=0;i=next[x][i].next)
    {
        if(next[x][i].data>0&&height[i]<minn)
        {
            minn=height[i];
        }
    }
    height[x]=minn+1;
}

void discharge(int x)//�ų�
{
    int i=next[x][0].next;
    while(e[x]>0)
    {
        if(i==0)
        {
            relabel(x);
        }
        else if(next[x][i].data>0&&height[x]>height[i])push(x,i);
        i=next[x][i].next;
    }
}

void rtf()//RTF����
{
    int i,j,k,old;
    for(i=listn[1];i!=n;i=listn[i])
    {
        old=height[i];
        discharge(i);
        if(height[i]>old&&listb[i]!=1)
        {
            j=i;
            listn[listb[j]]=listn[j];
            listb[listn[j]]=listb[j];
            listn[j]=listn[1];
            listb[listn[1]]=j;
            listn[1]=j;
            listb[j]=1;
        }
    }
}

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,k,m,x,y,z;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(next,0,sizeof(next));
        memset(height,0,sizeof(height));
        memset(e,0,sizeof(e));
        e[1]=2147483640;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(z==0)continue;
            if(next[x][y].data!=0)
            {
                next[x][y].data+=z;
                continue;
            }
            if(next[x][0].pre==0)
            {
                next[x][0].pre=y;
                next[x][0].next=y;
                next[x][y].data=z;
                next[x][y].pre=0;
                next[x][y].next=0;
            }
            else insert(x,y,z);
        }
        for(i=1;i<=n;i++)
        {
            listb[i]=i-1;
            listn[i]=i+1;
        }
        height[1]=n;
        for(i=next[1][0].next;i!=0;i=next[1][i].next)push(1,i);
        rtf();
        printf("%d\n",e[n]);
    }
    return 0;
}
