Name: 
	Jose Paterno
Class account user name: 
	masc1418
Class information: 
	CS570 Summer 2014
Assignment information: 
	Assignment #1, Creation and management of threads using POSIX
Filename of this file: 
	README.txt



File Manifest: 
	Makefile: the make file for this specific assignment.
	SHARED.txt: the file that each thread wrties to.
	sem.cpp: the program.
	sem.h: the header file to sem.cpp/the include file.
	sem: the exectuable. 
	
Compile Instructions: 
	To compile the program: 
		1) type "make clean"
		2) type "make"

Operating Instructions: 
	There are no comman line arguments that is used in the program. Compile
	the file then run sem (./sem). 

Design Decisions: 
	I made the main function as simple as possible, which is one line. The
	internal methods/routines are ran inside the constructor of the class. 
	
Deficiencies: 
	The program can most likely be written more elegantly than I did. 
	
Lessons Learned: 
	The main lesson I learned was using POSIX. To complete this program I
	had to do extra research online about the functions necessary to use 
	for this program. I had to look at the man pages and study the
	functionality of the header pthread.h. I had to learn what each
	parameter meant. This project also helped me review C++. 
