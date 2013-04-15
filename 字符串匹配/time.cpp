#include<iostream>
#include"timecounter.h"

void _function()
{
	for(int i=0;i<214748364;i++);
	for(int j=0;j<214748364;j++);
}

int main(void)
{
  Time_start();
  _function();
  Time_end();
	return 0;
}


