#include "enemyBase.hpp"
#include "player.hpp"
#include <raymath.h>
enemyBase::enemyBase(Texture2D tex, int frameCount, float animTime, Vector2 pos, float speed,float hp)
{
	this->texture = tex;
	this->hp = hp;
	this->frameCount = frameCount;
	this->animTime = animTime;
	this->state = EnemyState::IDLE;	
	this->pos = pos;
	this->speed = speed;
	animPlayer.setTexture(tex,frameCount,animTime);
}
void enemyBase::update()
{
	base::update();	
	// Update player position, velocity, and state
	updateState();
}
void enemyBase::updateState()
{
	if(this->hp<0)
	{
		state = EnemyState::DEAD;
	}
	switch (state)
	{
	case EnemyState::DEAD:
	break;
	case EnemyState::IDLE:
		//animPlayer.setTexture(idleTexture, frameCount, animTime);
		break;
	case EnemyState::RUNNING:
		break;
	case EnemyState::JUMPING:
		break;
	}
}
void enemyBase::draw()
{
	// Draw the player on the screen
	base::draw();
	DrawTextureRec(animPlayer.getTexture(), animPlayer.getAnimatedframe(), pos, RED);

}
void enemyBase::lockon(Player &player)
{
	Vector2 dir = Vector2Subtract(player.pos, this->pos);
	float distance = Vector2Length(dir);
	if (distance >0.0f && distance< 350.0f)
	{
		this->dir=dir;
        this->state = EnemyState::RUNNING;
	}
	else
    {
        this->state = EnemyState::IDLE;
    }

}
