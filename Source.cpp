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
	enemyBase enemy = enemyBase(playerTexture, 8, 1, {100,1000}, 150,100,player);
	Texture2D running = LoadTexture("Warrior\\Warrior_Run.png");
	Texture2D attack = LoadTexture("Warrior\\Warrior_Attack1.png");
	Texture2D attack2 = LoadTexture("Warrior\\Warrior_Attack1.png");
	player.runningTexture = running;
	player.attackTexture = attack;
	player.attackTexture2 = attack2;
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
	TASKS currenttask;
	float lastContract=0.0f;
	currenttask = TASKS::NONE;
	SetWindowPosition(0, 0);
	state=gameState::CONTRACT;
	//
	SetRandomSeed(int(GetTime()));
	TASKS A = TASKS::NONE;
	TASKS B = TASKS::NONE;
	while (!WindowShouldClose())
	{
		switch (state)
		{
			case gameState::PlayerAlive:
			{
				if (player.hp <= 0)
				{
					state = gameState::CONTRACT;
				}
				enemy.update();
				player.update();
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
				// tilemap rendering
				drawlevel(map, 32, tileset, level);
				drawlevel(solids, 32, tileset, ground);
				enemy.draw();
				player.draw();
				//collosion_checks
				E2P(player,enemy);
				P2E(player,enemy);
				PHit(player,enemy);
				EHit(player,enemy);
				LOCKIN(currenttask);	
				//-----
				EndMode2D();
				if(currenttask!=TASKS::NONE)
				{
					DrawText(toText(currenttask).c_str(),0,0,5,BLACK);
				}
				EndDrawing();
				break;
			}
		
			case gameState::CONTRACT:
			{
				if(player.hp<=0)
				{
					A=(TASKS)GetRandomValue(1,1);
					B=(TASKS)GetRandomValue(2,2);
					player.hp=110;
				}
				//contract state stuff
				BeginDrawing();
				ClearBackground(BLACK);
				DrawText("CONTRACT", screenWidth / 2 - MeasureText("CONTRACT", 25) ,10, 50, RED);
				if (GameButton({(float)screenWidth/2-250, (float)screenHeight/2, 500, 100 },toText(A).c_str()))
				{
					currenttask = A;
					state = gameState::PlayerAlive;
					player.pos=Vector2Add(player.pos,{100,100});//safe place
				}
				if(GameButton({ (float)screenWidth/2-250, (float)screenHeight/2-125, 500, 100  }, toText(B).c_str()))
				{
					currenttask = B;
					state = gameState::PlayerAlive;
					player.pos=Vector2Add(player.pos,{100,100});//safe place
				}
				EndDrawing();
				break;
			}
		}
	}
	return 0;
}
