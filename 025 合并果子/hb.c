#include<stdio.h>
main()
{
     freopen("hb.in","r",stdin);    
     freopen("hb.out","w",stdout);
     int i,j,n,temp;
     unsigned long sum=0;
     int data[10001]={999999999},head1=0;
     int tep[10001]={999999999},head2=0,end=0;
     int quicksort(int date[],int s,int t);
     scanf("%d",&n);
     for(i=0;i<n;i++)printf("%d ",tep[i]);
     printf("\n");
     for(i=0;i<n;i++)printf("%d ",data[i]);
     printf("\n");
     for(i=0;i<n;i++)scanf("%d",&data[i]);
     quicksort(data,0,n-1);
     for(i=0;i<n;i++)printf("%d ",data[i]);
     printf("\n");
     for(i=0;i<n;i++)
     {
                     if(data[head1]<tep[head2])
                     {
                         if(data[head1+1]<tep[head2])
                         {
                              tep[end]=data[head1]+data[head1+1];
                              head1=head1+2;
                              sum+=tep[end];
                              end++;
                         }
                         else
                         {
                             tep[end]=data[head1]+tep[head2];
                             head1=head1+1;
                             head2=head2+1;
                             sum+=tep[end];
                             end++;
                         }
                     }
                     else
                     {
                         if(data[head1]<tep[head2+1])
                         {
                             tep[end]=data[head1]+tep[head2];
                             head1=head1+1;
                             head2=head2+1;
                             sum+=tep[end];
                             end++;
                         }
                         else
                         {
                             tep[end]=data[head1]+data[head1+1];
                             head2=head2+2;
                             sum+=tep[end];
                             end++;
                         }
                             
                     }
     }
     printf("%d",sum);
     return(0);
}


int quicksort(int date[],int s,int t)
{
     int i,j,y,temp,m,k;
     m=rand()%(t+1-s)+s;
     i=s-1;
     j=t+1;
     y=date[m];
     for(;i<j;)
     {
                 for(i++;i<=t&&date[i]<y;i++);
                 for(j--;j>=0&&date[j]>y;j--);
                 if(i==m){j++;continue;}
                 if(j==m){i--;continue;}
                 if(i<j)
                 {
                        temp=date[i];
                        date[i]=date[j];
                        date[j]=temp;
                 }
     }
     if(m<j)
     {
            date[m]=date[j];
            date[j]=y;
     }
     else if(m>j)
     {
          date[m]=date[j+1];
          date[j+1]=y;
     }
     if(s<j-1)quicksort(date,s,j-1);
     if(j+1<t)quicksort(date,j+1,t);
}
