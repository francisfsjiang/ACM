#include<stdio.h>
#include<string.h>
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int max(int x,int y);
    int i,j,head,end,l1,l2;
    int data[1000][2];
    char s1[1000],s2[1000];
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        memset(data,0,sizeof(data));
        l1=strlen(s1);
        l2=strlen(s2);
        head=0;
        end=1;
        for(i=1;i<=l1;i++)
        {
            for(j=1;j<=l2;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    data[j][end]=data[j-1][head]+1;
                }
                else
                {
                    data[j][end]=max(data[j][head],data[j-1][end]);
                }
            }
            if(head==0)
            {
                end=0;
                head=1;
            }
            else
            {
                end=1;
                head=0;
            }
        }
        printf("%d\n",data[l2][head]);
    }
    return 0;
}

int max(int x,int y)
{
    if(x>y)return x;
    else return y;
}


