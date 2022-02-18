#include "event.h"

Event::Event()
{
   arrivalTime = 0;
   transactionTime = 0;
   eventType = ' ';
}

Event::Event(const Event &obj)
{
   arrivalTime = obj.getArrivalTime();
   transactionTime = obj.getTransactionTime();
   eventType = obj.getEventType();
}

Event::Event(int arrTime, int transTime)
{
   arrivalTime = arrTime;
   transactionTime = transTime;
   eventType = 'A';
}

Event::Event(int arrTime, int transTime, char type)
{
   arrivalTime = arrTime;
   transactionTime = transTime;
   eventType = type;
}

int Event::getArrivalTime() const
{
   return arrivalTime;
}

int Event::getTransactionTime() const
{
   return transactionTime;
}

char Event::getEventType() const
{
   return eventType;
}
