#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

template<class ItemType>
class PQueueInterface {
public:
    virtual bool isEmpty() const = 0;
    virtual bool enqueue(const ItemType& newEntry, int newPosition) = 0;
    virtual bool dequeue() = 0;
    virtual ItemType peekFront() const = 0;
    virtual int peekFrontPriority() const = 0;
    virtual ~PQueueInterface() { }
};
#endif
