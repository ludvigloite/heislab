#include "elev.h"
#include "elevController.h"
#include "queue.h"
#include "timer.h"
#include <stdio.h>
#include <stdlib.h>

// cd Desktop/G57microbit/heis/rammeverk/

/*
TING SOM MÅ FIKSES:

fikse UML ordentlig
fikse dokumentasjon i Doxygen!

fikse alt av godkjenninger Git, gdb.
*/


//extern int task_array[];

int main() {
 	
	int state=0;
	int floor_number=0;
  int stopped=0; //flag: the elevator have been stopped.

	enum STATES{
		IDLE,
		ACTIVE,
		STOP
	};
 
	if (!init_total_elev()){
		printf("Elevator initiatize failed. Program quit!");
			return 1;
	}





  while(1){
    	
    check_buttons_and_add_tasks();
    floor_number=elev_get_floor_sensor_signal();

    if(floor_number >= 0){//den er på et floor
      
      set_floor_nr(floor_number);
    	elev_set_floor_indicator(floor_number);
    }

    if(!timer_expired() && task_at_floor()){
      remove_tasks_at_floor(floor_number);
      start_timer();
    }

  	if (elev_get_stop_signal()){
  		state = STOP;
  	} else if (is_there_task() && timer_expired()){
  		state = ACTIVE;
  	} else {
  		state = IDLE;
  	}

  	if (timer_expired()){
  		elev_set_door_open_lamp(0);
  	}





  	switch(state){
  		case IDLE:
  			elev_set_motor_direction(DIRN_STOP); //sikring
  		break;

  		case ACTIVE:
        elev_set_door_open_lamp(0);

				if (stop_at_floor(floor_number) && (floor_number!=-1)){
  				elev_set_motor_direction(DIRN_STOP);
  				elev_set_door_open_lamp(1);
          remove_tasks_at_floor(floor_number);
          start_timer();
  				
          state = IDLE;
  			} 

    		if (timer_expired()){
    			if (continue_dir()){
    				elev_set_motor_direction(get_prev_dir()); 
					} else{
            if(stopped){ //hvis heis nettopp har blitt stoppet
              change_floor_nr();
            } 
        		change_dir(); 
        	} 
        }

        if (stop_at_floor(floor_number) && (floor_number != -1)){
  				elev_set_motor_direction(DIRN_STOP);
  				elev_set_door_open_lamp(1);
  				start_timer();
  				remove_tasks_at_floor(floor_number);
  				state = IDLE;
  			} 
        stopped=0;
  		break;

  		case STOP:
  			printf("Elevator emergency stop\n");
  			elev_set_motor_direction(DIRN_STOP);
  			remove_all_tasks();
  			elev_set_stop_lamp(1);
        stopped=1;

  			if (floor_number >= 0){ //åpner døra hvis den er i en etasje
  				elev_set_door_open_lamp(1);
  			} else{
  				elev_set_door_open_lamp(0);
  			}

  			while(elev_get_stop_signal()){};

  			elev_set_stop_lamp(0);
  			state=IDLE;
  			if(elev_get_floor_sensor_signal() >= 0){ //den står i en etasje
  				start_timer();
  			}
  		break;

      default:
      break;
	  }
  }
    return 0;
}
