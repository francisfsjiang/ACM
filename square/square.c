#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define MAX_INDEX 100    /*��������޸�����*/

void swap(int *a,int *b)
{
int t;
t=*a;
*a=*b;
*b=t;
}

/*���������㷨*/
void QuickSort(int a[], int l, int r)

{
int i=l; /*�������ҵ��α�*/
int j=r + 1; /*���ҵ�����α�*/
int pivot=a[l];
if (l >= r) return;
/*�����>= pivot��Ԫ�����Ҳ�<= pivot ��Ԫ�ؽ��н���*/
while (1)
{
do
{/*�����Ѱ��>= pivot ��Ԫ��*/
i = i + 1;
} while (a[i] < pivot);
do
{/*���Ҳ�Ѱ��<= pivot ��Ԫ��*/
j = j - 1;
} while (a[j] > pivot);
if (i >= j) break; /*δ���ֽ�������*/
swap(&a[i],&a[j]);
}

/*����p i v o t*/
a[l] = a[j];
a[j] = pivot;
QuickSort(a, l, j-1); /*���������*/
QuickSort(a, j+1, r); /*���Ҷ�����*/
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
/*���ĶԵ�*/
for(i=0;i<n;i++)
for(j=0;j<n/2;j++)
{
if(i<n/2)
{
if(i%2==1&&Array[i][j]%2==0)/*ż�л�ż*/
{
swap(&Array[i][j],&Array[n-1-i][n-1-j]);
}
else if(i%2==0&&Array[i][j]%2==1)/*���л���*/
{
swap(&Array[i][j],&Array[n-1-i][n-1-j]);
}
}
else
{
if(i%2==1&&Array[i][j]%2==1)/*ż�л���*/
{
swap(&Array[i][j],&Array[n-1-i][n-1-j]);
}
else if(i%2==0&&Array[i][j]%2==0)/*���л�ż*/
{
swap(&Array[i][j],&Array[n-1-i][n-1-j]);
} 
}

}
/*End���ĶԵ�*/
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
/*���ĶԵ�*/
for(i=0;i<n;i++)
for(j=0;j<n/2;j++)
{
if(i<n/2)
{
if(i%2==1&&Array[i][j]%2==0) /*ż�л�ż*/
{
swap(&Array[i][j],&Array[n-1-i][n-1-j]);
}
else if(i%2==0&&Array[i][j]%2==0)/*���л���*/
{
swap(&Array[i][j],&Array[n-1-i][n-1-j]);
}
}
else if(i>n/2)
{
if(i%2==1&&Array[i][j]%2==0)/*ż�л�ż*/
{
swap(&Array[i][j],&Array[n-1-i][n-1-j]);
}
else if(i%2==0&&Array[i][j]%2==0)/*���л���*/
{
swap(&Array[i][j],&Array[n-1-i][n-1-j]);
}
}
}
/*End���ĶԵ�*/
/*��������*/
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
/*End��������*/

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
/*���鸳��ֵ*/
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
