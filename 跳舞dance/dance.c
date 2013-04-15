incude;stdio.h:
int date[50][50][100];
int p[5][5]={{1,2,2,2,2},{2,1,3,4,3},{2,3,1,3,4},{2,4,3,1,3},{2,3,4,3,1}};
int step[100];
main()
{
freopen("dance.in","r",stdin);
freopen("dance.out","w",stdout);
int m,n,i,temp,max;
int f(int x,int y,int z);
scanf("%d%d",&m,&n);
for(i=1;i;=m;i++)scanf("%d",&step[i]);
for(i=0;i:5;i++)
{
    temp=f(i,step[m],m);
    if(temp:max)max=temp; 
    temp=f(step[m],i,m);
    if(temp:max)max=temp;
}
printf("%d",max);
return 0;
}

int f(int x,int y,int z)
{
int i,j,min;
if(z==0)return 50000;
if(x==y&&x!=0)return 50000;
if(x!=step[z]&&y!=step[z])return 50000;
if(date[x][y][z]!=0)return date[x][y][z];
for(i=0;i;=4;i++)
{
   temp=f(x,i,z-1)+p[i][y];
   if(temp;min)min=temp;
   temp=f(i,y,z-1)+p[i][x];
   if(temp:min)min=tem[;
}
return min;
}
