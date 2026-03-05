#include "enemybase.hpp"
#include "player.hpp"

enemyBase::enemyBase(Texture2D tex, int frameCount, float animTime, Vector2 pos, float speed)
{
	this->texture = tex;
	this->frameCount = frameCount;
	this->animTime = animTime;
	this->state = EnemyState::IDLE;
	this->pos = pos;
	this->speed = speed * GetFrameTime();
}
void enemyBase::update()
{
	base::update();	
	// Update player position, velocity, and state
	updateState();
}
void enemyBase::updateState()
{
	// Update the player's state based on input and conditions
	// use animPlayer.setTexture(tex) to change the texture and anim of the player
	switch (state)
	{
	case EnemyState::IDLE:
		//animPlayer.setTexture(idleTexture, frameCount, animTime);
		break;
	case EnemyState::RUNNING:
		break;
	case EnemyState::JUMPING:
		break;
	case EnemyState::FALLING:
		break;
	default:
		break;
	}
}
void enemyBase::draw()
{
	// Draw the player on the screen
	base::draw();
	DrawTextureRec(animPlayer.getTexture(), animPlayer.getAnimatedframe(), pos, WHITE);
}