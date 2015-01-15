###########################################################  Makefile
# CS570, Summer 2014, a2
# Jose Paterno, masc1418
###########################################################
EXEC = page_sim
CC = g++       ###  or use cc / g++ / gcc   ###

$(EXEC):
	$(CC) -o $(EXEC) page_replacement_sim.cpp 
	rm -f *.o

clean:
	rm -f *.o core a.out $(EXEC) pages.txt

#######################[ EOF: Makefile ]###################
