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
	this->idleTexture = tex;
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
	
	switch (state)
	{
	case EnemyState::DEAD:
		break;
	case EnemyState::IDLE:
		animPlayer.setTexture(idleTexture, frameCount, animTime);
		break;
	case EnemyState::RUNNING:
		break;
	case EnemyState::JUMPING:
		break;
	}
}
void enemyBase::draw()
{
    base::draw();

    // 1. Choose your multiplier (2.0f is double size, 3.0f is triple, 0.5f is half)
    float scale = 5.0f; 

    // 2. Get the animation frame (The Source)
    Rectangle sourceRect = animPlayer.getAnimatedframe();

    // 3. Build the stretching box (The Destination)
    // We multiply the width and height by our scale!
    Rectangle destRect = { this->pos.x, this->pos.y, sourceRect.width * scale, sourceRect.height * scale };
    // The {0,0} is the origin point, and the 0.0f is rotation.
    DrawTexturePro(animPlayer.getTexture(), sourceRect, destRect, {0, 0}, 0.0f, WHITE);
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
