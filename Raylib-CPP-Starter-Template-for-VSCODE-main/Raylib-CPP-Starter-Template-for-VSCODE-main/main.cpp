#include <iostream>
#include <raylib.h>
#include "obstacle.h"
#include "raymath.h"
#include<deque>
using namespace std;
class snake;
class food;
class gamestage;
int cellsize=20;
int cellcount=40;
float countingtime=0;
Vector2 direction={0,-1};
Vector2 pendingDirection={0,-1};
enum differentstages
{
 gameinitialize,
 gamerunning,
 gamepausing,
 gameover,
 gamerestart,
};
differentstages stage=gameinitialize;
class food
{
public:
    Vector2 foodpos;
    food()
    {
        foodpos.x=GetRandomValue(6,35);
        foodpos.y=GetRandomValue(6,35);
    }
    void Draw()
    {
        DrawRectangle((foodpos.x)*cellsize,(foodpos.y)*cellsize,cellsize,cellsize,WHITE);
    }
    void geteaten()
    {
        foodpos.x=GetRandomValue(6,34);
        foodpos.y=GetRandomValue(6,34);
    }
};
class snake
{
public:
  float vy=1;
  deque<Vector2> bodysegment={Vector2{20,21},Vector2{20,22},Vector2{20,23}};
  void Draw()
  { 
    DrawRectangle(bodysegment[0].x*cellsize,bodysegment[0].y*cellsize,cellsize,cellsize, ORANGE);
    for (int i=1; i<bodysegment.size();i++)
    {
        int x=bodysegment[i].x;
        int y=bodysegment[i].y;
        DrawRectangle(x*cellsize,y*cellsize,cellsize,cellsize,ORANGE);
    }
  };

  void move()
  { 
    bodysegment.pop_back();
    bodysegment.push_front(Vector2Add(bodysegment[0],direction));
  }
  void grow()
{
    bodysegment.push_back(Vector2Subtract(bodysegment.back(),direction));
}
  void check()
{
    for (int i=1;i<bodysegment.size(); i++)
     {
       if (bodysegment[0].x==bodysegment[i].x and bodysegment[0].y==bodysegment[i].y)
        {
            stage=gameover;
        }
     }
     if(bodysegment[0].x>34 || bodysegment[0].x<6||bodysegment[0].y<6||bodysegment[0].y>34)
     {
       stage=gameover;
     }
}
  

  
};
class gamestage
{
    public:
     Rectangle label={150,150, 520, 170};
     void gameinitialize(snake &body)
     {
      DrawRectangleLinesEx(label, 20, PINK);
      DrawText("Snake Game Project", 190,190, 35, WHITE);
      DrawText("Press R to start playing", 300, 450, 25, ORANGE);
     body.bodysegment={Vector2{20,21},Vector2{20,22},Vector2{20,23}};
     pendingDirection={0,-1};
     }
     
     void gamerunning(Vector2 &direction, Vector2&pendingDirection, snake &body, food &Food)
     {  ClearBackground(BLACK);
        if (IsKeyPressed(KEY_W) && direction.y != 1  && pendingDirection.y != 1)  pendingDirection = {0,-1};
        if (IsKeyPressed(KEY_A) && direction.x != 1  && pendingDirection.x != 1)  pendingDirection = {-1,0};
        if (IsKeyPressed(KEY_S) && direction.y != -1 && pendingDirection.y != -1) pendingDirection = {0, 1};
        if (IsKeyPressed(KEY_D) && direction.x != -1 && pendingDirection.x != -1) pendingDirection = {1, 0};
        if (GetTime()-countingtime>=0.1)
        {
            countingtime=GetTime();
            direction=pendingDirection;
            body.move();
            if (body.bodysegment[0].x == Food.foodpos.x && body.bodysegment[0].y == Food.foodpos.y)
            {
                body.grow();
                Food.geteaten();
            }
        }
        body.check();
        body.Draw();
        Food.Draw();
     }
     void gameover()
     {
        DrawText("Press space to start again", 300, 450, 25, ORANGE);
     }
     void gamepause()
     {
        DrawText("click anywhere to start again", 300, 450,25, ORANGE);
     }
    };
int main () {
    snake body;
    food Food;
    gamestage Stage;
    InitWindow(cellsize*cellcount,cellsize*cellcount, "My first RAYLIB program!");
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BLACK);
        Rectangle borderfake={100,100,620,620};
        DrawRectangleLinesEx(borderfake,20,WHITE);
        if (stage==gameinitialize)
        {
           Stage.gameinitialize(body);

           if(IsKeyPressed(KEY_R))
           {
            stage=gamerunning;
           }
        }
        if(stage==gamerunning)
        {
            Stage.gamerunning(direction,pendingDirection,body,Food);
            if(IsKeyPressed(KEY_M))
            {
                stage=gamepausing;
            }
            
        }
        if(stage==gamepausing)
        {
            Stage.gamepause();
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                stage=gamerunning;
            }
        }
        if(stage==gameover)
        {
            Stage.gameover();
            if(IsKeyPressed(KEY_SPACE))
            {
                stage=gameinitialize;
            }
        }

        

        EndDrawing();
    }
}
