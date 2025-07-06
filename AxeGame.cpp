#include "raylib.h"
int main()
{
    int width{700};
    int height{500};
    InitWindow( width, height, "Collision Game");

    int Circle_x{350};
    int Circle_y{250};
    int Circle_Radius{25};
    int l_circle_x = Circle_x - Circle_Radius;
    int r_circle_x = Circle_x + Circle_Radius;
    int u_circle_y = Circle_y - Circle_Radius;
    int b_circle_y = Circle_y + Circle_Radius;

    int axe_x{200};
    int axe_y{0};
    int axe_length{50};
    int l_axe_x = axe_x;
    int r_axe_x = axe_x + axe_length;
    int u_axe_y = axe_y;
    int b_axe_y = axe_y + axe_length;

    int axe_x2{400};
    int axe_y2{0};
    int l_axe_x2 = axe_x2;
    int r_axe_x2 = axe_x2 + axe_length;
    int u_axe_y2 = axe_y2;
    int b_axe_y2 = axe_y2 + axe_length;

    bool Collision_with_axe =
                               b_axe_y >= u_circle_y&&
                              u_axe_y <= b_circle_y&&
                              l_circle_x <= r_axe_x&&
                              r_circle_x >= l_axe_x;

     bool Collision_with_axe2 = 
                              b_axe_y2 >= u_circle_y&&
                              u_axe_y2 <= b_circle_y&&
                              l_circle_x <= r_axe_x2&&
                              r_circle_x >= l_axe_x2;  
    int direction{10};
    int direction2{10};
    SetTargetFPS(30);
    while(WindowShouldClose()==false)
    {
      BeginDrawing();
      ClearBackground(BLUE);
      if(Collision_with_axe || Collision_with_axe2)
      {
        DrawText("GameOver",400,200,40,RED);
       if( IsKeyDown(KEY_R) )
       {
         Collision_with_axe2 = false;
         Collision_with_axe = false;
         Circle_x = 350;
         Circle_y = 250;
       }
      }
      else
      {
        int l_circle_x = Circle_x - Circle_Radius;
        int r_circle_x = Circle_x + Circle_Radius;
        int u_circle_y = Circle_y - Circle_Radius;
        int b_circle_y = Circle_y + Circle_Radius;

        int l_axe_x = axe_x;
        int r_axe_x = axe_x + axe_length;
        int u_axe_y = axe_y;
        int b_axe_y = axe_y + axe_length;

        int l_axe_x2 =axe_x2;
        int r_axe_x2 =axe_x2 + axe_length;
        int u_axe_y2 = axe_y2;
        int b_axe_y2 = axe_y2 + axe_length;

        Collision_with_axe =
                              b_axe_y >= u_circle_y&&
                              u_axe_y <= b_circle_y&&
                              l_circle_x <= r_axe_x&&
                              r_circle_x >= l_axe_x;

         Collision_with_axe2 = 
                              b_axe_y2 >= u_circle_y&&
                              u_axe_y2 <= b_circle_y&&
                              l_circle_x <= r_axe_x2&&
                              r_circle_x >= l_axe_x2; 

        DrawCircle(Circle_x, Circle_y, Circle_Radius, RED);
        DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);
        DrawRectangle(axe_x2, axe_y2, axe_length, axe_length, RED);

      }
      axe_y += direction;
      axe_y2 += direction2;
      if(axe_y > height||axe_y < 0)
      {
        direction = -direction;
      }
      if(axe_y2 > height||axe_y < 0)
      {
        direction2 = -direction2;
      }

      if(IsKeyDown(KEY_D) && Circle_x < width)
      {
        Circle_x = Circle_x + 10;
      }

      if(IsKeyDown(KEY_A) && Circle_x > 0)
      {
        Circle_x -= 10;
      }
      
      if(IsKeyDown(KEY_S) && Circle_y < height)
      {
        Circle_y += 10;
      }
      if(IsKeyDown(KEY_W) && Circle_y > 0)
      {
        Circle_y -= 10;
      }
      
      EndDrawing();
    }
}
