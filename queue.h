// queue interface

#ifndef QUEUE_INTERFACE_
#define QUEUE_INTERFACE _
template<class ItemType>
class QueueInterface {
public:
    virtual bool isEmpty() const = 0;
    virtual bool enqueue(const ItemType& anEntry) = 0;
    virtual bool dequeue() = 0;
    virtual ItemType dequeue() const = 0;
    
    virtual ~QueueInterface() { }
}; // end QueueInterface
#endif
