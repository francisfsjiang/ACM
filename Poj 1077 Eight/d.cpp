#include<stdio.h>
#include<string.h>
#include<stdlib.h>
bool used[362890];
int bfs[190000][3];
int movex[4]={-1,1,0,0};//u0 d1 l2 r3
int movey[4]={0,0,-1,1};
int fact[10]={1,1,2,6,24,120,720,5040,40320,362880};
int main()
{
    int i,j,head,end,data[3][3],tempx,tempy,temp;
    char s[200];
    int compute(int data[3][3]);
    int move(int temp,int m);
    int cantor(int temp);
    void check(int temp);
    void pr(int end);
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    for(i=0;i<=2;i++)for(j=0;j<=2;j++)//j+i*3
    {
        scanf("%s",s);
        if(s[0]=='x')data[i][j]=9;
        else data[i][j]=s[0]-48;
    }
    /*for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)printf("%d ",data[i][j]);
        printf("\n");
    }*/
    //printf("%d",compare(data));
    memset(used,0,sizeof(used));
    head=0;
    end=1;
    bfs[head][0]=compute(data);
    //printf("%d\n",bfs[head][0]);
    if(bfs[head][0]==87654321)
    {
        return 0;
    }
    bfs[head][1]=-1;
    bfs[head][2]=-1;
    int sign=0,can;
    while(head<end)
    {
        for(i=0;i<=3;i++)
        {
            temp=move(bfs[head][0],i);
            can=cantor(temp);
            if(temp&&used[can]==0)
            {
                //printf("%d\n",temp);
                used[can]=1;
                bfs[end][0]=temp;
                bfs[end][1]=i;
                bfs[end][2]=head;
                end++;
            }
            if(temp==12345678)
            {
                //printf("---------------------------------%d\n",temp);
                sign=1;
                break;
            }
        }
        if(sign==1)break;
        head++;
    }
    //printf("%d",sign);
    if(sign==0)printf("unsolvable");
    else pr(end-1);
    return 0;
}


int compute(int data[3][3])
{
    int temp=0,i,j,k=1;
    for(i=2;i>=0;i--)for(j=2;j>=0;j--)
    {
        if(i==2&&j==2)continue;
        temp+=data[i][j]*k;
        k*=10;
    }
    return temp;
}

int move(int temp,int m)
{
    int data[3][3],num[10]={0},x0,y0,tempp,i,j;
    x0=-1;
    for(i=2;i>=0;i--)for(j=2;j>=0;j--)
    {
        if(i==2&&j==2)continue;
        data[i][j]=temp%10;
        num[data[i][j]]=1;
        if(data[i][j]==9)
        {
            x0=i;
            y0=j;
        }
        temp=(temp-temp%10)/10;
    }
    if(x0==-1)
    {
        x0=2;
        y0=2;
    }
    for(i=1;i<=9;i++)if(num[i]==0)
    {
        data[2][2]=i;
        break;
    }
    if(x0+movex[m]>=0&&x0+movex[m]<3&&y0+movey[m]>=0&&y0+movey[m]<3)
    {
        tempp=data[x0][y0];
        data[x0][y0]=data[x0+movex[m]][y0+movey[m]];
        data[x0+movex[m]][y0+movey[m]]=tempp;
        return compute(data);
    }
    else return 0;
}

void check(int temp)
{
    int data[3][3],num[10]={0},x0,y0,tempp,i,j;
    for(i=2;i>=0;i--)for(j=2;j>=0;j--)
    {
        if(i==2&&j==2)continue;
        data[i][j]=temp%10;
        num[data[i][j]]=1;
        if(data[i][j]==9)
        {
            x0=i;
            y0=j;
        }
        temp=(temp-temp%10)/10;
    }
    for(i=1;i<=9;i++)if(num[i]==0)
    {
        data[2][2]=i;
        break;
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)printf("%d ",data[i][j]);
        printf("\n");
    }
}

void pr(int end)
{
    if(bfs[end][2]==-1)return;
    pr(bfs[end][2]);
    if(bfs[end][1]==0)printf("u");
    else if(bfs[end][1]==1)printf("d");
    else if(bfs[end][1]==2)printf("l");
    else printf("r");
    //check(bfs[end][0]);
}

int cantor(int temp)
{
    int num[11],sign[11]={0},tempp,i,j;
    for(i=8;i>=1;i--)
    {
        num[i]=temp%10;
        sign[num[i]]=1;
        temp=(temp-temp%10)/10;
    }
    for(i=1;i<=9;i++)if(sign[i]==0)
    {
        num[9]=i;
        break;
    }
    int sum=0;
    for(i=1;i<=9;i++)
    {
        tempp=0;
        for(j=i+1;j<=9;j++)if(num[i]>num[j])tempp++;
        sum+=tempp*fact[9-i];
    }
    return sum;
}
