#pragma once
#include "base.hpp"
#include "player.hpp"

enum class EnemyState
{
	IDLE,
	RUNNING,
	JUMPING,
    LOCKON,
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
public:
	enemyBase(Texture2D tex, int frameCount, float animTime, Vector2 pos, float speed,float hp);
	void update() override;
	void updateState();
	void draw() override;
	void lockon(Player &player);
};