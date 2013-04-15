#include<stdio.h>
int m1=0,m2=0,m3=0,m4=0;
int main()
{    
     freopen("chess.in","rt+",stdin);
     freopen("chess.out","wt+",stdout);
     int s1,s2;//ø’»±∆Â≈Ãµƒ◊¯±ÍS1∫·S2◊› 
     int n; //∆Â≈Ã±ﬂ≥§2^n/
     int c;
     int cover(int n,int x,int y);
     scanf("%d %d %d",&n,&s1,&s2);
     printf ("n=%d\ns1=%d\ns2=%d\n",n,s1,s2);
     c=(int)pow(2,n);
     printf ("m1=%d\nm2=%d\nm3=%d\nm4=%d",m1,m2,m3,m4);
     printf ("c=%f\n",c);
     cover(c,s1,s2);
     printf ("m1=%d\nm2=%d\nm3=%d\nm4=%d",m1,m2,m3,m4);
     return(0);
}

int cover(int n,int x,int y)
{
    int a,b,p,i;
    //for(i=0;i<=2*n;i++)printf("***");
    //printf("\n");
    //printf("n=%d\n",n);
    //printf("x=%d\n",x);
    //printf("y=%d\n",y);
    p=n/2;
    if(x<=(n/2))a=0;
    else a=1;
    if(y<=(n/2))b=0;
    else b=1;
    if(a==0&&b==0)m1++;
    else if(a==0&&b==1)m2++;
    else if(a==1&&b==0)m3++;
    else m4++;
    //printf ("m1=%d\nm2=%d\nm3=%d\nm4=%d\n",m1,m2,m3,m4);
    
    if(n>2)
    {
           if(a==0&&b==0)
           {
                         cover(p,x,y);
                         cover(p,p,1);
                         cover(p,1,p);
                         cover(p,1,1);
           }
           else if(a==0&&b==1)
           {
                              cover(p,x,y);
                              cover(p,p,p);
                              cover(p,1,p);
                              cover(p,1,1);
           }
           else if(a==1&&b==0)
           {
                              cover(p,x,y);
                              cover(p,p,p);
                              cover(p,p,1);
                              cover(p,1,1);
           }
           else
           {
                cover(p,x,y);
                cover(p,p,p);
                cover(p,p,1);
                cover(p,1,p);
           }
    }
    //for(i=0;i<=2*n;i++)printf("***");
    //printf("\n");
}
    

