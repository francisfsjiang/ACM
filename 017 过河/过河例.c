#include<stdio.h>
int s,t,m,x,p=0;
int f[100000]={0};
int r[120]={0};
int map[100000]={0};
main()
{
      int l,k;
      int i,j,min;
      freopen("river.in","rt+",stdin);    
      freopen("river.out","wt+",stdout);
      scanf("%ld%d%d%d",&l,&s,&t,&m);
      printf("%ld\n%d %d %d\n",l,s,t,m);
      for(i=1;i<=m;i++)scanf("%ld",&r[i]);
      for(i=1;i<=m;i++)printf("%ld",r[i]);
      printf("\n");
      for(i=1;i<=m-1;i++)
      {
                         for(j=i+1;j<=m;j++)
                         {
                                            if(r[i]>r[j])
                                            {
                                                         x=r[i];
                                                         r[i]=r[j];
                                                         r[j]=x;
                                            }
                         }
      }
      printf("×´Ì¬Ñ¹Ëõ\n");
      for(i=1;i<=m;i++)
      {
                       l=r[i]-r[i-1];
                       printf("l(%d)=r[%d](%d)-r[%d](%d)\n",l,i,r[i],i-1,r[i-1]);
                       if(l%t==0)k=t;
                       else k=1%t;
                       k+=t;
                       printf("k=%d\n",k);
                       if(l<k)k=l;
                       p+=k;
                       printf("p=%d\n",p);
                       map[p]=1;
      }
      printf("map\n");
      for(i=1;i<=m;i++)printf("%ld ",r[i]);
      printf("\n");
      for(i=1;i<=p+t;i++)
      {
                         min=101;
                         for(j=i-t;j<=i-s;j++)
                         {
                                              if(j<0)continue;
                                              if(f[j]<min)min=f[j];
                         }
                         f[i]=min+map[i];
      }
      printf("f\n");
      for(i=1;i<=p+t;i++)printf("%ld ",f[i]);
      printf("\n");
      min=101;
      for(i=p+1;i<=p+t;i++)if(f[i]<min) min=f[i];
      printf("%d\n",min);
} 
