#include<iostream>
#include<cstdio>
#include"timecounter.h"
using namespace std;
int next[5000000];
int main()
{
    Time_start();
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    string s1,s2;
    int l1,l2,k,i,j;
    cin>>s1>>s2;
    l1=s1.size();
    l2=s2.size();
    next[1]=0;
    k=0;
   // for(i=2;i<=l2;i++)
   // {
   //     for(;k>0&&s2[k]!=s2[i-1];k=next[k]);
   //     if(s2[k]==s2[i-1])k++;
   //     next[i]=k;
   // }
    for(i=2;i<=l2;i++)
    {
        for(;k>0&&s2[k]!=s2[i-1];k=next[k]);
        if(s2[k]==s2[i-1])k++;
        next[i-1]=k;
    }
    cout<<s2<<endl;
    for(int i=1;i<=s2.size();i++)cout<<next[i];
    k=0;
   // for(i=0;i<l1;i++)
   // {
   //     for(;k>0&&s1[i]!=s2[k];k=next[k]);
   //     if(s1[i]==s2[k])k++;
   //     if(k==l2)break;
   // }
    cout<<i-l2;
    Time_end();
    return 0;
}
