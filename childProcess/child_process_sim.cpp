#include "a3.cpp"


int main(int argc,char *argv[]){
	string seconds;
	(argc < 2) ? seconds="10":seconds=argv[1];
	a3 test;
	test.set_time(seconds);
	pid_t pid = getpid();
	test.create_children(pid);
	test.terminate_children(pid);
	return 0;
}
