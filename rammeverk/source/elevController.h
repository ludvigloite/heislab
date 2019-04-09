/**
* @file
* @brief A simple library for doing operations on memory
* buffers consisting of integers
*/


#include "queue.h"
#include "elev.h"
#include "timer.h"

//check if at floor, if not go down until floor. Returns 1 if success
/**
* @brief Check if the elevator is at a floor. If not, move down until the elevator is at a floor.
*
* @param[out] prev_dir Previous direction.
*
* @return 1 on succes. 0 otherwise.
*/
int floor_init(); 

//combines floor_init, elev_init og timer_init. Gir ut 0 om noe er feil. 1 om alt er OK.
/**
* @brief Initialising the elevator. Calls @c elev_init, @c floor_init and @c timer_init. 
* The elevator ends up at a defined state, where we know what floor it is at.
*
* @return 1 on succes. 0 otherwise.
*/
int init_total_elev();