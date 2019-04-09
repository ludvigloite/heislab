/**
* @file
* @brief A simple library for doing operations on memory
* buffers consisting of integers
*/


#include <time.h>

//time_t start;
time_t time_end;

//starter timer, setter time_end til nåtid+3 sek
/**
* @brief Set @p time_end to 3 seconds from the current time.
*
* @param[out] time_end Time stamp 3 seconds after the timer is started.
*/
void start_timer(); 

//gir ut 1 om nåtid er større enn time_end, altså at tiden er gått ut.
/**
* @brief Check if the current time is greater than, or equal to @p time_end.
*
*@param[out] time_end Time stamp 3 seconds after the timer is started.
*
* @return 0 if @p time_end is greater than current time, 1 otherwise.
*/
int timer_expired();

//setter time_end til nåtid. Gjør at timer_expired gir 1 helt til start_timer blir kalt og ny end_time settes
/**
* @brief Set @p time_end to current time.
*
*@param[out] time_end Time stamp 3 seconds after the timer is started.
*/
void timer_init();