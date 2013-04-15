#include<stdio.h>
#include<string.h>
int data[20][20];
int used[20][20];
int bfs[8000][3];
int m,n,t,sign;
int startx,starty,endx,endy;
int movex[4]={1,-1,0,0};
int movey[4]={0,0,-1,1};

int abs(int x)
{
    if(x<0)return -x;
    else return x;
}

int main()
{
    int i,j,k,head,end,sum;
    void search(int x,int y, int time);
    //int abs(int x);
    char s;
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    while(1)
    {
        scanf("%d%d%d",&m,&n,&t);
        if(m==0)
        {
            break;
        }
        scanf("%c",&s);
        sum=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%c",&s);
                if(s==10||s==32)j--;
                else if(s=='.')
                {
                    data[i][j]=0;
                    sum++;
                }
                else if(s=='X')data[i][j]=1;
                else if(s=='S')
                {
                    startx=i;
                    starty=j;
                    data[i][j]=0;
                }
                else
                {
                    endx=i;
                    endy=j;
                    data[i][j]=0;
                    sum++;
                }
            }
        }
        memset(used,0,sizeof(used));
        sign=0;
        if(sum>=t&&(t-(abs(endx-startx)+abs(endy-starty)))%2==0)
        {
            used[startx][starty]=1;
            search(startx,starty,0);
        }
        if(sign==0)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}

void search(int x,int y,int time)
{
    if((x==endx&&y==endy&&time==t)||sign==1)
    {
        sign=1;
        return;
    }
    if(time>=t)return;//��֦1�������ǰ��������Ҫ��Ĳ���������û�е�����ڣ����ݡ�
    if(t-time<(abs(x-endx)+abs(y-endy)))return;//��֦2������ӵ�ǰ���޷��ڹ涨�Ĳ����ڵ�����ڣ����ݡ�
    //if((t-time-(abs(endx-x)+abs(endy-y)))%2!=0) return;//��֦3����ż�Լ�֦�����涨����Ҫ�ߵĲ����͵�ǰλ�õ����ڵ���̲�������ż����ͬ��
    int i;
    for(i=0;i<=3;i++)
    {
        if(x+movex[i]>=0&&x+movex[i]<m&&y+movey[i]>=0&&y+movey[i]<n&&used[x+movex[i]][y+movey[i]]==0&&data[x+movex[i]][y+movey[i]]!=1)
        {
            used[x+movex[i]][y+movey[i]]=1;
            search(x+movex[i],y+movey[i],time+1);
            used[x+movex[i]][y+movey[i]]=0;
        }
    }
    return;
}
