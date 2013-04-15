#include<stdio.h>
main()
{
      int i,j,n,m1,m2,lw,singlsum,singlsums=0,sum=0;
      char yng,ynx,name[20],names[20];
      freopen("123.in","rt+",stdin);
      freopen("123.out","wt+",stdout);
      scanf("%d",&n);
      for(i=1;i<=n;i++)
      {
                        singlsum=0;
                        scanf("%s %d %d %c %c %d",name,&m1,&m2,&yng,&ynx,&lw);
                        if(m1>80&&lw>=1)singlsum+=8000;
                        if(m1>85&&m2>80)singlsum+=4000;
                        if(m1>90)singlsum+=2000;
                        if(m1>85&&ynx=='Y')singlsum+=1000;
                        if(m2>80&&yng=='Y')singlsum+=850;
                        sum+=singlsum;
                        if(singlsum>singlsums)
                        {
                                              singlsums=singlsum;
                                              for(j=0;j<=19;j++)
                                              {
                                                               if(name[j]>60)names[j]=name[j];
                                                               else names[j]=0;
                                                               name[j]=0;
                                              }
                        }
      }
      printf("%s\n%d\n%d\n",names,singlsums,sum);
      }
