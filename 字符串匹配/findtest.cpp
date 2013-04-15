#include<iostream>
#include<cstdio>
#include"timecounter.h"
using namespace std;
int main()
{
  Time_start();
  freopen("data.in","r",stdin);
  freopen("data.out","w",stdout);
  string s1,s2;
  cin>>s1>>s2;
  cout<<s1.find(s2)<<endl;
  Time_end();
  return 0;
}
