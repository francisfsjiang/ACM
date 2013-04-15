#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define MAX_INDEX 100    /*这里可以修改最大阶*/

void swap(int *a,int *b)
{
int t;
t=*a;
*a=*b;
*b=t;
}

/*快速排序算法*/
void QuickSort(int a[], int l, int r)

{
int i=l; /*从左至右的游标*/
int j=r + 1; /*从右到左的游标*/
int pivot=a[l];
if (l >= r) return;
/*把左侧>= pivot的元素与右侧<= pivot 的元素进行交换*/
while (1)
{
do
{/*在左侧寻找>= pivot 的元素*/
i = i + 1;
} while (a[i] < pivot);
do
{/*在右侧寻找<= pivot 的元素*/
j = j - 1;
} while (a[j] > pivot);
if (i >= j) break; /*未发现交换对象*/
swap(&a[i],&a[j]);
}

/*设置p i v o t*/
a[l] = a[j];
a[j] = pivot;
QuickSort(a, l, j-1); /*对左段排序*/
QuickSort(a, j+1, r); /*对右段排序*/
}

void Huanf(int Array[][MAX_INDEX],int n)
{
int i,j;
int a,b,m;
int tempArray1[MAX_INDEX];
int tempArray2[MAX_INDEX];
a=n/2;
b=a+1;
m=n%4;
switch(m)
{
case 0:
case 2:
/*穿心对调*/
for(i=0;i<n;i++)
for(j=0;j<n/2;j++)
{
if(i<n/2)
{
if(i%2==1&&Array[i][j]%2==0)/*偶行换偶*/
{
swap(&Array[i][j],&Array[n-1-i][n-1-j]);
}
else if(i%2==0&&Array[i][j]%2==1)/*奇行换奇*/
{
swap(&Array[i][j],&Array[n-1-i][n-1-j]);
}
}
else
{
if(i%2==1&&Array[i][j]%2==1)/*偶行换奇*/
{
swap(&Array[i][j],&Array[n-1-i][n-1-j]);
}
else if(i%2==0&&Array[i][j]%2==0)/*奇行换偶*/
{
swap(&Array[i][j],&Array[n-1-i][n-1-j]);
} 
}

}
/*End穿心对调*/
if(m==2)
{
for(i=0;i<n/2;i++)
{
if((i!=0)&&(i!=a-1)&&(i!=b-1)&&(i!=n-1))
{
swap(&Array[i][a-1],&Array[n-1-i][a-1]);
swap(&Array[b-1][i],&Array[b-1][n-1-i]);
}
}
swap(&Array[0][a-1],&Array[0][b-1]);
swap(&Array[a-1][0],&Array[b-1][0]);
swap(&Array[2][0],&Array[2][n-1]);
swap(&Array[0][2],&Array[n-1][2]); 
}
break;
case 1:
case 3:
/*穿心对调*/
for(i=0;i<n;i++)
for(j=0;j<n/2;j++)
{
if(i<n/2)
{
if(i%2==1&&Array[i][j]%2==0) /*偶行换偶*/
{
swap(&Array[i][j],&Array[n-1-i][n-1-j]);
}
else if(i%2==0&&Array[i][j]%2==0)/*奇行换奇*/
{
swap(&Array[i][j],&Array[n-1-i][n-1-j]);
}
}
else if(i>n/2)
{
if(i%2==1&&Array[i][j]%2==0)/*偶行换偶*/
{
swap(&Array[i][j],&Array[n-1-i][n-1-j]);
}
else if(i%2==0&&Array[i][j]%2==0)/*奇行换奇*/
{
swap(&Array[i][j],&Array[n-1-i][n-1-j]);
}
}
}
/*End穿心对调*/
/*重排米字*/
for(i=0;i<n;i++)
{
tempArray1[i]=Array[i][i];
tempArray2[i]=Array[a][i];
}

QuickSort(tempArray1,0,n-1);
QuickSort(tempArray2,0,n-1);
for(i=0;i<n;i++)
{
Array[i][i]=tempArray2[i];
Array[a][i]=tempArray1[i];
}
for(i=0;i<n;i++)
{
tempArray1[i]=Array[i][n-1-i];
tempArray2[i]=Array[i][a];
}
QuickSort(tempArray1,0,n-1);
QuickSort(tempArray2,0,n-1);
for(i=0;i<n;i++)
{
Array[i][n-1-i]=tempArray2[i];
Array[i][a]=tempArray1[i];
}
/*End重排米字*/

if(m==3)
{
for(i=0;i<n/2;i++)
{
if((i!=a-1)&&(i!=b-1)&&(i!=a+1))
{
swap(&Array[i][a-1],&Array[n-1-i][a-1]);
swap(&Array[a-1][i],&Array[a-1][n-1-i]);
}
}
swap(&Array[a-1][a-1],&Array[a+1][a+1]);
swap(&Array[a-1][b-1],&Array[a+1][b-1]); 
}
break;
default:
break;
}
return;
}


void main()
{
freopen("square.in","rt+",stdin);
freopen("square.out","wt+",stdout);
int Ne[MAX_INDEX][MAX_INDEX];
int Ne2[MAX_INDEX][MAX_INDEX];
int i,j,n;
//printf("Please Input N (0 quit): \n");
scanf("%d",&n);
/*数组赋初值*/
for(i=0;i<n;i++)
for(j=0;j<n;j++)
Ne[i][j]=i*n+(j+1);

Huanf(Ne,n);

for(i=0;i<n;i++)
//for(j=0;j<n;j++)
//{
//                printf("%-4d",Ne[i][j]);
//                if(j==n-1)
//                printf("\n");
//}
//printf("\n");

for(i=0;i<n;i++)
{
                for(j=n-1;j>=0;j--)
                {
                                printf("%d ",Ne[j][i]);
                }
                printf("\n");
}
printf("\n");


} 
