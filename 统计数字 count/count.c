#include<stdio.h>
unsigned long date[15000];
int count[15000],maxad=0;
FILE *in,*out;
main()
{
in=fopen("count.in","r");
out=fopen("count.out","w+");
int n,i,j,address,m,w;
unsigned long  temp;
int hash(unsigned long x);
int quicksort(int x,int y);
fscanf(in,"%d",&n);
for(i=0;i<n;i++)
{
          fscanf(in,"%ld",&temp);
           address=hash(temp);
           if(address>maxad)maxad=address;
           date[address]=temp;
           count[address]++;
           fprintf(out,"%d  %d   %d\n",temp,address,count[address]);
}
i=0;
j=maxad;
while(i<j)
{
          for(;count[i]!=0;i++);
          for(;count[j]==0;j--);
          if(i<j)
          {
                                        count[i]=count[j];
                                        count[j]=0;
                                        date[i]=date[j];
                                        date[j]=0;
          }
}
maxad=i;
for(i=0;i<maxad;i++)fprintf(out,"%d ",date[i]);
fprintf(out,"\n");
quicksort(0,maxad-1);
for(i=0;i<maxad;i++)fprintf(out,"%d %d\n",date[i],count[i]);
return 0;
}

int hash(unsigned long x)
{
        int i;
       i=x%10000;
         while(date[i]!=x&&count[i]!=0)i++;
         return i;
}

int quicksort(int x,int y)
{
int i,j,m,temp;
m=rand()%(y-x+1)+x;
fprintf(out,"sort %d %d  %d\n",x,y,m);
i=x;
j=y;
while(i<=j)
{
          for(;date[i]<date[m];i++);
          for(;date[j]>date[m];j--);
          if(date[i]==date[m])i++;
          if(date[j]==date[m])j--;
          if(i<j)
          {
                 temp=date[i];
                 date[i]=date[j];
                 date[j]=temp;
                 temp=count[i];
                 count[i]=count[j];
                 count[j]=temp;
          }
}
fprintf(out,"i=%d j=%d\n",i,j);
if(m<=j)
{
                 temp=date[m];
                 date[m]=date[j];
                 date[j]=temp;
                 temp=count[m];
                 count[m]=count[j];
                 count[j]=temp;
}
else
{
                 temp=date[j+1];
                 date[j+1]=date[m];
                 date[m]=temp;
                 temp=count[j+1];
                 count[j+1]=count[m];
                 count[m]=temp;
                 j++;
}
for(i=0;i<maxad;i++)fprintf(out,"%d ",date[i]);
fprintf(out,"\n%d\n",j);
if(j-1>x)quicksort(x,j-1);
if(j+1<y)quicksort(j+1,y);
}
 
