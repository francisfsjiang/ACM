#include<iostream>
#include<cstdio>
using namespace std;
int explode(int i)
{
  //cout<<i<<endl;
  //if(i<=1)return 0;
  //return explode(i-1);
  explode(i);
}

int main()
{
  int n;
  cin>>n;
  cout<<explode(n);
  getchar();
  getchar();
  return 0;
}
