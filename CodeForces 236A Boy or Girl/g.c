#include<stdio.h>
#include<string.h>
int main()
{
    char s[10000];
    int data[27]={0},i,l,sum=0;
    scanf("%s",s);
    l=strlen(s);
    for(i=0;i<l;i++)data[s[i]-97]++;
    for(i=0;i<26;i++)if(data[i]>0)sum++;
    if(sum%2==0)printf("CHAT WITH HER!");
    else printf("IGNORE HIM!");
    return 0;
}
