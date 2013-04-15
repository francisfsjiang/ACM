#include<stdio.h>
#include<string.h>
const int SIZE=10001;
char c1[SIZE],c2[SIZE];
int A[SIZE],B[SIZE];
int temp[SIZE*2];
main()
{    
     freopen("AB.in","r",stdin);    
     freopen("AB.out","w+",stdout);
     int i,j,k,l,l1,l2,tmp=0,tmp2=0;
     memset(temp,0,sizeof(temp));
     scanf("%s",c1);
     scanf("%s",c2);
     l1=strlen(c1);
     l2=strlen(c2);
     l=l1+l2;
     for(i=1;i<=l1;i++)A[i]=c1[l1-i]-48;
     for(i=1;i<=l2;i++)B[i]=c2[l2-i]-48;
     for(i=1;i<=l;i++)
     {
                      for(j=1;j<=l;j++)
                      {
                                       temp[j+i-1]+=A[j]*B[i];
                      }
     }
     for(i=1;i<=l;i++)
     {
                      tmp=(temp[i]+tmp2)%10;
                      tmp2=(temp[i]+tmp2-tmp)/10;
                      temp[i]=tmp;                        
     }        
     if(temp[1]==0)for(i=1;i<=l;i++)temp[i]=temp[i+1];k=l-1;
     for(i=k;i>=1;i--)printf("%d",temp[i]);
     printf("\n");
                      
}
     
