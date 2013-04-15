#ifndef TIMECOUNTER_H_INCLUDED
#define TIMECOUNTER_H_INCLUDED
#include<iostream>
#include<sys/time.h>
using namespace std;
struct timeval Time_startr,Time_endr;
double Time_used;
/*
struct timeval 
{
	time_t      tv_sec;    
	suseconds_t tv_usec;
}
*/
void Time_start()
{
	gettimeofday(&Time_startr,NULL);
}

void Time_end()
{
	gettimeofday(&Time_endr,NULL);
	Time_used=(Time_endr.tv_sec-Time_startr.tv_sec)+(double)(Time_endr.tv_usec-Time_startr.tv_usec)/1000000;
	cout<<endl<<"Cost time:"<<Time_used<<" s"<<endl;
}


#endif // TIMECOUNTER_H_INCLUDED
