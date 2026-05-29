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
  float vy=0.125;
  deque<Vector2> snake={Vector2{20,21},Vector2{20,22},Vector2{20,23}};
  void Draw()
  { DrawCircle(snake[0].x*cellsize,snake[0].y*cellsize,10,RED);
    for (int i=1; i<snake.size();i++)
    {
    int x=snake[i].x;
    int y=snake[i].y;
    DrawRectangle(x*cellsize,y*cellsize,cellsize,cellsize,ORANGE);
    }
  };
  void moving()
  {
    for (int i=0;i<snake.size();i++)
    {
        snake[i].y-=vy;
    }
  }
};

int main () {
    
    snake body;
    food Food;

    cout << "Hello World" << endl;

    InitWindow(cellsize*cellcount,cellsize*cellcount, "My first RAYLIB program!");
    SetTargetFPS(60);
    Food.foodpos.x=GetRandomValue(6,35);
    Food.foodpos.y=GetRandomValue(6,35);

    while (WindowShouldClose() == false)
    {  
        
        
       
        BeginDrawing();
        ClearBackground(BLACK);
        body.moving();
        body.Draw();
        Rectangle borderfake={100,100,620,620};
        DrawRectangleLinesEx(borderfake,20,WHITE); 
        Food.Draw();
        EndDrawing();

    }
    CloseWindow();
}
