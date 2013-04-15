#include<iostream>
#include<cstdio>
#include<stdlib.h>
#define MAX 10000000
using namespace std;
int main()
{
  int temp,j=0;
  char s[100000];
  freopen("data.in","w",stdout);
  for(int i=0;i<MAX;i++)
  {
    temp=rand()%52;
    if(temp<=25)
    {
      printf("%c",temp+'a');
      if(i>MAX-2000&&i<MAX-500)
      {
	s[j]=temp+'a';
	j++;
      }
    }
    else
    {
      printf("%c",temp-26+'A');
      if(i>MAX-2000&&i<MAX-500)
      {
	s[j]=temp-26+'A';
	j++;
      }
    }
  }
  cout<<endl<<s;
  return 0;
}
