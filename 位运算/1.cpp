#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include"timecounter.h"
using namespace std;
int main()
{
  int n;
  scanf("%d",&n);
  Time_start();
  //while(n--)rand()>>1;
  while(n--)rand()/2;
  Time_end();
  system("pause");
  return 1;
}
