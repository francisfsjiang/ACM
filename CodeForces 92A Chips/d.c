#include<stdio.h>
int main()
{
    int n,m,i;
    int data[55]={0};
    for(i=1;i<=50;i++)data[i]=data[i-1]+i;
    /*for(i=1;i<=50;i++)printf("%4d ",i);
    printf("\n");
    for(i=1;i<=50;i++)printf("%4d ",data[i]);*/
    scanf("%d%d",&n,&m);
    for(;;)
    {
        if(m>=data[n])m-=data[n];
        else
        {
            for(i=n-1;;i--)
            {
                if(m>=data[i])
                {
                    printf("%d",m-data[i]);
                    return 0;
                }
            }
        }
    }
    return 0;
}
