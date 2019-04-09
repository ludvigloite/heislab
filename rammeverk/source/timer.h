#include <time.h>

//time_t start;
time_t time_end;

//starter timer, setter time_end til nåtid+3 sek
void start_timer(); 

//gir ut 1 om nåtid er større enn time_end, altså at tiden er gått ut.
int timer_expired();

//setter time_end til nåtid. Gjør at timer_expired gir 1 helt til start_timer blir kalt og ny end_time settes
void timer_init();