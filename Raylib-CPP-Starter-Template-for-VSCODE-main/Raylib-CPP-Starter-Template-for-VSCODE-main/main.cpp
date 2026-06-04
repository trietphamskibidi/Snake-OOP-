#include <iostream>
#include <raylib.h>
#include "obstacle.h"
#include "raymath.h"
#include<deque>
using namespace std;
int cellsize=20;
int cellcount=40;
float countingtime=0;
Vector2 direction={0,-1};
Vector2 pendingDirection={0,-1};

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
  float vy=1;
  deque<Vector2> snake={Vector2{20,21},Vector2{20,22},Vector2{20,23}};
  void Draw()
  { 
    DrawRectangle(snake[0].x*cellsize,snake[0].y*cellsize,cellsize,cellsize, ORANGE);
    for (int i=1; i<snake.size();i++)
    {
        int x=snake[i].x;
        int y=snake[i].y;
        DrawRectangle(x*cellsize,y*cellsize,cellsize,cellsize,ORANGE);
    }
  };
  void move()
  { 
    snake.pop_back();
    snake.push_front(Vector2Add(snake[0],direction));
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

        if (IsKeyPressed(KEY_W) && direction.y != 1  && pendingDirection.y != 1)  pendingDirection = {0,-1};
        if (IsKeyPressed(KEY_A) && direction.x != 1  && pendingDirection.x != 1)  pendingDirection = {-1,0};
        if (IsKeyPressed(KEY_S) && direction.y != -1 && pendingDirection.y != -1) pendingDirection = {0, 1};
        if (IsKeyPressed(KEY_D) && direction.x != -1 && pendingDirection.x != -1) pendingDirection = {1, 0};

        if (GetTime()-countingtime>=0.25)
        {
            countingtime=GetTime();
            direction=pendingDirection;
            body.move();
        }
        
        body.Draw();
        Rectangle borderfake={100,100,620,620};
        DrawRectangleLinesEx(borderfake,20,WHITE); 
        Food.Draw();
        EndDrawing();
    }
}
