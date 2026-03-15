#pragma once
#include "base.hpp"
#include "player.hpp"

enum class EnemyState
{
	IDLE,
	RUNNING,
	ATTACKING,
	WANDERING,
	HURT,
    DEAD
	// Add more states as needed
};

class enemyBase : public base
{
private:
	// Player-specific attributes
	Texture2D texture; 
	int frameCount = 0;
	float animTime = 0;
	AnimPlayer animPlayer;
	Player playerptr;
public:
	bool isColliding=false;
	bool dmgtaken=false;
	bool ALIVE=true;
	EnemyState state;
	Collosion Cboxes;
	Texture2D idleTexture;
	Texture2D runningTexture;
	Texture2D attackTexture;
	bool getHit=false;
	Color tint=WHITE;
	float hurtcooldown = 1.0f;
	float lasthurttime = 0.f;
	float hp=100;
	float attackStrength=10;
	float attackcooldown = 1.0f;
	float lastattacktime = 0.f;
	float collideCooldown=0.2f;
	float lastCollideTime=0.0f;
	enemyBase(Texture2D tex, int frameCount, float animTime, Vector2 pos, float speed,float hp,Player& playerptr);
	void update() override;
	void updateState();
	void draw() override;
	void takedmg(float dmg){this->hp-=dmg;}
	void lockon();
};