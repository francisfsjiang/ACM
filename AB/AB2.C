#include<stdio.h>
#include<string>
const int SIZE=5001;
main()
{    
     FILE *in,*out;
     in=fopen("AB.in","r");    
     out=fopen("AB.out","w+");    
     char c1[SIZE],c2[SIZE];
     int A[SIZE],B[SIZE];
     int temp[SIZE*2],temp2[SIZE];
     int i,j,k,l,l1,l2,tmp=0,tmp2=0;
     memset(temp,0,sizeof(temp));
     memset(temp2,0,sizeof(temp2));
     fscanf(in,"%s",c1);
     fscanf(in,"%s",c2);
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
     for(i=k;i>=1;i--)fprintf(out,"%d",temp[i]);
     fprintf(out,"\n");
     fclose(in);    
     fclose(out);               
}
     
