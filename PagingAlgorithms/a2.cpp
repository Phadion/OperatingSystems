#include "a2.h"

a2::a2(){	
	clock_ptr = index_to_rmv = page_fault_count = 0;
	for(unsigned int i = 0; i<99; i++){
		a_page.total_index = 0;
		a_page.total_count = 0;
		a_page.in_memory = false;
		a_page.position_in_mem;
		a_page.last_position;
		a_page.u_bit = 0;
		pages.push_back(a_page);		
	}
}

int a2::do_work(){
	memory.clear();
	extract_pages();	
	reset_page_attr();		
	init_page_attr();	
	reference_pages();	
	return page_fault_count;
}

void a2::create_file(){
	ofstream myfile;
	myfile.open("pages.txt");
	
	//generate 100 random numbers ranging from 0 to 99 and write it to file
	if(myfile.is_open()){
		srand(time(NULL));
		for(int i = 0; i < num_pages ; i++){
			myfile << rand() % 100 <<  " " ;	
		}
	 	myfile.close();
	}
	else{
	 	cout<<"error opening file"<<endl;
	 	exit(-1);
	}
}

void a2::extract_pages(){
	ifstream file;
	file.open("pages.txt");

	if(file.is_open()){
		while(!file.eof()){
			getline(file,line);
		}
	}
	else{
		cout<<"error opening file"<<endl;
		exit(-1);
	}
	data = split(line,' ');
}


void a2::init_page_attr(){
	for(unsigned int i = 0; i<data.size(); i++){
		pages[data[i]].total_index += i;	
		pages[data[i]].total_count++;
	}
}

void a2::reference_pages(){	
	int index = 0;//index used to count how many items entered into mem.	
	//load pages into frames until frames are full
	while(memory.size() < frame_size){		
		int page_num = data[index];		
		//cout << "referencing " << page_num << " from memory,a." << endl;
		if(!is_page_fault(page_num)){
			pages[page_num].last_position = index;
			pages[page_num].u_bit = 1;			
			index++;						
			continue;	
		}
		else{
			page_fault_count++;
			//cout << "page fault on: " << page_num << endl << endl;
	 		memory.push_back(page_num);
			pages[page_num].last_position = index;			
			pages[page_num].in_memory = true;			
			pages[page_num].position_in_mem = index;
			pages[page_num].u_bit = 1;
			pages[page_num].total_count--;  
			index++;
		}
	}	
	index_to_rmv = clock_ptr = 0;
	//remove pages processed from while loop above
	data.erase(data.begin(),data.begin()+index);	
	//Frames are full at this point. Use an algorithm to decide which page to remove from frame.
	while(!data.empty()){
		int page_num = data[0];		
		//cout << "referencing " << page_num << " from memory,b." << endl;
		if(!is_page_fault(page_num)){
			data.erase(data.begin(),++data.begin());
			pages[page_num].total_count--;  	
			pages[page_num].last_position = index;			
			pages[page_num].u_bit ^= 1;
			//if not using clock algorithm increment
			if(algo_being_used != 3){
				index++;
			}
			continue;	
		}	
		else{				
			page_fault_count++;
			//cout << "page fault on: " << page_num << endl << endl;
			if(algo_being_used == 1){
				//cout << "using opt" << endl;
				opt_algo(page_num,index);
			}
			else if(algo_being_used == 2){
				//cout << "using lru" << endl;
				lru_algo(page_num,index);
			}
			else{
				//cout << "using clock" << endl;				
				clock_algo(page_num);
			}			
			index++;			
		}
	}
	/*cout << "memory: ";
	for(unsigned int i = 0;i<memory.size();i++){
		cout << memory[i] << " ";
	}
	cout << endl;*/	
}



void a2::opt_algo(int page_to_enter,int current_index){
	int index_to_replace;	
	int page_entering = page_to_enter;
	for(unsigned int i = 0; i<memory.size();i++){
		int page_num = memory[i];
		if(pages[page_num].total_count == 0){
			index_to_replace = i;
		}
		else{
			index_to_replace = find_highest_index();
		}
	}
	
	int page_removed = memory[index_to_replace];
	//cout << "page removed: " << page_removed << endl;
	memory[index_to_replace] = page_entering;
	pages[page_entering].in_memory = true;	
	pages[page_entering].total_count--;
	pages[page_entering].total_index -= current_index; 	
	
	pages[page_removed].in_memory = false;		
	data.erase(data.begin(),++data.begin());
}

void a2::lru_algo(int page_to_enter,int current_index){
	int index_to_replace = lowest_position_index();
	int page_removed = memory[index_to_replace];
		
	memory[index_to_replace] = page_to_enter;	
	pages[page_to_enter].in_memory = true;		
	pages[page_to_enter].last_position = current_index;		
	pages[page_removed].in_memory = false;	
	data.erase(data.begin(),++data.begin());
}

int a2::clock_algo(int page_to_enter){	
	find_zero_ubit_index();	
	int index_to_replace = index_to_rmv;	
	if(clock_ptr == memory.size()-1){
		clock_ptr = 0;
	}
	else{
		clock_ptr = ++index_to_rmv;
	}
	int page_removed = memory[index_to_replace];		
	memory[index_to_replace] = page_to_enter;
	pages[page_to_enter].in_memory = true;	
	pages[page_to_enter].u_bit = 1;
	pages[page_removed].in_memory = false;			
	data.erase(data.begin(),++data.begin());
	return 0;
}


int a2::set_frame_size(){
	int t_frame_size;
	cout << "Please enter a frame size: ";
	cin >> frame_size;
	t_frame_size = frame_size;
	return t_frame_size;
}

void a2::set_algo(int n){
	algo_being_used = n;	
}


int a2::get_frame_size(){
	return frame_size;
}

void a2::reset_page_attr(){
	page_fault_count = 0;	
	for(int i=0; i < pages.size(); i++){
		pages[i].total_index = 0;
		pages[i].total_count = 0;
		pages[i].in_memory = false;
		pages[i].position_in_mem;
		pages[i].last_position;
		pages[i].u_bit = 0;
	}
}

void a2::set_num_ref_pages(){
	cout << "Please enter number of pages to reference: ";
	cin >> num_pages;	
}


////////////***HELPER FUNCTIONS***//////////////////////////////////////
int a2::find_highest_index(){
	int highest = 0;
	int index;
	for(unsigned int i = 0;i<memory.size();i++){
		int current_item = find_index(memory[i]);
		if(current_item > highest){
			index = i;
			highest = current_item;
		}
		else{
			continue;
		}
	}
	return index;
}

int a2::find_index(int n){
	for(unsigned int i=0;i<data.size();i++){
		if(data[i] == n){
			return i;
			break;
		}
	}	
}


void a2::find_zero_ubit_index(){	
	bool ubit_found = false;
	//finding 0 u_bit starting from current_index
	for(unsigned int i = clock_ptr; i<memory.size(); i++){
		if(pages[memory[i]].u_bit == 0){
			ubit_found = true;
			index_to_rmv = i;
			break;		
		}	
		else{
			pages[memory[i]].u_bit = 0;
			continue;
		}
	}
	//if 0 u_bit is not found starting from current_index, start from 
	//beginning	
	if(ubit_found == false){
		for(unsigned int i = 0; i<memory.size(); i++){	
			if(pages[memory[i]].u_bit == 0){
				ubit_found = true;
				index_to_rmv = i;
				break;		
			}	
			else{
				pages[memory[i]].u_bit = 0;
				continue;
			}
		}
	}
}
int a2::lowest_position_index(){	
	int lowest = pages[memory[0]].last_position;	
	int index = 0;	
	for(unsigned int i= 0; i<memory.size(); i++){					
		int current_index = pages[memory[i]].last_position;		
		if(current_index < lowest){
			index = i;			
			lowest = current_index;
		}
		else{
			continue;
		}		
	}
	return index;
}

bool a2::is_page_fault(int page_num){
	if(pages[page_num].in_memory == false){
		return true;
	}
	return false;
}

vector<int>& a2::split(const string &s, char delim, vector<int> &elems ){
	stringstream ss(s);
	string item;
	while(getline(ss,item,delim)){
		int t_item = string_to_int(item);
		elems.push_back(t_item);
	}
	return elems;
}

vector<int> a2::split(const string &s, char delim){
	vector<int> elems;
	split(s,delim,elems);
	return elems;
}

int a2::string_to_int(string s){
	istringstream instr(s);
	int n;
	instr >> n;
	return n;
}






	
