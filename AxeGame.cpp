#include "raylib.h"

static int windowWidth = 350;
static int windowHeight = 350;

static int speed = 1;

static int direction{10};

int main()
{
    InitWindow(windowWidth, windowHeight, "window");

    Vector2 circleCurrPos = Vector2 {(windowWidth / 2) - 50, (windowHeight / 2 ) - 50};
    Vector2 axeCurrPos = Vector2 {windowWidth / 2, windowHeight / 2};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawCircle(circleCurrPos.x, circleCurrPos.y, 10.0f, BLUE);
        DrawRectangle(axeCurrPos.x, axeCurrPos.y, 50, 20, RED);

        if(axeCurrPos.y > windowHeight || axeCurrPos.y < 0)
            direction = -direction;

        axeCurrPos.y += direction;

        if(IsKeyDown(KEY_R))
        {
            circleCurrPos = Vector2 {windowWidth / 2, windowHeight / 2};
        }

        if(IsKeyDown(KEY_W) && circleCurrPos.y > 0)
        {
            circleCurrPos.y -= speed;
        }
        if(IsKeyDown(KEY_S) && circleCurrPos.y < windowHeight)
        {
            circleCurrPos.y += speed;
        }
        if(IsKeyDown(KEY_D) && circleCurrPos.x < windowWidth)
        {
            circleCurrPos.x += speed;
        }
        if(IsKeyDown(KEY_A) && circleCurrPos.x > 0)
        {
            circleCurrPos.x -= speed;
        }

        EndDrawing();
    }
}