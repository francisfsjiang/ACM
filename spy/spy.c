#include<stdio.h>
#include<string.h>
const int SIZE=101;
int main()
{    
     freopen("spy.in","rt+",stdin);    
     freopen("spy.out","wt+",stdout);
     int i,j,n,m,d=1;
     char a[SIZE],b[SIZE],c[SIZE],r[SIZE];
     int z[26]={0};
     scanf("%s",a);
     scanf("%s",b);
     scanf("%s",c);
     n=strlen(a);
     m=strlen(c);
     printf("%s\n",a);
     printf("%s\n",b);
     printf("%s\n",c);
     for(i=0;i<n;i++)
     {
                     z[b[i]-65]++;
     }
     for(i=0;i<26;i++)printf("%c",(i+65));
     printf("\n");
     for(i=0;i<26;i++)printf("%d",z[i]);
     printf("\n");
     for(i=0;i<26;i++)
     {
                     if(z[i]==0)d=0;
     }
     printf("d=%d\n",d);
     if(d==0)printf("Failed");
     else 
     {
          for(i=0;i<n;i++)
          {
                          for(j=i;j<n;j++)
                          {
                                          if(b[i]==b[j]&&a[i]!=a[j])d=0;
                          }
          }
          if(d==0)printf("Failed"); 
     }
     if(d==1)
     {
             for(i=0;i<n;i++)
             {
                             for(j=0;j<n;j++)
                             {
                                             if(c[i]==a[j])r[i]=b[j];
                                             if(c[i]==a[j])break;
                             }
             }
             for(i=0;i<m;i++)printf("%c",r[i]);     
     }

     return(0);
}
             
                                          
     
