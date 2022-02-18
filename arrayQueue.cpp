template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue(){
    front = -1;
    back = -1;
    count - 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const{
    return count == 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry){
    bool result = false;
    if(count < DEFAULT_CAPACITY){
        if(front == -1){
            front = 0;
        }
        back = (back + 1) % DEFAULT_CAPACITY;
        items[back] = newEntry;
        count++;
        result = true;
    }
    return result;
}

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue(){
    bool result = false;
    if(!isEmpty()){
        front = (front + 1) % DEFAULT_CAPACITY;
        count--;
        result = true;
    }
    return result;
}

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const{
    bool ableToPeek = !isEmpty();
    if(ableToPeek){
        return items[front];
    }
    throw ("Empty Queue"); //throw
}

template<class ItemType>
ArrayQueue<ItemType>::~ArrayQueue(){ }
