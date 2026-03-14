#include<raylib.h>
#include <vector>
#include "player.hpp"
#include"sfx.hpp"
#include "camera.hpp"
#include "maps.hpp"
#include "enemyBase.hpp"
#include "GameManager.hpp"
int main()
{

	gameState state = gameState::PlayerAlive;
	std::vector<Rectangle> level;
	std::vector<Rectangle> ground;
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
	enemyBase enemy = enemyBase(playerTexture, 8, 1, {100,1000}, 250,100,&player);
	Texture2D running = LoadTexture("Warrior\\Warrior_Run.png");
	Texture2D attack = LoadTexture("C:\\Projects\\C++\\Raylib Projects\\Template2.0\\Template\\Warrior\\Warrior_Attack1.png");
	player.runningTexture = running;
	player.attackTexture = attack;
	enemy.idleTexture = playerTexture;
	enemy.runningTexture = running;
	int j=1;
	//-------------------------LOAD LEVEL-------------------------------------
	auto map = loadcsv("maps\\testtilemap.csv");
	auto solids = loadcsv("maps\\testtilemap_walls_walls.csv");
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
		switch (state)
		{
		case gameState::PlayerAlive:
			if (player.hp <= 0)
			{
				state = gameState::CONTRACT;
			}
			player.update();
			enemy.update();
			enemy.lockon();
			//playersound(bg1,6);
			BeginDrawing();
			if (j == 1)
			{
				camsys.defaultcam(camera, player);
				j++;
			}
			ClearBackground(RAYWHITE);
			BeginMode2D(camera);
			DrawRectangle(400, 250, 30, 20, YELLOW);
			camsys.lockOnEntity(camera, player);
			player.draw();
			enemy.draw();
			// tilemap rendering
			drawlevel(map, 32, tileset, level);
			drawlevel(solids, 32, tileset, ground);
			EndMode2D();
			EndDrawing();

			break;
		case gameState::CONTRACT:
			//contract state stuff
			BeginDrawing();
			ClearBackground(BLACK);
			DrawText("CONTRACT", screenWidth / 2 - MeasureText("CONTRACT", 50) / 2, screenHeight / 2 - 25, 50, RED);
			if (GameButton({ 100, 100, 200, 50 }, "TASK A"))
			{
				// handle click
			}
			if(GameButton({ 100, 200, 200, 50 }, "TASK B"))
			{
				// handle click
			}
			EndDrawing();
			break;
		}
	}
	return 0;
}
