/*
title: SSSTA3 - DIV1 – Math – F – Opposites Attract
author : neveralso
*/
#include<stdio.h>
int main()
{
    int n,i;
    long long sum,x;
    long long  data[50]={0};
    scanf("%d",&n);
    for(i=1;i<=n;i++)//统计
    {
        scanf("%I64d",&x);
        data[x+10]++;
    }
    sum=0;
    sum+=data[10]*(data[10]-1)/2;//计算喜好值为0的情况
    for(i=1;i<=10;i++)sum+=data[10-i]*data[10+i];//其他情况
    printf("%I64d",sum);
    return 0;
}
