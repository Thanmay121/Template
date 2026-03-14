#include<raylib.h>
#include <vector>
#include "player.hpp"
#include"sfx.hpp"
#include "camera.hpp"
#include "maps.hpp"
#include "enemyBase.hpp" 
#include "Dialogue.cpp"
int main()
{
	CAMERA camsys;
	bool hasTiggered = false;
	bool isDialogueActive = false;
	bool hasTriggered = false;       // A safety lock so we only trigger it once
	char* myText = "Warrior, beware! There are enemies ahead.\nPress ENTER to continue...";
	int charCount = 0;
	int textTimer = 1;
	Camera2D camera = {0};
	int screenWidth = 1600;
	int screenHeight = 900;
	InitWindow(screenWidth, screenHeight, "man");
	InitAudioDevice();
	SetTargetFPS(60);  
	Texture2D playerTexture = LoadTexture("Warrior\\Warrior_Idle.png");
	Texture2D golem = LoadTexture("Warrior\\Golem_1_idle.png");
	Sound bg1 = LoadSound("file_example_WAV_1MG.wav");

	Player player=Player(playerTexture, 8, 1, {0,0}, 250,bg1,100);
	enemyBase enemy = enemyBase(golem, 8, 1, {100, 0}, 50, 100);
	Texture2D running = LoadTexture("Warrior\\Warrior_Run.png");
	Texture2D golemrunning = LoadTexture("Warrior\\Golem_1_walk.png");
	player.runningTexture = running;
	enemy.runningTexture = golemrunning;
	int j=1;
	//-------------------------LOAD LEVEL-------------------------------------
	auto map = loadcsv("maps\\testtilemap.csv");
	auto ground = loadcsv("maps\\first_lvl_ground.csv");
	auto castle = loadcsv("maps\\first_lvl_castle.csv");
	auto water = loadcsv("maps\\first_lvl_water.csv");
	auto tower = loadcsv("maps\\first_lvl_tower.csv");
	Texture2D tileset = LoadTexture("maps\\Tilemap_color1.png");
	Texture2D tileset1 = LoadTexture("maps\\Castle.png");
	Texture2D tileset2 = LoadTexture("maps\\Tower.png");
	Texture2D tileset3 = LoadTexture("maps\\Water_Background_color.png");
	
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
		if (GetTime() > 3.0f && !hasTriggered)
        {
            isDialogueActive = true; 
            hasTriggered = true; 
        }
        if (isDialogueActive)
        {
            dia(myText, 0, 3, 5, charCount, textTimer, isDialogueActive);
        }
		ClearBackground(RAYWHITE);
		BeginMode2D(camera);
		DrawRectangle(400,250,30,20,YELLOW);
		camsys.lockOnEntity(camera,player);
		// tilemap rendering
		drawlevel(water,32,tileset3);
		drawlevel(ground,32,tileset);
		drawlevel(castle,32,tileset1);
		drawlevel(tower,32,tileset2);
		player.draw();

		enemy.draw();
		EndMode2D();
		if (isDialogueActive)
        {
            // 1. Draw the dark background box
            DrawRectangle(100, screenHeight - 250, screenWidth - 200, 200, Fade(BLACK, 0.8f));
            // 2. Draw the white border
            DrawRectangleLines(100, screenHeight - 250, screenWidth - 200, 200, WHITE);
            // 3. Draw the typewriter text
            // TextSubtext uses the charCount math your dia() function calculated
            DrawText(TextSubtext(myText, 0, charCount), 130, screenHeight - 220, 30, WHITE);
        }
		EndDrawing();
	}
	return 0;
}
