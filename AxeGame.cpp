#include "raylib.h"

static int windowWidth = 350;
static int windowHeight = 350;

static int speed = 1;

int main()
{
    InitWindow(windowWidth, windowHeight, "window");

    Vector2 currPos = Vector2 {windowWidth / 2, windowHeight / 2};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RED);

        DrawCircle(currPos.x, currPos.y, 10.0f, BLUE);

        if(IsKeyDown(KEY_R))
        {
            currPos = Vector2 {windowWidth / 2, windowHeight / 2};
        }

        if(IsKeyDown(KEY_W) && currPos.y > 0)
        {
            currPos.y -= speed;
        }
        if(IsKeyDown(KEY_S) && currPos.y < windowHeight)
        {
            currPos.y += speed;
        }
        if(IsKeyDown(KEY_D) && currPos.x < windowWidth)
        {
            currPos.x += speed;
        }
        if(IsKeyDown(KEY_A) && currPos.x > 0)
        {
            currPos.x -= speed;
        }

        EndDrawing();
    }
}