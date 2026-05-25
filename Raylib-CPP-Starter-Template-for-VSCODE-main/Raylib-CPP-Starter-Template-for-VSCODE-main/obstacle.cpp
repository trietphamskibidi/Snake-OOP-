#include "obstacle.h"
#include<iostream>
#include<cmath>
using namespace std;
obstacle::obstacle()
{
}
void obstacle::kill(int xcircle, int ycircle)
{
if (pow(pow((x-xcircle),2)+pow((y-ycircle),2),1/2)<5.25)
{
CloseWindow();
}
}
obstacle::~obstacle()
{

}