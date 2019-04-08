//#pragma once
#include "queue.h"
#include "elev.h"
#include "timer.h"

//int floor_nr;

//check if at floor, if not go down until floor. Returns 1 if success
int floor_init(); 

//combines floor_init, elev_init og timer_init. Gir ut 0 om noe er feil. 1 om alt er OK.
int init_total_elev();

void active_case();

void stop_case();


