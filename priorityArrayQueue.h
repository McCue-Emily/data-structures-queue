#ifndef PRIORITY_ARRAY_QUEUE
#define PRIORITY_ARRAY_QUEUE

#include "priorityqueue.h"

template<class ItemType>
class PriorityQueue : public PQueueInterface<ItemType>{
private:
    static const int DEFAULT_CAPACITY = 60;
    ItemType items[DEFAULT_CAPACITY];
    int priority[DEFAULT_CAPACITY];
    int front;
    int back;
    int count;
public:
    PriorityQueue();
    bool isEmpty() const;
    bool enqueue(const ItemType &newEntry, int newPriority);
    bool dequeue();
    ItemType peekFront() const;
    int peekFrontPriority() const;
    virtual ~PriorityQueue();
};
#include "priorityArrayQueue.cpp"
#endif
