# Homework 3

## Project Goals
The goal of this project is to:
1.	Familiarize students with **queues**
2.  Familiarize students with the **using Data Structures**.

## Program
Implement the event-driven simulation of a bank mentioned in the textbook (Question 6). A queue of arrival events will represent the line of customers in the bank. Maintain the arrival events and departure events in a priority queue, sorted by the time of the event. 

The input is a text file of arrival and transaction times. Each line of the file contains the arrival time and required transaction time for a customer. The arrival times are ordered by increasing time.

Your program must count customers and keep track of their cumulative waiting time. These statistics are sufficient to compute the average waiting time after the last event has been processed. Display a trace of the events executed and a summary of the computed statistics (the total number of arrivals and average time spent waiting in line). For example, the input file shown in below should produce the output shown at the bottom of the assignment.

You may do Question 7 for Extra Credit.  

**Use circular array based implementations for the Data Structures.**

Input File:  
1	5  
2	5  
4	5  
20	5  
22	5  
24	5  
26	5  
28	5  
30	5  
88	3  

Output:  
Simulation Begins	 
Processing an arrival event at time:	1  
Processing an arrival event at time:	2  
Processing an arrival event at time:	4  
Processing a departure event at time:	6  
Processing a departure event at time:	11  
Processing a departure event at time:	16  
Processing an arrival event at time:	20  
Processing an arrival event at time:	22  
Processing an arrival event at time:	24  
Processing a departure event at time:	25  
Processing an arrival event at time:	26  
Processing an arrival event at time:	28  
Processing an arrival event at time:	30  
Processing a departure event at time:	30  
Processing a departure event at time:	35  
Processing a departure event at time:	40  
Processing a departure event at time:	45  
Processing a departure event at time:	50  
Processing an arrival event at time:	88  
Processing a departure event at time:	91  
Simulation Ends	  
	
Final Statistics:	  
	Total number of people processed: 10  
	Average amount of time spent waiting: 5.6	 
