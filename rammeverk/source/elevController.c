#include "elevController.h"
#include <stdio.h>


extern int task_array[];

int floor_init(){ //funker
	set_prev_dir(DIRN_DOWN);
	while(elev_get_floor_sensor_signal()<0){
        elev_set_motor_direction(DIRN_DOWN);
    }
    elev_set_motor_direction(DIRN_STOP);
    //set_floor_nr(elev_get_floor_sensor_signal()); //0-3
    elev_set_floor_indicator(elev_get_floor_sensor_signal());
    //printf("%d\n",floorNr);
    return 1;
}

int init_total_elev(){
	if (!elev_init()) {
            printf("Unable to initialize elevator hardware!\n");
            return 0;
    }
    if (!floor_init()) {
            printf("Unable to initialize elevator to floor!\n");
            return 0;
    }
    timer_init(); //kan ikke gå feil..trenger ikke if...
    printf("Elevator initialized\n");
    return 1;
}


void active_case(){

	elev_set_door_open_lamp(0);

    if (continue_dir()){
        elev_set_motor_direction(get_prev_dir());    
    }
    else{
        change_dir();
        elev_set_motor_direction(get_prev_dir());
    }
    
}

void stop_case(){
	printf("stop\n" );
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
    //state=IDLE;
    if(elev_get_floor_sensor_signal()>0){
    	start_timer();
    }

}
