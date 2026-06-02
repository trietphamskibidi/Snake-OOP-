#include <iostream>
#include <raylib.h>
#include "obstacle.h"
#include<deque>
using namespace std;
int cellsize=20;
int cellcount=40;
float countingtime=0;
int movementtracking=0;
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
  { DrawRectangle(snake[0].x*cellsize,snake[0].y*cellsize,cellsize,cellsize, ORANGE);
    for (int i=1; i<snake.size();i++)
    {
    int x=snake[i].x;
    int y=snake[i].y;
    DrawRectangle(x*cellsize,y*cellsize,cellsize,cellsize,ORANGE);
    }
  };
  void movingup()
  {
    snake.pop_back();
    snake.push_front({snake[0].x,(snake[0].y)-1});
    movementtracking=0;
  };
  void movingdown()
  {
    snake.pop_back();
    snake.push_front({snake[0].x,(snake[0].y)+1});
    movementtracking=1;
  }
  void movingleft()
  {
    snake.pop_back();
    snake.push_front({(snake[0].x)-1,snake[0].y});
    movementtracking=2;
  }
  void movingright()
  {
   snake.pop_back();
    snake.push_front({(snake[0].x)+1,snake[0].y});
    movementtracking=3;
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

        if (IsKeyPressed(KEY_W) and movementtracking !=1)
        {
            body.movingup();
        }
        if(IsKeyPressed(KEY_A) and movementtracking!=3)
        {
            body.movingleft();
        }
        if(IsKeyPressed(KEY_S) and movementtracking!=0)
        {
            body.movingdown();
        }
        if(IsKeyPressed(KEY_D) and movementtracking!=2)
        {
            body.movingright();
        }
    body.Draw();
        Rectangle borderfake={100,100,620,620};
        DrawRectangleLinesEx(borderfake,20,WHITE); 
        Food.Draw();
        EndDrawing();
    }
}
