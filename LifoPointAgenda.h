// File name: LifoPointAgenda.h
// Author: Jungwon Jang
// userid: jangj1
// Email: jungwon.jang@vanderbilt.edu
// Class: 2201-3
// Assignment Number: 7
// Honor Statement: I have not given or received unauthorized aid on this assignment.
// Description: creates a concrete class from PointAgenda
// Last Changed: Nov.8


#ifndef LifoPointAgenda_H
#define LifoPointAgenda_H

#include "PointAgenda.h"
#include "Stack_t.h"

class LifoPointAgenda : public PointAgenda{
public:
    // isEmpty (pure virtual)
    // Checks if the agenda is empty
    virtual bool isEmpty() const{
        return pStack.isEmpty();
    }

    // add (pure virtual)
    // adds a Point to the agenda.
    virtual void add(const Point& item){
        pStack.push(item);
    }

    // remove (pure virtual)
    // removes the next Point from the agenda.
    virtual void remove(){
        pStack.pop();
    }

    // peek (pure virtual)
    // Returns the next Point from the agenda without removing it from the agenda.
    virtual Point peek() const{
        return pStack.top();
    }

    // size (pure virtual)
    // Returns the number of Points in the agenda.
    virtual size_t size() const{
        return pStack.size();
    }

private:
    Stack<Point> pStack;
};

#endif