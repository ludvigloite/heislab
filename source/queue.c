#include "queue.h"
#include <stdio.h>


// {01, 01 up, 01 down, 02, 02 up, 02 down, 03, 03 up, 03 down, 04, 04 up, 04 down} //Set all elements to 0
int task_array[12]={};
int prev_dir; 
int floor_nr;

void check_buttons_and_add_tasks(){
	for (int floor = 0; floor < 4; floor++){
		for (int button = 0; button < 3; button++){
			if ((button == 0 && floor == 3) || (button == 1 && floor == 0)){
				continue;
			}
			else if (elev_get_button_signal(button,floor)){
				add_task(button,floor);
			}
		}
	}
}

void add_task(int button, int floor){
	int diff = 0; //add 1 for up  button and 2 for down button.
	if (button==0){diff=1;} 
	else if (button==1){diff=2;} 
	task_array[floor*3+diff]=1;
	elev_set_button_lamp(button,floor,1);
}

void remove_tasks_at_floor(int floor){
	if (floor!=-1){
		for (int c = 0; c<3; c++){
			task_array[floor*3+c]=0;
			
			if (!((c==0 && floor ==3) || (c==1 && floor==0))){
				elev_set_button_lamp(c,floor,0);
			}	
		}
	}
}

void remove_all_tasks(){
	for (int c = 0; c<4; c++){
		remove_tasks_at_floor(c);
	}
}

int stop_at_floor(int floor_numb){
	if (floor_numb!=-1){
		if(task_array[floor_numb*3]){
			return 1;
		}
		if(prev_dir==1){
			if(task_array[floor_numb*3+1]){
				return 1;
			}
		} else if(prev_dir==-1){
			if(task_array[floor_numb*3+2]){
				return 1;
			}
		}
	}
	return 0;
}

int task_at_floor(){
	for (int c =0; c<3; c++){
		if (task_array[floor_nr*3+c]){
			return 1;
		}
	}
	return 0;
}

int continue_dir(){
	int ans=0;
	if (prev_dir > 0){
		for (int c = (floor_nr*3+3); c<12; c++){
			if (task_array[c]){
				ans = 1;
			}
		}
	} else{
		for (int i = 0; i < (floor_nr*3); i++){
			if (task_array[i]){
				ans = 1;
			}
		}
	}
	return ans;
}

int is_there_task(){
	for (int c =0; c<12; c++){
		if (task_array[c]){
			return 1;
		}
	}
	return 0;
}

void set_prev_dir(int dir){
	if (dir!=0){
		prev_dir=dir;
	}
}

int get_prev_dir(){
	return prev_dir;
}

void change_dir(){
	prev_dir = -prev_dir;
}

void set_floor_nr(int floor){
	floor_nr = floor;
}

int get_floor_nr(){
	return floor_nr;
}

void print_task_array(){
	for (int c = 0; c<12; c++){
		printf("%d\t",task_array[c]);
	}printf("\n" );
}

void change_floor_nr(){
	if (prev_dir==1){
		floor_nr++;
	}else if (prev_dir==-1) {
		floor_nr--;
	}
}