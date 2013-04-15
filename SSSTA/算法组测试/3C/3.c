#include<stdio.h>
int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int t,a,b,c,x,y,z,i,j,k,temp,sum;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
                    scanf("%d%d%d%d%d%d",&a,&b,&c,&x,&y,&z);
                    if(a<b)
                    {
                           temp=a;
                           a=b;
                           b=temp;
                    }
                    if(b<c)
                    {
                           temp=c;
                           c=b;
                           b=temp;
                    }
                    if(a<b)
                    {
                           temp=a;
                           a=b;
                           b=temp;
                    }
                    
                    
                    if(x<y)
                    {
                           temp=x;
                           x=y;
                           y=temp;
                    }
                    if(y<z)
                    {
                           temp=y;
                           y=z;
                           z=temp;
                    }
                    if(x<y)
                    {
                           temp=x;
                           x=y;
                           y=temp;
                    }
                    //printf("%d %d %d\n%d %d %d\n",a,b,c,x,y,z);
                    sum=0;
                    if(a>x)sum+=x;
                    else sum+=a;
                    if(b>y)sum+=y;
                    else sum+=b;
                    if(c>z)sum+=z;
                    else sum+=c;
                    printf("%d\n",sum);
    }
    return 0;
}

