NAME: Jose Paterno, Jonathan Dabu
CLASS ACCOUNT: masc1418,masc1417
CLASS INFO.: CS 570, Summer 2014
ASSIGMENT INFO: Assignment #3, Child Processes
FILE NAME: README.txt


FILE MANIFEST: 

a3.h
a3.cpp
child_process_sim.cpp
README.txt

COMPILE INSTRUCTIONS: 

To compile, type: 

1) make clean
2) make

OPERATING INSTRUCTIONS: 

After compilation. Type in ./a3. This will set the time for the program to run to 10
seconds. If you want to run the program run for a specific amount of seconds, type
./a3 (number of seconds here). 

DESIGN DECISIONS: 

Usual header file and .cpp file. 

main() method in a separate .cpp file called child_process_sim.cpp

DEFICIENCIES: 

Didn't check for user input. 
	- when user puts a3 hello. hello is translated to ascii code (i think)
		and program runs forever. 

Really no protection of implementation of a3.h. 
	- couldn't figure out how to import a3.h only and have program run. 

*Program is still fully functional and implements what the assignment wanted.

LESSONS LEARNED: 
We learned how to use fork() properly and learned how to end/kill processses. 

Creating processes allows you to save time and lets you work more efficiently. It 
allow code reuse to happen. By creating child processes, human error is eliminated.  

