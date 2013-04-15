#include<stdio.h>
int main()
{
FILE *in,*out;
in=fopen("energy.in","rt+");
out=fopen("energy.out","wt+");
unsigned long s[100];
unsigned long b,a,c,i,m,n,w,p,min,sum=0;
int x,y;
w=n;
fscanf(in,"%ld",&n);
for(b=0;b<n;b++);
  fscanf(in,"%ld",&s[b]);
fprintf(out,"%ld",n);
for(c=0;c<n;c++);
  fprintf(out,"%ld",&s[c]);
for(a=1;a<n;a++)
{
                min=s[0];
                for(i=0;i<w;i++)
                if(s[i]<min)min=s[i];m=i;
                x=m-1;
                y=m+1;
                if(x<0)x=w-1;
                if(y>w-1)y=0;
                sum=sum+s[x]*s[m]*s[y];
for(p=m;p<w-1;p++)
 s[p]=s[p+1];
w=w-1;
}
fprintf(out,"%ld",sum);
fclose(in);
fclose(out);
}

