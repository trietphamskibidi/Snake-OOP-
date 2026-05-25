#ifndef OBSTACLE_H
#define OBSTACLE_H
#include<iostream>
#include<raylib.h>

#pragma once

class obstacle
{
public:
    obstacle();
    ~obstacle();
    void kill(int xcircle, int ycircle);

protected:
    
    int x;
    int y;
private:

};

#endif