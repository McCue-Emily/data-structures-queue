template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue(){
    front = -1;
    back = -1;
    count = 0;
}

template<class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const{
    return count == 0;
}

template<class ItemType>
bool PriorityQueue<ItemType>::enqueue(const ItemType& newEntry, int newPriority){
    bool result = false;
    int i;
    if(count < DEFAULT_CAPACITY){
        if (front == -1){
            front = back = 0;
            items[back] = newEntry;
            priority[back] = newPriority;
            count = 1;
        }
        else{
            for(i=back; i>=front; i--){
                if(newPriority < priority[i]){
                    items[i+1] = items[i];
                    priority[i+1] = priority[i];
                }
                else{
                    break;
                }
            }
            items[i+1] = newEntry;
            priority[i+1] = newPriority;
            back++;
            count++;
        }
        result = true;
    }
    return result;
}

template<class ItemType>
bool PriorityQueue<ItemType>::dequeue(){
    bool result = false;
    if(count > 0){
        if (front == back){
            front = back = -1;
            count = 0;
        }
        else{
            front++;
            count--;
            result = true;
        }
    }
    return result;
}


template<class ItemType>
ItemType PriorityQueue<ItemType>::peekFront() const{
    if(count > 0){
        return items[front];
    }
    throw "Empty Queue";
}

template<class ItemType>
int PriorityQueue<ItemType>::peekFrontPriority() const{
    if(count > 0){
        return priority[front];
    }
    throw "Empty Queue";
}

template<class ItemType>
PriorityQueue<ItemType>::~PriorityQueue(){ }
