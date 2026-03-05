#include "player.hpp"

Player::Player(Texture2D tex, int frameCount, float animTime,Vector2 pos,float speed)
{
	this->texture = tex;
	this->frameCount = frameCount;
	this->animTime = animTime;
	this->state = PlayerState::IDLE;
	this->pos = pos;
	this->speed = speed;
	animPlayer.setTexture(tex, frameCount, animTime);
}
void Player::update()
{
	// Update player position, velocity, and state
	if (IsKeyDown(KEY_W))
	{
		dir.y = -1;
	}
	else if (IsKeyDown(KEY_S))
	{
		dir.y = 1;
	}
	else
		dir.y = 0;
	if (IsKeyDown(KEY_A))
	{
		dir.x = -1;
		animPlayer.Hdir = -1;
	}
	else if (IsKeyDown(KEY_D))
	{
		dir.x = 1;
		animPlayer.Hdir = 1;
	}
	else
		dir.x = 0;
	// state change
	if (Vector2Length(dir) > 0)
	{
		state = PlayerState::RUNNING;
		//if not attacking and stuff that is 
	}
	else
	{
		state = PlayerState::IDLE;
	}
	base::update();
	updateState();
}
void Player::updateState()
{
	
	// Update the player's state based on input and conditions
	// use animPlayer.setTexture(tex) to change the texture and anim of the player
	switch (state)
	{
	case PlayerState::IDLE:
		//animPlayer.setTexture(idleTexture, frameCount, animTime);
		break;
	case PlayerState::RUNNING:
		break;
	case PlayerState::JUMPING:
		break;
	case PlayerState::FALLING:
		break;
	default:
		break;
	}
}
void Player::draw()
{
	// Draw the player on the screen
	base::draw();
	DrawTextureRec(animPlayer.getTexture(), animPlayer.getAnimatedframe(), pos, WHITE);
	
}