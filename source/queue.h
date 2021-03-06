/**
* @file
* @brief Module for keeping track of tasks and task logic.
*/


#include "elev.h"

/**
* @brief Check elevator buttons. Calling @c add_task() if active.
*
* @param[out] task_array[] Array of tasks. 12 elements. Inactive : 0, Active : 1.
*/
void check_buttons_and_add_tasks();

/**
* @brief Add task to @p task_array. Being used in @c check_buttons_and_add_tasks(). 
*
* @param[in] button Pressed button. Up, down or floor button.
* @param[in] floor Floor.
* @param[out] task_array[] Array of tasks. @c add_task() sets corresponding element to 1.
*/
void add_task(int button, int floor);

/**
* @brief Remove all tasks at certain floor from @p task_array.
*
* @param[in] floor Floor.
* @param[out] task_array[] Array of tasks. 12 elements. Inactive : 0, Active : 1.

*/
void remove_tasks_at_floor(int floor);

/**
* @brief Remove all tasks in @p task_array, by setting the elements to 0.
*
* @param[out] task_array[] Array of tasks. 12 elements. Inactive : 0, Active : 1.
*/
void remove_all_tasks();

/**
* @brief Determine if the elevator have to stop at a given floor.
*
* @param[in] floor_numb The floor number if elevator is at floor. floor_numb is -1 if not at floor.
* @param[out] prev_dir Previous direction.
*
* @return 1 if the elevator has to stop at the given floor. 0 otherwise.
*/
int stop_at_floor(int floor_numb);

/**
* @brief Are there any tasks on the floor.
*
* @param[in] floor_nr Floor number last detected by floor sensor.
* @param[in] task_array Array of tasks. 12 elements. Inactive : 0, Active : 1.
*
* @return 1 if there are one or more tasks at current floor. 0 otherwise.
*/
int task_at_floor();

/**
* @brief Determine the direction of the elevator.
*
* @param[in] prev_dir Previous direction.
* @param[in] task_array[] Array of tasks. 12 elements. Inactive : 0, Active : 1.
*
* @return 1 if the elevator has to continue in the same direction,
* 0 if it has to change direction.
*/
int continue_dir();

/**
* @brief Determine if there are any tasks in @p task_array.
*
* @param[in] task_array[] Array of tasks. 12 elements. Inactive : 0, Active : 1.
*
* @return 0 if @p task_array is empty. 1 otherwise.
*/
int is_there_task();

/**
* @brief Set function for @p prev_dir.
*
* @param[out] prev_dir Previous direction.
*/
void set_prev_dir(int dir);

/**
* @brief Get function for @p prev_dir.
*
* @param[in] prev_dir Previous direction.
*
* @return @p prev_dir. 1 for up. -1 for down.
*/
int get_prev_dir();

/**
* @brief Reverse @p prev_dir.
*
* @param[out] prev_dir Previous direction.
*/
void change_dir();

/**
* @brief Set function for @p floor_nr.
*
* @param[out] floor_nr Floor number last detected by floor sensore.
*/
void set_floor_nr(int floor);

/**
* @brief Get function for @p floor_nr.
*
* @param[in] floor_nr Floor number last detected by floor sensore.
*
* @return @p floor_nr. An integer corresponding to the floor.
*/
int get_floor_nr();

/**
* @brief Print task array with tab between elements.
*
* @param[in] task_array[] Array of tasks. 12 elements. Inactive : 0, Active : 1.
*/
void print_task_array();

/**
* @brief Modify @p floor_nr to desired value after the elevator has been stopped between floors.
*
* @param[in] prev_dir Previous direction.
* @param[out] floor_nr Floor number last detected by floor sensore.
*/
void change_floor_nr();