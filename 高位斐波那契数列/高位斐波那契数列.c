#include<stdio.h>
#include<string.h>
const int SIZE=2605;
int l=1;
int temp1[40000000],temp2[20000000];
main()
{
     freopen("F.in","rt+",stdin);
     freopen("F.out","wt+",stdout);
     int n,t,i,j;
     int fix(int a[]);
     scanf("%d\n",&n);
     //printf("%d\n",n);
     temp1[0]=1;
     temp2[0]=1;
     printf("1 ");
     printf("1\n");
     printf("2 ");
     printf("1\n");
     for(i=0;i<n-2;i++)
     {
                     //printf("***********************************************\n");
                     //printf("%d ",i+3);
                     //printf("l=%d\n",l);
                     //printf("相加前temp1\n");
                     //for(j=0;j<l;j++)printf("%d ",temp1[j]);
                     //printf("\n");
                     //printf("相加前temp2\n");
                     //for(j=0;j<l;j++)printf("%d ",temp2[j]);
                     //printf("\n");
                     for(j=0;j<l;j++)
                     {
                                     t=temp1[j]+temp2[j];
                                     temp1[j]=temp2[j];
                                     temp2[j]=t;
                     }
                     //printf("-----------------------------------------------\n");
                     //printf("相加后temp2\n");
                     //for(j=0;j<l;j++)printf("%d ",temp2[j]);
                     //printf("\n");
                     //printf("---------------------整理----------------------\n");
                     fix(temp2);
                     //printf("---------------------整理----------------------\n");
                     //printf("整理后temp2\n");
                     //for(j=l-1;j>=0;j--)printf("%d",temp2[j]);
                     //printf("\n");
                     //printf("***********************************************\n");
     }
     for(j=l-1;j>=0;j--)printf("%d",temp2[j]);
                     printf("\n");
     //printf("%d ",i+2);
     //for(j=l-1;j>=0;j--)printf("%d",temp2[j]);
     //printf("\n");
     //printf("Fibonacci数列第%d项长度为%d\n",i+2,l);
     return(0);
}



int fix(int a[])
{
    int m,i,tmp=0,tmp2=0,w=0;
    //printf("l=%d\n",l);
    for(i=0;i<l;i++)
    {
                    //printf("________\n",tmp);
                    //printf("tmp=%d\n",tmp);
                    tmp=(a[i]+tmp2)%10;
                    if(i==l-1&&a[i]+tmp2>=10)l++;
                    //printf("tmp=%d\n",tmp);
                    tmp2=(a[i]+tmp2-tmp)/10;
                    //printf("tmp2=%d\n",tmp2);
                    a[i]=tmp;
                    //printf("________\n",tmp);
                    //printf("w=%d\n",w);
                    //printf("i=%d\n",i);
    }
    if(tmp2!=0)a[i-w]=a[i-w]+tmp2;
}

