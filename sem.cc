#include "sem.h"

sem::sem(){
	//file_name = str;
}

void sem::create_file(){
	ofstream myfile("SHARED.txt");

	if(myfile.is_open()){
		cout<<"file successfully created"<<endl;
		myfile.close();
	}
	else{
		cout<<"error opening file"<<endl;
	}
	
}

void *sem::write_to_file(void *tid){
	int t_tid = (int) tid;

	sem_wait(&SEM);

	ofstream myfile("SHARED.txt",std::ofstream::app);

	if(myfile.is_open()){

		for(int i = 0; i<10; i++){
			myfile << "thread id: "<<t_tid + 1 <<endl;
			cout << "Thread " << t_tid + 1 << "is running." << endl;
			myfile.close();
			sem_post(&SEM);

			if(t_tid % 2 == 0){
				sleep(1);
			}
			else{
				sleep(2);
			}
		}
		pthread_exit(NULL);

	}
	else{
		cout << "Error opening file" << endl;
	}

}

void sem::create_threads(){

	for(int i = 0; i< 6 ; i++){
		int status = pthread_create(&threads[i],NULL,write_to_file,(void *)i);

		if(status != 0){
			cout << "pthread_create returned error code " << status << endl;
			exit(-1);
		}
	}

}

void sem::join_threads(){
	for(int i = 0; i < 6 ; i++){
		pthread_join(threads[i],NULL);
	}
}

// void sem::test_write(){
// 	ofstream myfile("SHARED.txt",std::ofstream::app);

// 	if(myfile.is_open()){
// 		myfile<<"Hello"<<endl;
// 		cout<<"writig to file"<<endl;
// 		myfile.close();
// 	}
// 	else{
// 		cout<<"error writing to file"<<endl;
// 	}
	
// }




int main(){
	sem test;
	test.create_file();

	sem_init(&SEM,0,1);

	test.create_threads();
	test.join_threads();

	sem_destroy(&SEM);

	exit(0);
	
	
	
	return 0;
}