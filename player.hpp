#pragma once
#include "base.hpp"
enum class PlayerState
{
	IDLE,
	RUNNING,
	JUMPING,
	FALLING
	// Add more states as needed
};

class Player : public base
{
private:
	// Player-specific attributes
	PlayerState state;
	Texture2D texture; // Player's texture(more like a current tex)
	int frameCount = 0;
	float animTime = 0;
	AnimPlayer animPlayer=AnimPlayer(texture,frameCount,animTime);
	//ADD TEXTURES HERE,load these either in the constructor, or manually
	Texture2D idleTexture;
	Texture2D runningTexture;
public:
	Player(Texture2D tex, int frameCount, float animTime, Vector2 pos, float speed);
	void update() override;//Update Player's stuff
	void updateState();//Updates state of the player
	void draw() override;//Draws the player
};
