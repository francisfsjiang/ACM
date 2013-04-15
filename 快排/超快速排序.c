#include<stdio.h>
int s[9000000],n;
main()
{
      int i;
      int quicksort(int date[],int s,int t);
      freopen("Quicksort.in","rt+",stdin);
      freopen("Quicksort.out","wt+",stdout);
      scanf("%d",&n);
      for(i=0;i<n;i++)scanf("%d",&s[i]);
      bq_sort(s,0,n-1,2048);
      for(i=0;i<n;i++)printf("%d ",s[i]);
}


bq_sort(int a[],int low,int high,int k) 
{ 
            int i,j; 
            int x;
            i=low; 
            j=high; 
            while(i<j) 
            { 
                       while(a[j]&k&&i<j )j--; 
                       while((a[i]&k)==0&&i<j)i++; 
                       if(i<j) 
                       {
                               x=a[j];  
                               a[j]=a[i];    
                               a[i]=x;    
                       } 
                       else 
                       { 
                            if(a[j]&k)i--; 
                            else j++;
                            break; 
                       } 
            }         
            if(k>1) 
            { 
                    if(low<i)bq_sort(a,low,i,k/2);  
                    if(j<high)bq_sort(a,j,high,k/2);    
            }      
}
