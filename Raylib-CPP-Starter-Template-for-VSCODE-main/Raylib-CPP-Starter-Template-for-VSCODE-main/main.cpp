#include <iostream>
#include <raylib.h>
#include "obstacle.h"

using namespace std;
class food{
    public:
       void spawnrandom()
       {
        foodx=GetRandomValue(1,2);
        foody= GetRandomValue(2,3);
       }
    
    protected:
    private: 
        float foodx;
        float foody;

};
int cellsize=20;
int cellcount=40;

int main () {

   
    int xcircle=400;
    int ycircle=400;
    int v_y=5;


    cout << "Hello World" << endl;

    InitWindow(cellsize*cellcount,cellsize*cellcount, "My first RAYLIB program!");
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        ycircle-=v_y;
        BeginDrawing();
        ClearBackground(BLACK);
        Rectangle borderfake={100,100,600,600};
        
        DrawRectangleLinesEx(borderfake,20,WHITE); 
        //drawing the border
        DrawCircle(xcircle,ycircle,5.25,RED);
        EndDrawing();

    }


   
       
    

    CloseWindow();
}