#include "elevController.h"
#include <stdio.h>


extern int task_array[];

int floor_init(){
	set_prev_dir(DIRN_DOWN);
	while(elev_get_floor_sensor_signal()<0){
        elev_set_motor_direction(DIRN_DOWN);
    }

    elev_set_motor_direction(DIRN_STOP);
    elev_set_floor_indicator(elev_get_floor_sensor_signal());
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
    timer_init(); //Cannot fail, so we do not need if statement.
    printf("Elevator initialized\n");
    return 1;
}

