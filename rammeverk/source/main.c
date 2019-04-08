#include "elev.h"
#include "elevController.h"
#include "queue.h"
#include "timer.h"
#include <stdio.h>
#include <stdlib.h>

// cd Desktop/G57microbit/heis/rammeverk/

/*
TING SOM MÅ FIKSES:

debug følgende i gdb eller hva det het:
	2etNED fucker seg. 
	3etOPP fucker seg om heisen går opp mot 3 et samtidig som en knapp under er trykket(2ETOPP og 1ETOPP)
	Ordren blir ikke fjernet ser det ut som...

Er den åpen for lenge om man skal på i samme etasje som heisen står i? tror det..

late som at vi har brukt git hele veien.
fikse UML ordentlig
fikse dokumentasjon i det programmet

*/


//extern int task_array[];

int main() {
 /* 	
  	int state=0;
  	int floor_number=0;
  	//int prev_dir=-1;
  	//int counter = 0;

  	enum STATES{
  		IDLE,
  		ACTIVE,
  		STOP
  	};*/

//evt legge elle init i en funksjon
    /*if (!elev_init()) {
            printf("Unable to initialize elevator hardware!\n");
            return 1;
    }

    if (!floor_init()) {
            printf("Unable to initialize elevator to floor!\n");
            return 1;
    }
    timer_init();

    set_prev_dir(DIRN_DOWN);
    printf("prev dir: %d\n",get_prev_dir());
    */

	/*
  	if (!init_total_elev()){
			printf("Elevator initiatize failed. Program quit!");
  			return 1;
  	}

    while(1){ //endless while loop
    	
    check_buttons();
    floor_number=elev_get_floor_sensor_signal();


    if(floor_number >= 0){//den er på et floor
      	set_floor_nr(floor_number);
    	elev_set_floor_indicator(floor_number);
    	//printf("floor number: %d\n",floor_number);
    }

  	if (elev_get_stop_signal()){
  		state = STOP;
  	}
  	else if (is_there_task() && timer_expired()){
  		//state = ACTIVE;
  	}
  	else {
  		state = IDLE;
  	}
  	if (timer_expired()){
  		elev_set_door_open_lamp(0);
  	}

    	switch(state){
    		case IDLE:
    			//elev_set_motor_direction(DIRN_STOP);
    			//gjør ingenting
    		break;

    		case ACTIVE:
          		elev_set_door_open_lamp(0);


    			if(floor_number >= 0){//den treffer en etasje den skal stoppe i.
      				
      				printf("\ncounter:  %d\n",counter );
      				counter++;

      				if (stop_at_floor(floor_number)){
      					printf("\nfloor nr is: %d",floor_number);
	      				printf(" stopp i denne etasjen \n");
	      				elev_set_motor_direction(DIRN_STOP);
	      				elev_set_door_open_lamp(1);
	      				start_timer();
	      				remove_tasks_at_floor(floor_number);
	      				state = IDLE;
	      				break;
	      			} 
	      			if (timer_expired()){

	      				if (continue_dir()){
        				//elev_set_motor_direction(get_prev_dir()); 
        				
    					} else{
		    				//print_task_array();
		    				printf("\nprev_dir blir endret!!\n");
		    				prev_dir = -prev_dir;
		        			change_dir();
		        			//elev_set_motor_direction(get_prev_dir());
		        		}if (stop_when_change_dir()){
		        			elev_set_motor_direction(DIRN_STOP);
		      				elev_set_door_open_lamp(1);
		      				start_timer();
		      				remove_tasks_at_floor(floor_number);
		      				state = IDLE;
		      				break;
		        		}
    				}
      				if (stop_at_floor(floor_number)){
	      				printf("treffer etasje som det er task i\n");
	      				elev_set_motor_direction(DIRN_STOP);
	      				elev_set_door_open_lamp(1);
	      				start_timer();
	      				remove_tasks_at_floor(floor_number);
	      				state = IDLE;
	      			}
    			}
	      			
      				
    		
          		//elev_set_motor_direction(get_prev_dir());
          		//active_case();
    		break;

    		case STOP: //seems ok
    			printf("Elevator emergency stop\n" );
    			elev_set_motor_direction(DIRN_STOP);
    			remove_all_tasks();
    			elev_set_stop_lamp(1);

    			if (elev_get_floor_sensor_signal()>0){ //åpner døra hvis den er i en etasje
    				elev_set_door_open_lamp(1);
    			}
    			else{
    				elev_set_door_open_lamp(0);
    			}

    			while(elev_get_stop_signal()){};

    			elev_set_stop_lamp(0);
    			state=IDLE;
    			if(elev_get_floor_sensor_signal()>0){ //den står i en etasje
    				start_timer();
    			}

    			
    			//stop_case();
    			//state = IDLE;
    		break;
		}*/
    /*if((floor_number >= 0) && (stop_at_floor())){//den treffer en etasje den skal stoppe i.
      elev_set_motor_direction(DIRN_STOP);
      elev_set_door_open_lamp(1);
      start_timer();
      remove_tasks_at_floor(floor_number);
      state = IDLE;
      printf("går inn i funk");
    }
	*/

  //}

    return 0;
}
