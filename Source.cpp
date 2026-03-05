#include<raylib.h>
#include "player.hpp"

int main()
{
	
	const int screenWidth = 800;
	const int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	//SetTargetFPS(60);  
	Texture2D playerTexture = LoadTexture("C:\\Projects\\C++\\Raylib Projects\\Template\\Warrior\\Warrior_Idle.png");
	Player player=Player(playerTexture, 8, 1, {0,0}, 250);
	while (!WindowShouldClose())   
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		//

		player.update();
		player.draw();
		EndDrawing();
	}
	return 0;
}
