banksim: driver.o event.o
	g++ driver.o event.o -o banksim

driver.o: driver.cpp event.h arrayQueue.h priorityArrayQueue.h
	g++ -c driver.cpp

event.o: event.cpp event.h
	g++ -c event.cpp

clean:
	del event.o driver.o
