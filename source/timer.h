/**
* @file
* @brief Module for the timer and the timer logic.
*/


#include <time.h>

time_t time_end;

/**
* @brief Set @p time_end to 3 seconds from the current time.
*
* @param[out] time_end Time stamp 3 seconds after the timer is started.
*/
void start_timer(); 

/**
* @brief Check if the current time is greater than, or equal to @p time_end.
*
*@param[out] time_end Time stamp 3 seconds after the timer is started.
*
* @return 0 if @p time_end is greater than current time, 1 otherwise.
*/
int timer_expired();

/**
* @brief Set @p time_end to current time.
*
*@param[out] time_end Time stamp 3 seconds after the timer is started.
*/
void timer_init();