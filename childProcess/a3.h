#ifndef A3_H
#define A3_H

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sstream>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/types.h>
#include <signal.h>
#include <ctime>
#include <vector>

using namespace std;

vector< int > child_pids;	
class a3{
	private:
		pid_t pid;
		time_t current_time;
		int status;
		int time_to_run;


	public:

		//constructor
		a3();
		//print current time
		void the_time();
		//return uptime
		void print_uptime();
		//print minutes left
		void print_minutes_left();
		//make children work
		void child_labor(int child_no);
		//set run time
		void set_time(string str);
		//string to integer
		int string_to_int(string s);
		//create children
		void create_children(pid_t pid);
		void terminate_children(pid_t pid);
};
#endif
