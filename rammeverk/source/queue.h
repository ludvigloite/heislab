#include "elev.h"



//Checking elevator buttons. Calling add_task if active. Must be in loop.
void check_buttons_and_add_tasks();

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

//setter variabelen prev_dir til input dir.
void set_prev_dir(int dir);

//returnerer variabelen prev_dir.
int get_prev_dir();

//Reverserer prev_dir. Dvs. prev_dir = -prev_dir
void change_dir();

//setter variabelen floor_nr til input floor.
void set_floor_nr(int floor);

//Returnerer variabelen floor_nr
int get_floor_nr();

//Printer task array med tab mellom alle elementer.
void print_task_array();

//Tilpasser floor_nr etter stopp mellom etasjer
void change_floor_nr();