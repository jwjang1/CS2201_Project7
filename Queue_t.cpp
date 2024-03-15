// File name: Queue_t.cpp
// Author: Jungwon Jang
// userid: jangj1
// Email: jungwon.jang@vanderbilt.edu
// Class: 2201-3
// Assignment Number: 7
// Honor Statement: I have not given or received unauthorized aid on this assignment.
// Description: provides support for a template stack abstraction that holds data of any specified type
// Last Changed: Nov.8

#include <cstddef>
#include <stdexcept>

// Class Constructor
template <typename ItemType>
Queue<ItemType>::Queue() : numItems(0), myFront(nullptr), myBack(nullptr), prev(nullptr) {

}

// Copy Constructor
// pre:  Class object, aQueue, exists
// post: Object is initialized to be a copy of the parameter
template <typename ItemType>
Queue<ItemType>::Queue(const Queue &aQueue) : numItems(aQueue.numItems), myFront(nullptr), myBack(nullptr),
                                             prev(nullptr) {
    if (aQueue.myFront != nullptr) {
        myFront = new qNode;
        myFront->item = aQueue.myFront->item;
        myFront->next = nullptr;
        qNodePtr newPtr = myFront;
        for (qNodePtr origPtr = aQueue.myFront->next; origPtr != nullptr; origPtr = origPtr->next) {
            newPtr->next = new qNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
            newPtr->next = nullptr;
            prev = newPtr;
        }
        newPtr->next = myBack;
        myBack = nullptr;
    }
}

// Class Destructor
// Destroys a queue
// pre:  Class object exists
// post: Class object does not exist
template <typename ItemType>
Queue<ItemType>::~Queue() {
    while (myFront != nullptr) {
        qNodePtr tmp = myFront;
        myFront = myFront->next;
        delete tmp;
    }
}

// Assignment operator
// Assigns a stack to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
template <typename ItemType>
const Queue<ItemType> &Queue<ItemType>::operator=(const Queue &rhs) {
    if (this != &rhs) {
        Queue tmp(rhs);
        std::swap(numItems, tmp.numItems);
        std::swap(myFront, tmp.myFront);
    }
    return *this;
}

// isEmpty
// Checks if the stack is empty
// pre:  A stack exists.
// post: Returns true if it IS empty, false if NOT empty.
template <typename ItemType>
bool Queue<ItemType>::isEmpty() const {
    return myFront == nullptr;
}

// enqueue
// enqueues an item to back of the queue.
// pre:  DblQueue exists and item is passed.
// post: adds the given item to the end of the queue.
template <typename ItemType>
void Queue<ItemType>::enqueue(const ItemType &item) {
    if (isEmpty()) {
        qNodePtr add = new qNode;
        add->item = item;
        myFront = add;
        prev = add;
        add->next = myBack;
        myBack = nullptr;
    } else {
        qNodePtr add = new qNode;
        add->item = item;
        add->next = myBack;
        prev->next = add;
        prev = add;
        myBack = nullptr;
    }
    numItems++;
}

// dequeue
// dequeues the front item off the queue
// pre:  DblQueue exists.
// post: Removes item on front of the queue. If the queue
//       was already empty, throws an std::underflow_error exception.
template <typename ItemType>
void Queue<ItemType>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("The queue is empty");
    } else {
        qNodePtr del = myFront;
        myFront = myFront->next;
        delete del;
        del = nullptr;
        numItems--;
    }
}

// front
// Returns the front item of the queue without dequeueing it.
// pre:  DblQueue exists.
// post: Returns item at front of queue.  If the queue is empty,
//       throws an std::underflow_error exception.
template <typename ItemType>
ItemType Queue<ItemType>::front() const {
    if (isEmpty()) {
        throw std::underflow_error("The queue is empty");
    } else {
        return myFront->item;
    }
}

// size
// Returns the number of items on the queue.
template <typename ItemType>
size_t Queue<ItemType>::size() const {
    return numItems;
}