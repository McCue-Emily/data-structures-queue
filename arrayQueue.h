#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

#include "queue.h"

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType>{
private:
    static const int DEFAULT_CAPACITY = 60;
    ItemType items[DEFAULT_CAPACITY];
    int front;
    int back;
    int count;
public:
    ArrayQueue();
    bool isEmpty() const;
    bool enqueue(const ItemType &newEntry);
    bool dequeue();
    ItemType peekFront() const;
    virtual ~ArrayQueue();
};
#include "arrayQueue.cpp"
#endif
