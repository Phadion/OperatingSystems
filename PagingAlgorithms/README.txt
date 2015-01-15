NAME:Jose Paterno
CLASS ACCOUNT: masc1418
CLASS INFORMATION: CS570, Summer 2014
ASSIGNMENT INFORMATION: Assignment #2, Page Replace Algorithms
README. 

FILE MANIFEST:
a2.h
a2.cpp
page_replacement_sim.cpp
Makefile
exp.txt
assignment2Design.txt



COMPILE INSTRUCTIONS: 
To compile type the following on the cmd line:
1)make clean
2)make



OPERATING INSTRUCTIONS: 
Run the executable by typing ./page_sim. 
A prompt will ask you for the frame size.
Another prompt will ask you for the number of pages to reference. 
The output will be the number of page faults per algorithm.



DESIGIN DECISIONS: 
Randomize numbers for input in pages.txt

Used a struct to record attributes of each page that each algorithm would use to decide which page to remove from the frame.

Vectors used to store page structs,represent memory,store data parsed from pages.txt
Index of vector of page structs represent the page number. 

Program is modularized for readability. 



DEFICIENCIES: 
Program may be too modularized. 
Each algorithm could have been created as separate classes. 
Algorithms used for simulate page algorithms are inefficient. 
Segmentation fault when frame size is 32 and pages to reference is 3200.
Not enough testing done to find more bugs. 



LESSONS LEARNED: 
Start on the project sooner than later. 

Think of how to design the entire program. Thinking of the end result is sometimes better than programming on the fly. I included the file assignment2Design.txt to show 
my thought process as I was designing the program. 

cout is your friend when you get segmentation faults or the program is not exiting. Print statements helped me debug my code and helped me find out where I have infinite loops and segmentation faults. 

I learned how to use vim on this project. It was tough at first, but it's fun when
you get used to it. 

Thinking about the problem and practicing the page algorithms by hand helped me code each algorithm. Pencil and paper/marker and whiteboard is soooooo useful. 

Programming can be frustrating but rewarding. I had many times where I couldn't figure out why I had the incorrect output or why I kept on getting segmentation faults. I learned to trace the program slowly to find my logical errors. 

People are interesting. 



EXPERIMENTAL PORTION: 

The tests that I ran are on the file exp.txt. 

The two factors that were experimented with were the frame size and the number of frames that were to be referenced. 

There were three experiments held: 

1) Have a constant frame size with increasing number of pages to reference.
2) Have a constant number of pages to reference with an increasing frame size.
3) Have an increasing number of frames and and increasing number of pages to reference.

Results: 

With the first experiment, the number of faults of lru and clock were almost the same. 

With the second experiment, the number of faults of lru are a little less than the number of faults with clock. 

With the last experiement, the number of faults of lru are a little less than the number of faults with clock. 















