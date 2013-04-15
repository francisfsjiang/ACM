#include<stdio.h>
int main()
{
    int n,i,k=1,temp;
    scanf("%d",&n);
    for(;;)
    {
        temp=k*5;
        if(n>temp)
        {
            n-=temp;
            k=k<<1;
        }
        else
        {
            for(i=1;;)
            {
                if(n<=k)break;
                else
                {
                    n-=k;
                    i++;
                }
            }
            break;
        }
    }
    if(i==1)printf("Sheldon");
    else if(i==2)printf("Leonard");
    else if(i==3)printf("Penny");
    else if(i==4)printf("Rajesh");
    else printf("Howard");
    return 0;
}

