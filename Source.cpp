#include<raylib.h>
#include "player.hpp"
#include "camera.hpp"
int main()
{
	Camera2D camera = {0};
	const int screenWidth = 1600;
	const int screenHeight = 900;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	//SetTargetFPS(60);  
	Texture2D playerTexture = LoadTexture("F:\\...code\\Template\\Template\\Warrior\\Warrior_Idle.png");
	Player player=Player(playerTexture, 8, 1, {0,0}, 250);
	
	
	
	while (!WindowShouldClose())   
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode2D(camera);
		DrawRectangle(400,250,30,20,YELLOW);
		lockOnEntity(camera,player);
		ShakeOn(camera,player,0.5,1,0.9);
		player.update();
		player.draw();
		EndMode2D();
		EndDrawing();
	}
	return 0;
}
