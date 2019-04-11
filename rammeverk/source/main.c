/**
* @file
* @brief main
*/

#include "elev.h"
#include "elevController.h"
#include "queue.h"
#include "timer.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
 	
  //The elevator initializes
	int state=0;
	int floor_number=0;
  int stopped=0; //flag: 1 if STOP button has been pressed. Is set to 0 after first iteration in ACTIVE. Assures correct behaviour when stopped between floors.

	enum STATES{
		IDLE,
		ACTIVE,
		STOP
	};
 
	if (!init_total_elev()){
		printf("Elevator initiatize failed. Program quit!");
			return 1;
	}



  //starts infinite loop
  while(1){

    //check every button, and add tasks to task_array[]
    check_buttons_and_add_tasks();
    floor_number=elev_get_floor_sensor_signal();

    if(floor_number >= 0){//elevator
      
      set_floor_nr(floor_number);
    	elev_set_floor_indicator(floor_number);
    }

    //timer will be started at the end of the button push. 
    if(!timer_expired() && task_at_floor()){
      remove_tasks_at_floor(floor_number);
      start_timer();
    }

    //sets state
  	if (elev_get_stop_signal()){
  		state = STOP;
  	} else if (is_there_task() && timer_expired()){
  		state = ACTIVE;
  	} else {
  		state = IDLE;
  	}


    //closes door if timer is expired.
  	if (timer_expired()){
  		elev_set_door_open_lamp(0);
  	}




  	switch(state){
  		case IDLE:
  			elev_set_motor_direction(DIRN_STOP);
  		break;

  		case ACTIVE:
        elev_set_door_open_lamp(0); //Assure that door is always closed when the elevator is moving

        //Execute all tasks at floor if there is a task at the floor in correct direction.
				if (stop_at_floor(floor_number) && (floor_number!=-1)){
  				elev_set_motor_direction(DIRN_STOP);
  				elev_set_door_open_lamp(1);
          remove_tasks_at_floor(floor_number);
          start_timer();
  				
          state = IDLE;
  			} 

        //change direction if needed.
    		if (timer_expired()){
    			if (continue_dir()){
    				elev_set_motor_direction(get_prev_dir()); 
					} else{
            if(stopped){
              change_floor_nr(); //Modify floor_nr to desired value after the elevator has been stopped between floors.
            } 
        		change_dir(); 
        	} 
        }

        //Execute all tasks if there is a task at the floor in correct direction, which is now changed.
        if (stop_at_floor(floor_number) && (floor_number != -1)){
  				elev_set_motor_direction(DIRN_STOP);
  				elev_set_door_open_lamp(1);
  				start_timer();
  				remove_tasks_at_floor(floor_number);
  				state = IDLE;
  			} 
        stopped=0; //clear stopped flag

  		break;

  		case STOP:
        //stop elevator and remove tasks.
  			printf("Elevator emergency stop\n");
  			elev_set_motor_direction(DIRN_STOP);
  			remove_all_tasks();
  			elev_set_stop_lamp(1);
        stopped=1;

  			if (floor_number >= 0){ //Opens door if elevator is at a floor
  				elev_set_door_open_lamp(1);
  			} else{
  				elev_set_door_open_lamp(0);
  			}

  			while(elev_get_stop_signal()){}; //Waits until STOP button is released. Blocks all input.

  			elev_set_stop_lamp(0);
  			state=IDLE;
  			if(elev_get_floor_sensor_signal() >= 0){ 
  				start_timer();
  			}
  		break;

      default:
      break;
	  }
  }
    return 0;
}
