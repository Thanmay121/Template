#include<raylib.h>
#include <vector>
#include "player.hpp"
#include"sfx.hpp"
#include "camera.hpp"
#include "maps.hpp"
int main()
{
	CAMERA camsys;
	Camera2D camera = {0};
	int screenWidth = 1600;
	int screenHeight = 900;
	InitWindow(screenWidth, screenHeight, "man");
	InitAudioDevice();
	SetTargetFPS(60);  
	Texture2D playerTexture = LoadTexture("Warrior\\Warrior_Idle.png");
	Sound bg1 = LoadSound("file_example_WAV_1MG.wav");
	Player player=Player(playerTexture, 8, 1, {0,0}, 250,bg1);
	int j=1;
	//-------------------------LOAD LEVEL-------------------------------------
	auto map = loadcsv("maps\\testtilemap.csv");
	Texture2D tileset = LoadTexture("maps\\Tilemap_color1.png");
	
	//--------------------FIXING WINDOW------------------------------------
	int monitor = GetCurrentMonitor();
	screenHeight = GetMonitorHeight(monitor);
	screenWidth = GetMonitorWidth(monitor);
	SetTargetFPS(GetMonitorRefreshRate(monitor));
	SetWindowState(FLAG_WINDOW_UNDECORATED);
	SetWindowSize(screenWidth, screenHeight);
	SetWindowPosition(0, 0);
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
		// tilemap rendering
		drawlevel(map,32,tileset);
		EndMode2D();
		EndDrawing();
	}
	return 0;
}
