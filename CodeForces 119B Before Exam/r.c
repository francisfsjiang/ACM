#include<stdio.h>
#include<stdlib.h>
int data[105],num[105];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int qs(int s,int t);
    int sign[105]={0};
    int orign[105];
    int n,k,nk,p,i,j,x,temp,cards,t;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&data[i]);
        orign[i+1]=data[i];
        num[i]=i+1;
    }
    qs(0,n-1);
    /*for(i=0;i<n;i++)printf("%d ",data[i]);
    printf("\n");
    for(i=0;i<n;i++)printf("%d ",num[i]);
    printf("\n");*/
    nk=n/k;
    //printf("nk=%d\n",nk);
    scanf("%d",&p);
    double div,max=-500000,min=500000;
    cards=0;
    for(i=1;i<=p;i++)
    {
        temp=0;
        t=cards+1;
        for(j=1;j<=nk;j++)
        {
            scanf("%d",&x);
            temp+=orign[x];
            if(sign[x]==0)
            {
                sign[x]=1;
                cards=t;
            }
        }
        div=(double)temp/nk;
        //printf("div=%lf %d\n",div,temp);
        if(div>max)max=div;
        if(div<min)min=div;
    }
    //min
    temp=0;
    int howmany=0;
    for(i=0;i<n&&howmany<nk;i++)
    {
        if(sign[num[i]]==0)
        {
            temp+=data[i];
            howmany++;
        }
    }
    div=(double)temp/nk;
    //printf("div=%lf\n",div);
    if(div<min&&howmany==nk&&cards<k)min=div;
    //max
    temp=0;
    howmany=0;
    for(i=n-1;i>=0&&howmany<nk;i--)
    {
        if(sign[num[i]]==0)
        {
            temp+=data[i];
            howmany++;
        }
    }
    div=(double)temp/nk;
    //printf("div=%lf\n",div);
    if(div>max&&howmany==nk&&cards<k)max=div;
    printf("%lf %lf",min,max);
    return 0;
}

int qs(int s,int t)
{
    int m,y,i,j,temp;
    m=rand()%(t-s+1)+s;
    temp=data[m];
    data[m]=data[s];
    data[s]=temp;
    temp=num[m];
    num[m]=num[s];
    num[s]=temp;
    y=data[s];
    i=s;
    j=t+1;
    for(;i<j;)
    {
        for(i++;data[i]<y;i++);
        for(j--;data[j]>y;j--);
        if(i<j)
        {
            temp=data[i];
            data[i]=data[j];
            data[j]=temp;
            temp=num[i];
            num[i]=num[j];
            num[j]=temp;
        }
    }
    data[s]=data[j];
    data[j]=y;
    temp=num[s];
    num[s]=num[j];
    num[j]=temp;
    if(s<j-1)qs(s,j-1);
    if(t>j+1)qs(j+1,t);
}
