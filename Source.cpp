#include<raylib.h>
#include "player.hpp"
#include"sfx.hpp"
#include "camera.hpp"
int main()
{
	CAMERA camsys;
	Camera2D camera = {0};
	const int screenWidth = 1600;
	const int screenHeight = 900;
	InitWindow(screenWidth, screenHeight, "man");
	InitAudioDevice();
	SetTargetFPS(60);  
	Texture2D playerTexture = LoadTexture("Warrior\\Warrior_Idle.png");
	Sound bg1 = LoadSound("F:\\...code\\Template\\Template\\file_example_WAV_1MG.wav");
	Player player=Player(playerTexture, 8, 1, {0,0}, 250,bg1);
	int j=1;
	
	
	while (!WindowShouldClose())   
	{
		player.update();
		//playersound(bg1,6);
		BeginDrawing();
		if (j==1)
		{
			camsys.defaultcam(camera,player);
			j++;
		}
		ClearBackground(RAYWHITE);
		BeginMode2D(camera);
		DrawRectangle(400,250,30,20,YELLOW);
		camsys.lockOnEntity(camera,player);
		player.draw();
		EndMode2D();
		EndDrawing();
	}
	return 0;
}
