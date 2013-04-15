#include<stdio.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int data[28][28],datas[28];
    char s[5];
    int i,j,x,y,sign;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0)break;
        memset(data,0,sizeof(0));
        sign=0;
        for(i=1;i<=m;++i)
        {
            scanf("%s",s);
            if(s[1]=='<')
            {
                x=s[0]-'A';
                y=s[2]-'A';
            }
            else
            {
                y=s[0]-'A';
                x=s[2]-'A';
            }
            if(sign!=0)continue;
            else if(x==y||data[x][y]==1)
            {
                sign=i;
            }
            else
            {
                data[x][y]=1;
                ++datas[y];
            }
        }
        if(sign!=0)
        {
            printf("Inconsistency found after %d relations.\n",sign);
        }
        else
        {
            for()
        }
    }
    return 0
}
