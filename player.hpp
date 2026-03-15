#pragma once
#include "base.hpp"
#include <string>
enum class PlayerState
{
	IDLE,
	RUNNING,
	ATTAKING,
	INTASK,
	DEAD
	// Add more states as needed
};

class Player : public base
{
private:
	// Player-specific attributes
	float animTime = 0;		
	AnimPlayer animPlayer=AnimPlayer(texture,frameCount,animTime);
	Sound s;
	SOUND soundsys;
	//ATTACK
	float attackcooldown = 0.5f;
	float lastattacktime = 0.f;
public:
	PlayerState state; // Player's texture(more like a current tex)
	float attackStrength=40.0f;
	Texture2D idleTexture;
	Texture2D attackTexture;
	Texture2D attackTexture2;
	Texture2D runningTexture;
	Texture2D texture;
	bool Attackdone=false;
	int frameCount = 0;
	Collosion Cboxes=Collosion(pos,dir,animPlayer.getWidth(),animPlayer.getTexture().height,{30,30});
	float hp = 100;
	Color tint=WHITE;
	bool isColliding=false;
	bool isCollidingObj=false;
	bool getHit=false;
	float hurtcooldown = 1.0f;
	float lasthurttime = 0.f;
	float dmgObtained=0;
	void takedmg(float dmg){this->hp-=dmg;}
	Player(Texture2D tex, int frameCount, float animTime, Vector2 pos, float speed,Sound s,float hp);
	void update() override;//Update Player's stuff
	void updateState();//Updates state of the player
	void draw() override;//Draws the player
};
