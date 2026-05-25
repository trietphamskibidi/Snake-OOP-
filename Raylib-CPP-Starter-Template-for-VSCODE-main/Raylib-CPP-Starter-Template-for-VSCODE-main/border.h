#ifndef BORDER_H
#define BORDER_H
#include<iostream>
#include<raylib.h>
#include"obstacle.h"
#pragma once

class border: public obstacle
{
public:
    border();
    ~border();
    void kill();

private:
int borderx1;
int borderx2;
int bordery1;
int bordery2;

};

#endif