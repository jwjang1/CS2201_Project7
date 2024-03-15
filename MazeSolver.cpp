// File name: MazeSolver.cpp
// Author: Jungwon Jang
// userid: jangj1
// Email: jungwon.jang@vanderbilt.edu
// Class: 2201-3
// Assignment Number: 7
// Honor Statement: I have not given or received unauthorized aid on this assignment.
// Description: defines MazeSolver.h
// Last Changed: Nov.8

#include "MazeSolver.h"

MazeSolver::MazeSolver(Maze &newMaze, PointAgenda &newAgenda) {
    myMaze = &newMaze;
    myAgenda = &newAgenda;
}

bool MazeSolver::solve(bool trace) {
    Point start = myMaze->getStartLocation();
    Point end = myMaze->getEndLocation();
    int sum = 0;

    myAgenda->add(start);
    Point cur = myAgenda->peek();

    while(!myAgenda->isEmpty()) {
        int rows = myMaze->getNumRows();
        int cols = myMaze->getNumCols();

        if(cur.x > 0){
            if(!myMaze->isWall(cur.x-1,cur.y)){
                Point left = Point(cur.x-1,cur.y);
                myAgenda->add(left);
                myMaze->markVisited(left);
            }
        }
        if(cur.x < rows){
            if(!myMaze->isWall(cur.x+1,cur.y)){
                Point right = Point(cur.x+1,cur.y);
                myAgenda->add(right);
                myMaze->markVisited(right);
            }
        }
        if(cur.y < cols){
            if(!myMaze->isWall(cur.x,cur.y+1)){
                Point above = Point(cur.x,cur.y+1);
                myAgenda->add(above);
                myMaze->markVisited(above);
            }
        }
        if(cur.y > 0){
            if(!myMaze->isWall(cur.x,cur.y-1)){
                Point below = Point(cur.x,cur.y);
                myAgenda->add(below);
                myMaze->markVisited(below);
            }
        }

        myAgenda->remove();
        cur = myAgenda->peek();
        sum += 1;
        std::cout << "(" << cur.x << "," << cur.y << ")->";

        if(cur == end){
            std::cout << "Solution found!\nNumber of nodes visited: " << sum;
        }else{
            std::cout << "Solution not found!\nNumber of nodes visited: " << sum;
        }

        return cur == end;
    }
    if (trace) {} //dummy use of trace to make compiler happy
    return false;
}