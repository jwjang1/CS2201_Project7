// File name: MazeSolver.h
// Author: Jungwon Jang
// userid: jangj1
// Email: jungwon.jang@vanderbilt.edu
// Class: 2201-3
// Assignment Number: 7
// Honor Statement: I have not given or received unauthorized aid on this assignment.
// Description: provides the necessary support to explore a maze
// from a given start position until the ending position is found
// Last Changed: Nov.8


#ifndef MAZESOLVER_H
#define MAZESOLVER_H
#include "PointAgenda.h"
#include "Maze.h"

class MazeSolver
{
private:
    Maze* myMaze;
    PointAgenda* myAgenda;

public:

    // Class Constructor
    MazeSolver(Maze& newMaze,PointAgenda& newAgenda);

    bool solve(bool trace);

};

#endif /* ifndef */