// File name: FifoPointAgenda.h
// Author: Jungwon Jang
// userid: jangj1
// Email: jungwon.jang@vanderbilt.edu
// Class: 2201-3
// Assignment Number: 7
// Honor Statement: I have not given or received unauthorized aid on this assignment.
// Description: creates a concrete class from PointAgenda
// Last Changed: Nov.8


#ifndef FifoPointAgenda_H
#define FifoPointAgenda_H

#include "PointAgenda.h"
#include "Queue_t.h"

class FifoPointAgenda : public PointAgenda{
public:
    // isEmpty (pure virtual)
    // Checks if the agenda is empty
    virtual bool isEmpty() const{
        return pQueue.isEmpty();
    }

    // add (pure virtual)
    // adds a Point to the agenda.
    virtual void add(const Point& item){
        pQueue.enqueue(item);
    }

    // remove (pure virtual)
    // removes the next Point from the agenda.
    virtual void remove(){
        pQueue.dequeue();
    }

    // peek (pure virtual)
    // Returns the next Point from the agenda without removing it from the agenda.
    virtual Point peek() const{
        return pQueue.front();
    }

    // size (pure virtual)
    // Returns the number of Points in the agenda.
    virtual size_t size() const{
        return pQueue.size();
    }

private:
    Queue<Point> pQueue;
};

#endif