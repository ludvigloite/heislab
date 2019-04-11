/**
* @file
* @brief Module for initializing the elevator
*/


#include "queue.h"
#include "elev.h"
#include "timer.h"

/**
* @brief Check if the elevator is at a floor. If not, move down until the elevator is at a floor.
*
* @param[out] prev_dir Previous direction.
*
* @return 1 on succes. 0 otherwise.
*/
int floor_init(); 

/**
* @brief Initialising the elevator. Calls @c elev_init, @c floor_init and @c timer_init. 
* The elevator ends up at a defined state, where we know what floor it is at.
*
* @return 1 on succes. 0 otherwise.
*/
int init_total_elev();