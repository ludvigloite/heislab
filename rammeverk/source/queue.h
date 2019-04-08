//#pragma once

#include "elev.h"
//#include "elevController.h"



// {01, 01 up, 01 down, 02, 02 up, 02 down, 03, 03 up, 03 down, 04, 04 up, 04 down} //Set all elements to 0



//Checking elevator buttons. Calling add_task if active. Must be in loop.
void check_buttons();

//Add task to task_array
void add_task(int button, int floor);

//removes all tasks at certain floor from task array
void remove_tasks_at_floor(int floor);

//remove all tasks in task_array
void remove_all_tasks();

//return 1 if stop at floor, return 0 otherwise
int stop_at_floor(int floor_numb);

//return 1 if continue in same direction, 0 otherwise.
int continue_dir();

//return 1 if task in task_array, 0 otherwise;
int is_there_task();

void set_prev_dir(int dir);

int get_prev_dir();

void change_dir();

void set_floor_nr(int floor);

int get_floor_nr();

void print_task_array();

int stop_when_change_dir();

void change_floor_nr();

/*enum task_buttons{
  FlOOR_1,
  UP_1,
  DOWN_1,
  FlOOR_2,
  UP_2,
  DOWN_2,
  FlOOR_3,
  UP_3,
  DOWN_3,
  FlOOR_4,
  UP_4,
  DOWN_4
};*/


