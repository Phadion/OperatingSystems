#include "a3.h"

a3::a3(){
	current_time = time(NULL);
}

void a3::set_time(string str){
	time_to_run = string_to_int(str);
}

// Prints the current time
void a3::the_time(){
	time_t ctt;	
	while (1) {
		ctt = time(0);
		tm *ltm = localtime(&ctt);
		printf("current time: %02d:%02d:%02d\n"
			,ltm->tm_hour,ltm->tm_min,ltm->tm_sec);
		sleep(1);
	}
}

// Print the current system uptime
// Uses an execv command
void a3::print_uptime(){
	while (1) {				
		if (!fork()) {
			execl("/usr/bin/uptime","uptime",NULL);
		}
		sleep(5);
	}
}

// Print minutes left
// Also does a kill 9 when time has ran out
void a3::print_minutes_left(){
	while(1) {
		int seconds = time_to_run%60;		
		int minutes = time_to_run/60;
		string min_sec;
		(minutes == 0)? min_sec = "seconds":min_sec = "minutes";
		printf("%02d:%02d %s left.\n",minutes,seconds,min_sec.c_str());		
		if (minutes == 0 && seconds == 0) {			
			kill(child_pids[0],9);
			kill(child_pids[1],9);
		}
		time_to_run--;
		sleep(1);
	}
}

// Used by child_process_sim to fire off the proper function
void a3::child_labor(int child_no){
		switch (child_no){
			case 1:
				the_time();
				break;
			case 2:
				print_uptime();
				break;
			case 3:
				print_minutes_left();
				break;
		}
}

void a3::create_children(pid_t pid){
	for(unsigned int i = 1; i<=3; i++){
		pid = fork();
		// If pid is under 0, there's an error
		if (pid < 0) {
			cout<< "Error with fork!" << endl;
			exit(-1);
		}
		// If pid is equal to zero it's the child process, do eet
		if(pid == 0){
			// Make the fork do something
			child_labor(i);
			break;
		} 
		else {
			child_pids.push_back(pid);
		}

	}
}

void a3::terminate_children(pid_t pid){
	if(pid > 0){
		waitpid(child_pids[1],NULL,0);
		kill(child_pids[2],9);		
		cout << "All children have terminated.";
		cout << " Parent terminating."<<endl;
	}
}

int a3::string_to_int(string s){
	istringstream instr(s);
	int n;
	instr >> n;
	return n;
}
