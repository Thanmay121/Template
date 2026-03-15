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
	Sound bg1 = LoadSound("649132__sonically_sound__medievalfantasy-rpg-loop-mix-at-32-secs-to-extendrepeat.wav");
	Sound foots = LoadSound("file_example_WAV_1MG.wav");
	Player player=Player(playerTexture, 8, 1, {200,200}, 250,bg1,100);
	enemyBase enemy = enemyBase(playerTexture, 8, 1, {100,1000}, 150,100,player);
	enemyBase enemy1 = enemyBase(playerTexture, 8, 1, {400,2000}, 150,100,player);
	enemyBase enemy2 = enemyBase(playerTexture, 8, 1, {300,1500}, 150,100,player);
	enemyBase enemy3 = enemyBase(playerTexture, 8, 1, {500,900}, 150,100,player);

	Texture2D running = LoadTexture("Warrior\\Warrior_Run.png");
	Texture2D attack = LoadTexture("Warrior\\Warrior_Attack1.png");
	Texture2D attack2 = LoadTexture("Warrior\\Warrior_Attack1.png");
	Texture2D parry=LoadTexture("Warrior\\Warrior_Guard.png");
	player.runningTexture = running;
	player.attackTexture = attack;
	player.attackTexture2 = attack2;
	player.parryTexture=parry;
	enemy.idleTexture = playerTexture;
	enemy.runningTexture = running;
	//---
	ContractStatus status;
	status=ContractStatus::NONE;
	int j=1;
	//-------------------------LOAD LEVEL-------------------------------------
	auto bglvl1 = loadcsv("maps\\demo_1_bg_1.csv");
	auto bg2 = loadcsv("maps\\demo_1_bg_2.csv");
	auto bg3 = loadcsv("maps\\demo_1_bg_3.csv");
	auto bg4 = loadcsv("maps\\demo_1_bg_4.csv");
	auto bg5 = loadcsv("maps\\demo_1_bg_5.csv");
	auto castle = loadcsv("maps\\demo_1_castle.csv");
	auto house = loadcsv("maps\\demo_1_house.csv");
	auto monastry = loadcsv("maps\\demo_1_monastry.csv");
	auto house2 = loadcsv("maps\\demo_1_house2.csv");
	auto towers = loadcsv("maps\\demo_1_towers.csv");
	auto water = loadcsv("maps\\demo_1_water.csv");
	auto waterfoam = loadcsv("maps\\demo_1_water_foam.csv");
	Texture2D archery = LoadTexture("maps\\Archery.png");
	Texture2D archery2 = LoadTexture("maps\\Archery2.png");
	Texture2D Barracks = LoadTexture("maps\\Barracks.png");
	Texture2D Barracks2 = LoadTexture("maps\\Barracks2.png");
	Texture2D tilecastle= LoadTexture("maps\\Castle.png");
	Texture2D tilecastle2 = LoadTexture("maps\\Castle2.png");
	Texture2D tilehouse = LoadTexture("maps\\House1.png");
	Texture2D tilehouse2 = LoadTexture("maps\\House2.png");
	Texture2D tileHouse3 = LoadTexture("maps\\House3.png");
	Texture2D tileHouse12 = LoadTexture("maps\\House12.png");
	Texture2D tileHouse22 = LoadTexture("maps\\House22.png");
	Texture2D tileHouse32 = LoadTexture("maps\\House32.png");
	Texture2D tileMonastery = LoadTexture("maps\\Monastery.png");
	Texture2D tileShadow = LoadTexture("maps\\Shadow.png");
	Texture2D forest1 = LoadTexture("maps\\Tilemap_color1.png");
	Texture2D forest2 = LoadTexture("maps\\Tilemap_color2.png");
	Texture2D forest3 = LoadTexture("maps\\Tilemap_color3.png");
	Texture2D forest4 = LoadTexture("maps\\Tilemap_color4.png");
	Texture2D forest5 = LoadTexture("maps\\Tilemap_color5.png");
	Texture2D tiletower = LoadTexture("maps\\Tower.png");
	Texture2D tree1 = LoadTexture("maps\\Tree1.png");
	Texture2D tree2 = LoadTexture("maps\\Tree2.png");
	Texture2D tree3 = LoadTexture("maps\\Tree3.png");
	Texture2D tree4 = LoadTexture("maps\\Tree4.png");
	Texture2D bush = LoadTexture("maps\\Bushe1.png");
	Texture2D watertile = LoadTexture("maps\\Water_Background_color.png");
	Texture2D waterfoamtile = LoadTexture("maps\\Water_Foam.png");
	
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
	float switchTime=-99999.0f;
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
				enemy1.update();
				enemy2.update();
				enemy3.update();
				player.update();
				BeginDrawing();
				if (j == 1)
				{
					camsys.defaultcam(camera, player);
					j++;
				}
				ClearBackground(RAYWHITE);
				camera.target.x = Clamp(camera.target.x, 887.3f, 2350.0f);
				camera.target.y = Clamp(camera.target.y, 520.2f, 2800.1f);
				BeginMode2D(camera);
				DrawRectangle(400, 250, 30, 20, YELLOW);
				camsys.lockOnEntity(camera, player);
				// tilemap rendering
				//drawlevel(water, 32, watertile, ground);
				//drawlevel(bglvl1, 32, forest2, level);
				//drawlevel(bg2, 32, forest1, ground);
				//drawlevel(bg3, 32, tree3, level);
				//drawlevel(bg4, 32, tree4, level);
				//drawlevel(bg5, 32, bush, level);
				//drawlevel(house, 32, tilehouse, ground);
				//drawlevel(house2, 32, tilehouse2, ground);
				//drawlevel(monastry, 32, tileMonastery, ground);
				//drawlevel(castle, 32, tilecastle, ground);
				//drawlevel(towers, 32, tiletower, ground);
				drawlevel(water,32,watertile,ground);
				drawlevel(waterfoam, 32, waterfoamtile,ground);
				drawlevel(bg2, 32, forest1, ground);
				drawlevel(bglvl1, 32, forest2, level);
				drawlevel(bg3, 32, tree3, level);
				drawlevel(monastry, 32, tileMonastery, ground);
				drawlevel(house2, 32, tilehouse2, ground);
				drawlevel(house, 32, tilehouse, ground);
				drawlevel(bg4, 32, tree4, level);
				drawlevel(bg5, 32, bush, level);
				drawlevel(castle, 32, tilecastle, ground);
				drawlevel(towers, 32, tiletower, ground);
				SOUND soundsys;
				soundsys.playsoundinfi(bg1, 6);

				enemy.draw();
				enemy1.draw();
				enemy2.draw();
				enemy3.draw();
				player.draw();
				//collosion_checks
				if (player.state == PlayerState::RUNNING)
				{
					soundsys.playsoundinfi(foots,6);
				}
				E2P(player,enemy);
				P2E(player,enemy);
				PHit(player,enemy);
				EHit(player,enemy);
				if(currenttask!=TASKS::NONE)
				LOCKIN(currenttask,GetTime(),player,status);	
				//-----
				if(!timer(2,switchTime))
				{
					player.invi=true;
				}
				EndMode2D();
				if(currenttask!=TASKS::NONE)
				{
					DrawText(toText(currenttask).c_str(),0,0,5,BLACK);
				}
				DrawText((status==ContractStatus::OFF? "OFF":status==ContractStatus::ON? "ON":"NONE"),0,10,50,BLACK);
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
					status=ContractStatus::ON;
					switchTime=GetTime();
					player.pos=Vector2Add(player.pos,{100,100});//safe place
				}
				if(GameButton({ (float)screenWidth/2-250, (float)screenHeight/2-125, 500, 100  }, toText(B).c_str()))
				{
					currenttask = B;
					state = gameState::PlayerAlive;
					status=ContractStatus::ON;
					player.pos=Vector2Add(player.pos,{100,100});//safe place
				}
				EndDrawing();
				break;
			}
		}
	}
	return 0;
}
