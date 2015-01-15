#ifndef SEM_H
#define SEM_H
#define THREAD_SIZE 6

#include <iostream>
#include <pthread.h>
#include <string> 
#include <semaphore.h>
#include <fstream>
#include <unistd.h>


using namespace std;

sem_t SEM;
ofstream myfile;


class sem{
	private:

		pthread_t threads[THREAD_SIZE];
		
	public: 
	
		//constructor
		sem();	
		//create SHARED.TXT file
		void create_file();	
		//create_threads;
		void create_threads();
		//join N threads
		void join_threads();
		
};

#endif
