#pragma once
#include "base.hpp"
#include "player.hpp"

enum class EnemyState
{
	IDLE,
	RUNNING,
	ATTACKING,
	WANDERING,
    DEAD
	// Add more states as needed
};

class enemyBase : public base
{
public:
	// Player-specific attributes
	EnemyState state;
	Texture2D texture; 
	int frameCount = 0;
	float animTime = 0;
	AnimPlayer animPlayer = AnimPlayer(texture, frameCount, animTime);
	//ADD TEXTURES HERE,load these either in the constructor, or manually
	Texture2D idleTexture;
	Texture2D runningTexture;
	float hp=100;
	Player* playerptr;
public:
	Collosion Cboxes;
	float attackcooldown = 1.0f;
	float lastattacktime = 0.f;
	enemyBase(Texture2D tex, int frameCount, float animTime, Vector2 pos, float speed,float hp,Player* playerptr);
	void update() override;
	void updateState();
	void draw() override;
	void lockon();
};