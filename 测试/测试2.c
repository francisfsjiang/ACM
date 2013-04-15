#include<stdio.h>
int s[9000000];
main()
{
      int i,n;
      int quicksort(int date[],int s,int t);
      freopen("Quicksort.in","rt+",stdin);
      freopen("Quicksort.out","wt+",stdout);
      scanf("%d",&n);
      for(i=0;i<n;i++)scanf("%d",&s[i]);
      quicksort(s,0,n-1);
      for(i=0;i<n;i++)printf("%d ",s[i]);
}
      
int quicksort(int date[],int s,int t)
{
     int i,j,y,temp,m;
     m=rand()%(t-s+1)+s;
     i=s-1;
     j=t+1;
     y=date[m];
     for(;i<j;)
     {
               for(i++;date[i]<y;i++);
               for(j--;date[j]>y;j--);
               if(m==i){j++;continue;}
               if(m==j){i--;continue;}
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
     else if(j<m)
     {
          date[m]=date[j+1];
                   date[j+1]=y;
              }
              if(s<j-1)quicksort(date,s,j-1);
              if(t>j+1)quicksort(date,j+1,t);
}
