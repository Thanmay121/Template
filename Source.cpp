#include<raylib.h>
#include <vector>
#include "player.hpp"
#include"sfx.hpp"
#include "camera.hpp"
#include "maps.hpp"
#include "enemyBase.hpp"
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

	Player player=Player(playerTexture, 8, 1, {0,0}, 250,bg1,100);
	enemyBase enemy = enemyBase(playerTexture, 8, 1, {100,1000}, 250,100);
	Texture2D running = LoadTexture("Warrior\\Warrior_Run.png");
	player.runningTexture = running;
	int j=1;
	//-------------------------LOAD LEVEL-------------------------------------
	auto map = loadcsv("maps\\testtilemap.csv");
	Texture2D tileset = LoadTexture("maps\\Tilemap_color1.png");
	
	//--------------------FIXING WINDOW------------------------------------
	int monitor = GetCurrentMonitor();
	screenHeight = GetMonitorHeight(monitor);
	screenWidth = GetMonitorWidth(monitor);
	SetWindowState(FLAG_WINDOW_UNDECORATED);
	SetWindowSize(screenWidth, screenHeight);
	SetWindowPosition(0, 0);
	while (!WindowShouldClose())   
	{
		player.update();
		enemy.update();        
        enemy.lockon(player);
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
		enemy.draw();
		// tilemap rendering
		drawlevel(map,32,tileset);
		EndMode2D();
		EndDrawing();
	}
	return 0;
}
