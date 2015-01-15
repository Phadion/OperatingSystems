#include "sem.h"

sem::sem(){
	create_file();
	sem_init(&SEM,0,1);
	create_threads();
	join_threads();
	sem_destroy(&SEM);
	cout<<"Program Successful."<<endl;
}
	
//creates SHARED.txt file
void sem::create_file(){
	myfile.open("SHARED.txt");

	if(myfile.is_open()){
		myfile.close();
	}
	else{
		cout<<"error opening file"<<endl;
		exit(-1);
	}
	
}

//shared resource
static void* write_to_file(void *tid){
	int t_tid = (int) tid;	
			
	for(int i = 0; i<10; i++){
		//if tid is even sleep for 2 seconds, otherwise sleep for 
		//3 seconds
		if(t_tid % 2 == 0){
			sleep(2);
		}
		else{
			sleep(3);
		}
						
		sem_wait(&SEM);	
		myfile.open("SHARED.txt",std::ofstream::app);	
		myfile << "Thread id: "<<t_tid + 1 <<endl;
		cout << "Thread " << t_tid + 1 << " is running." << endl;
		myfile.close();
		sem_post(&SEM);				
											
	}		
	pthread_exit(NULL);
}
//creates 6 threads
void sem::create_threads(){
	for(int i = 0; i< THREAD_SIZE ; i++){
		int status = pthread_create(&threads[i],NULL,write_to_file,(void *)i);

		if(status != 0){
			cout << "pthread_create returned error code "<<status<<endl;
			exit(-1);
		}
	}

}

void sem::join_threads(){
	for(int i = 0; i < THREAD_SIZE ; i++){
		int status = pthread_join(threads[i],NULL);
		if(status != 0){
			cout << "pthread_join returned error code: "<<status<<endl;
			exit(-1);
		}
	}
}


int main(){
	sem test;	
	return 0;
}
