/*
title: SSSTA3 - DIV1 �C Math �C F �C Opposites Attract
author : neveralso
*/
#include<stdio.h>
int main()
{
    int n,i;
    long long sum,x;
    long long  data[50]={0};
    scanf("%d",&n);
    for(i=1;i<=n;i++)//ͳ��
    {
        scanf("%I64d",&x);
        data[x+10]++;
    }
    sum=0;
    sum+=data[10]*(data[10]-1)/2;//����ϲ��ֵΪ0�����
    for(i=1;i<=10;i++)sum+=data[10-i]*data[10+i];//�������
    printf("%I64d",sum);
    return 0;
}
