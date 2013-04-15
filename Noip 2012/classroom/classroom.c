#include<stdio.h>
int data[100005];
int left[1000005];
int mid[1000005];
int right[1000005];
int min[1000005];
int n;
int main()
{
    freopen("classroom.in","r",stdin);
    freopen("classroom.out","w",stdout);
    int build(int a,int x,int y);
    int ask(int a,int x,int y,int d);
    int rchild(int x);
    int lchild(int x);
    int father(int x);
    int f5(int a,int x,int y,int d);
    int i,m,x,y,d,sign=0,w;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&data[i]);
    for(i=1;i<=n;i++)printf("%d ",data[i]);
    printf("\n");
    build(1,1,n);
    for(i=1;i<=20;i++)printf("%d ",min[i]);
    printf("\n");
    for(i=1;i<=20;i++)printf("%d ",left[i]);
    printf("\n");
    for(i=1;i<=20;i++)printf("%d ",right[i]);
    printf("\n");
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&d,&x,&y);
        w=ask(1,x,y,d);
        printf("w=%d\n",w);
        if(w==1)f5(1,x,y,d);
        else
        {
            printf("-1\n%d",i);
            break;
        }
    }
    if(i==m+1)printf("0\n");
    return 0;
}

int rchild(int x)
{
    return x*2+1;
}

int lchild(int x)
{
    return x*2;
}

int father(int x)
{
    if(x%2==0)return x/2;
    else return (x-1)/2;
}

int build(int a,int x,int y)
{
    if(x==y)
    {
        left[a]=x;
        right[a]=x;
        mid[a]=x;
        min[a]=data[x];
        return 0;
    }
    if(y-x%2==0)
    {
        left[a]=x;
        right[a]=y;
        mid[a]=(y-x)/2+x;
    }
    else
    {
        left[a]=x;
        right[a]=y;
        mid[a]=(y-x-1)/2+x;
    }
    build(lchild(a),left[a],mid[a]);
    build(rchild(a),mid[a]+1,right[a]);
    if(min[lchild(a)]<min[lchild(a)])min[a]=min[lchild(a)];
    else min[a]=min[rchild(a)];
    return 0;
}

int ask(int a,int x,int y,int d)
{
    if(x==left[a]&&y==right[a])
    {
        if(d<=min[a])return 1;
        else return 0;
    }
    if(y<=mid[a])
    {
        return ask(lchild(a),x,y,d);
    }
    else
    {
        if(x>mid[a])
        {
            return ask(rchild(a),x,y,d);
        }
        else
        {
            if(ask(lchild(a),x,mid[a],d)==1&&ask(rchild(a),mid[a]+1,y,d)==1)return 1;
            else return 0;
        }
    }
}

int f5(int a,int x,int y,int d)
{
    printf("%d %d %d %d\n",a,x,y,d);
    if(x==y)
    {
        min[a]=min[a]-d;
        return 0;
    }
    min[a]=min[a]-d;
    if(y<=mid[a])
    {
        f5(lchild(a),x,y,d);
    }
    else
    {
        if(x>mid[a])
        {
            f5(rchild(a),x,y,d);
        }
        else
        {
            f5(lchild(a),x,mid[a],d);
            f5(rchild(a),mid[a],y,d);
        }
    }
}

