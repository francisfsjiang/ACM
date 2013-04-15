#include<iostream>
#include<cstdio>
#include<cstring>
#include"timecounter.h"
#define MAX 60000000
using namespace std;
char s1[MAX],s2[MAX];
int main()
{
  Time_start();
  freopen("data.in","r",stdin);
  freopen("data.out","w",stdout);
  cin>>s1>>s2;
  cout<<strstr(s1,s2)<<endl;
  Time_end();
  return 0;
}
