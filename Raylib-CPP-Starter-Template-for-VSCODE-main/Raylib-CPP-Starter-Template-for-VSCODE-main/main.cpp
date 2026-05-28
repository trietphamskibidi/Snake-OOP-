#include <iostream>
#include <raylib.h>
#include "obstacle.h"
#include<deque>
using namespace std;
int cellsize=20;
int cellcount=40;
class food
{
public:
    Vector2 foodpos;
    void Draw()
    {
        DrawRectangle((foodpos.x)*cellsize,(foodpos.y)*cellsize,cellsize,cellsize,WHITE);
    }
};
class snake
{
public:
  deque<Vector2> body;
};
class head
{public:
    Vector2 headpos;
    void Draw()
    {
     DrawCircle((headpos.x)*cellsize,(headpos.y)*cellsize,10,RED);
    }

};

int main () {

    food Food;
    head Head;
    Head.headpos.x=20;
    Head.headpos.y=20;
    float v_y=0.125;
    

    cout << "Hello World" << endl;

    InitWindow(cellsize*cellcount,cellsize*cellcount, "My first RAYLIB program!");
    SetTargetFPS(60);
    Food.foodpos.x=GetRandomValue(6,35);
    Food.foodpos.y=GetRandomValue(6,35);

    while (WindowShouldClose() == false)
    {  

        Head.headpos.y-=v_y;
        BeginDrawing();
        ClearBackground(BLACK);
        Rectangle borderfake={100,100,620,620};
        DrawRectangleLinesEx(borderfake,20,WHITE); 
        Head.Draw();
        Food.Draw();
        EndDrawing();

    }


   
       
    

    CloseWindow();
}
