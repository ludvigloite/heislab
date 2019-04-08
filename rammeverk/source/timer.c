#include "timer.h"
#include <stdio.h>


void start_timer(){
	time_t start = time(NULL);
	time_end = start + 3;
}

int timer_expired(){
	return (time_end <= time(NULL));
}

void timer_init(){
	time_end = time(NULL);
}