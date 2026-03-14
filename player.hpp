#pragma once
#include "base.hpp"
#include <string>
enum class PlayerState
{
	IDLE,
	RUNNING,
	ATTAKING,
	CONTRACT,
	DEAD
	// Add more states as needed
};

class Player : public base
{
private:
	// Player-specific attributes
	PlayerState state; // Player's texture(more like a current tex)
	float animTime = 0;		
	AnimPlayer animPlayer=AnimPlayer(texture,frameCount,animTime);
	Sound s;
	SOUND soundsys;
	//ATTACK
	float attackcooldown = 0.5f;
	float lastattacktime = 0.f;
public:
	Texture2D idleTexture;
	Texture2D attackTexture;
	Texture2D runningTexture;
	Texture2D texture;
	int frameCount = 0;
	Collosion Cboxes;
	float hp = 100;
	Player(Texture2D tex, int frameCount, float animTime, Vector2 pos, float speed,Sound s,float hp);
	void update() override;//Update Player's stuff
	void updateState();//Updates state of the player
	void draw() override;//Draws the player
};
