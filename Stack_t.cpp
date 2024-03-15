// File name: Stack_t.cpp
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
// post: stack is created & initialized to be empty
template <typename ItemType>
Stack<ItemType>::Stack(): numItems(0), myTop(nullptr){

}

// Copy Constructor
// pre: parameter object, rhs, exists
// post: stack is created to be a copy of the parameter stack
template <typename ItemType>
Stack<ItemType>::Stack(const Stack& rhs): numItems(rhs.numItems), myTop(nullptr){
    if (rhs.myTop != nullptr){
        myTop = new StackNode;
        myTop -> item = rhs.myTop -> item;
        myTop -> next = nullptr;
        StackNodePtr  newPtr = myTop;
        for (StackNodePtr origPtr = rhs.myTop->next; origPtr!= nullptr; origPtr=origPtr->next){
            newPtr->next = new StackNode;
            newPtr = newPtr -> next;
            newPtr -> item = origPtr -> item;
            newPtr -> next = nullptr;
        }
    }
}

// Class Destructor
// pre: the stack exists
// post: the stack is destroyed and any dynamic memory is returned to the system
template <typename ItemType>
Stack<ItemType>::~Stack() {
    while (myTop != nullptr){
        StackNodePtr tmp = myTop;
        myTop = myTop->next;
        delete tmp;
    }
}

// Assignment operator
// Assigns a stack to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
template <typename ItemType>
const Stack<ItemType> &Stack<ItemType>::operator=(const Stack &rhs) {
    if (this != &rhs) {
        Stack tmp(rhs);
        std::swap(numItems, tmp.numItems);
        std::swap(myTop, tmp.myTop);
    }
    return *this;
}


// isEmpty
// Checks if the stack is empty
// pre:  A stack exists.
// post: Returns true if it IS empty, false if NOT empty.
template <typename ItemType>
bool Stack<ItemType>::isEmpty() const{
    return myTop == nullptr;
}

// push
// Pushes an item on top of the stack.
// pre:  Stack exists and item is passed.
// post: the item is placed on top of the stack, and size is incremented.
template <typename ItemType>
void Stack<ItemType>::push(const ItemType& item){
    StackNodePtr add = new StackNode;
    add->item = item;
    add->next = myTop;
    myTop=add;
    numItems++;
}

// pop
// Pops the top item off the stack.
// pre:  Stack exists.
// post: Removes item on top of stack.  If the stack
//       was already empty, throws a std::underflow_error exception.
template <typename ItemType>
void Stack<ItemType>::pop(){
    if(isEmpty()){
        throw std::underflow_error("The stack is empty");
    }else{
        StackNodePtr del = myTop;
        myTop = myTop->next;
        delete del;
        del = nullptr;
        numItems--;
    }
}

// top
// Returns the top item of the stack without popping it.
// pre:  Stack exists.
// post: Returns item on top of stack.  If the stack
//       was already empty, throws a std::underflow_error exception.
template <typename ItemType>
ItemType Stack<ItemType>::top() const{
    if(isEmpty()){
        throw std::underflow_error("The stack is empty");
    }
    return myTop->item;
}

// size
// Returns the number of items on the stack.
// post: Returns size from the private section of class.
template <typename ItemType>
size_t Stack<ItemType>::size() const{
    return numItems;
}