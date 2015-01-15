#include "a2.cpp"

int main(){
	a2 page_sim;
	page_sim.set_frame_size();
	page_sim.set_num_ref_pages();
	page_sim.create_file();
	
	
	page_sim.set_algo(1);
	cout << "Number of faults with opt: " << page_sim.do_work() << endl;
	
	page_sim.set_algo(2);
	cout << "Number of faults with lru: " << page_sim.do_work() << endl;
	
	page_sim.set_algo(3);
	cout << "Number of faults with clock: " << page_sim.do_work() << endl;
		
	return 0;
}



