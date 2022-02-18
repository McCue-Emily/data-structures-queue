/*
Team Members: Tanner Ashby, Emily Mccue, Bryce Millis
CS 302
10/10/21
Homework 3 - Queue, Priority Queue, Bank Simulation
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "arrayQueue.h"
#include "event.h"
#include "priorityArrayQueue.h"

void loadData(PriorityQueue<Event>*);
bool processArrival(bool, PriorityQueue<Event>*,  ArrayQueue<Event>*);
bool processDeparture(bool, PriorityQueue<Event>*, ArrayQueue<Event>*, int*);

int main(){
    PriorityQueue<Event>* eventPQ;
    PriorityQueue<Event>* eventPQptr = eventPQ;
    ArrayQueue<Event>* lineQ;
    ArrayQueue<Event>* lineQptr = lineQ;
    bool tellerAvailable = true;
    int waitTimeSum = 0;
    int numCustomers = 0;

    int loopCount = 0; //temp
    bool isEventArrival = true;
    bool firstLoop = true;
    int prevDeparture = 0;
    int* prevDep = &prevDeparture;

    do{
        if(firstLoop){
            loadData(eventPQptr);
            tellerAvailable = processArrival(tellerAvailable, eventPQptr, lineQptr);
            numCustomers = 1;
            firstLoop = false;
        }
        else{
            Event pq(eventPQptr->peekFront());
            Event lineEvent(lineQptr->peekFront());
            if(lineQptr->isEmpty()){
                if(pq.getEventType() == 'A'){
                    isEventArrival = true;
                }
                else{
                    isEventArrival = false;
                }
            }
            else{
                if(pq.getEventType() == 'A'){
                    isEventArrival = true;
                }
                else if(lineEvent.getArrivalTime() > eventPQptr->peekFrontPriority()){
                    isEventArrival = true;
                }
                else{
                    isEventArrival = false;
                }
            }
            if(isEventArrival){
                tellerAvailable = processArrival(tellerAvailable, eventPQptr, lineQptr);
                numCustomers++;
            }
            else{
                tellerAvailable = processDeparture(tellerAvailable, eventPQptr, lineQptr, prevDep);
            }       
        }
        loopCount++; //temp
    }while(!(eventPQptr->isEmpty()) && loopCount < 40); //2nd condition is temp

    cout << "Simulation Ends\n" << endl;
    cout << "Final Statistics" << endl;
    cout << "Total number of people processed: " << numCustomers << endl;
    cout << "Average amount of time spent waiting: " << waitTimeSum << endl;
    return 0;
}

void loadData(PriorityQueue<Event>* eventPQptr){
    ifstream inFile("bank-line.txt");
    int arrivalTime;
    int transactionLength;
    while(inFile >> arrivalTime >> transactionLength){
        Event addArrival(arrivalTime, transactionLength);
        eventPQptr->enqueue(addArrival, arrivalTime);
    }
}

bool processArrival(bool tellerAvailable, PriorityQueue<Event>* eventPQptr, ArrayQueue<Event>* lineQptr){
    Event pqEvent(eventPQptr->peekFront());
    if(tellerAvailable){
        int depTime = (pqEvent.getArrivalTime()+pqEvent.getTransactionTime());
        Event departure(pqEvent.getArrivalTime(), pqEvent.getTransactionTime(), 'D');
        eventPQptr->dequeue();
        eventPQptr->enqueue(departure, depTime);
        cout << "Processing an arrival event at time: " << pqEvent.getArrivalTime() << endl;
        tellerAvailable = false;
    }
    else{
        lineQptr->enqueue(pqEvent);
        eventPQptr->dequeue();
        cout << "Processing an arrival event at time: " << pqEvent.getArrivalTime() << endl;
        tellerAvailable = false;
    }
    return tellerAvailable;
}
bool processDeparture(bool tellerAvailable, PriorityQueue<Event>* eventPQptr, ArrayQueue<Event>* lineQptr, int* prevDep){
    bool nextFromLine;

    bool isLine = (!lineQptr->isEmpty());
    if(isLine){
        Event tempLine(lineQptr->peekFront());
        Event tempPQ(eventPQptr->peekFront());
        Event lineCustomer(tempLine.getArrivalTime(), tempLine.getTransactionTime(), 'D');
        nextFromLine = (lineCustomer.getArrivalTime() < tempPQ.getArrivalTime());
        if(nextFromLine){
            int depTime = (*prevDep + lineCustomer.getTransactionTime());
            eventPQptr->enqueue(lineCustomer, depTime);
            lineQptr->dequeue();
        }
    }
    else{
        Event depEvent(eventPQptr->peekFront());
        int transTime = depEvent.getTransactionTime();
        int addTime;
        if(depEvent.getArrivalTime() > *prevDep){
            addTime = depEvent.getArrivalTime();
        }
        else{
            addTime = *prevDep;
        }
        cout << "Processing a departure event at time: " << (transTime + addTime) << endl;
        *prevDep = (transTime + addTime);
        eventPQptr->dequeue();
        return true;
    }
    return false;
}
