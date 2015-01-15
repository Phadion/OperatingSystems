#ifndef A2_H
#define A2_H

#include <iostream>
#include <vector> 
#include <fstream>
#include <unistd.h>
#include <string> 
#include <cstdlib>
#include <stdlib.h> 
#include <sstream>

using namespace std;



class a2{

	private:
		struct page_struct{
			int total_index;
			int total_count;
			bool in_memory;
			int position_in_mem;
			int last_position;
			int u_bit;
		};
		
		vector <page_struct> pages;	
		vector <int> memory;
		page_struct a_page;
		string line;
		vector <int> data;
		int frame_size;
		int page_fault_count;
		//1=opt,2=lru,3=clock
		int algo_being_used;
		int clock_ptr;
		int index_to_rmv;
		int num_pages;
	public: 
		//constructor
		a2();
		//do work!
		int do_work();
		//create pages.txt file
		void create_file();
		//populate vector of pages
		void extract_pages();
		//parse into a vector of ints
		vector <int>  &split(const string &s,char delim,vector <int> &elems);
		vector <int> split(const string &s,char delim);	
		//string to int 
		int string_to_int(string s);
		//initialize page attributes
		void init_page_attr();
		//load pages into frames;
		void reference_pages();		
		//checks for page fault;
		bool is_page_fault(int page_num);
		//use opt algo
		void opt_algo(int page_to_enter,int current_index);		
		//use lru algo
		void lru_algo(int page_to_enter,int current_index);
		//returns lowest position index.Used for LRU algo
		int lowest_position_index();		
		//runs clock algorithm. returns updated index value
		int clock_algo(int page_to_enter);
		//find u bit that is 0
		void find_zero_ubit_index();
		//set frame size
		int set_frame_size();
		//get frame size
		int get_frame_size();
		//set algorithm to use
		void set_algo(int n);	
		//reset page attributes
		void reset_page_attr();	
		//sets number of pages to write to pages.txt
		void set_num_ref_pages();
		int find_highest_index();
		int find_index(int n);
};
#endif
