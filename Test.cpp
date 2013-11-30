#include<iostream>
#include"timecounter.h"
int main()
{
    Time_start();
    for(int i=0;i<=40000000;i++);
    Time_end();
    return 0;
}
