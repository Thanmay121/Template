#include "enemyBase.hpp"
#include "player.hpp"
#include <raymath.h>
enemyBase::enemyBase(Texture2D tex, int frameCount, float animTime, Vector2 pos, float speed,float hp,Player* playerptr)
{
	this->texture = tex;
	this->hp = hp;
	this->frameCount = frameCount;
	this->animTime = animTime;
	this->state = EnemyState::IDLE;	
	this->pos = pos;
	this->speed = speed;
	this->playerptr = playerptr;
	animPlayer.setTexture(tex,frameCount,animTime);
}
void enemyBase::update()
{
	base::update();	
	animPlayer.Hdir = 0;
	animPlayer.Hdir = dir.x >0 ? 1 : -1;
	// Update player position, velocity, and state
	if(attackcooldown <= GetTime() - lastattacktime)
	{
		if(playerptr->hp>0)
		{
			if (playerptr->Cboxes.Check_Collision(playerptr->Cboxes.HurtBox(playerptr->texture, playerptr->frameCount, playerptr->pos), this->Cboxes.GetHitBox(Vector2Scale(dir, 10 * speed * GetFrameTime()), (float(texture.height) / 5), (float(texture.width) / float(frameCount)) / 3)))
			{
				playerptr->hp -= 10;
				lastattacktime = GetTime();
			}	
		}
		else
		{
			state = EnemyState::IDLE;
		}
		
	}
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
		animPlayer.setTexture(idleTexture, frameCount, animTime);
		break;
	case EnemyState::RUNNING:
		animPlayer.setTexture(runningTexture, 6, 1);
		break;
	case EnemyState::ATTACKING:
		break;
	}
}
void enemyBase::draw()
{
	// Draw the player on the screen
	base::draw();
	DrawTextureRec(animPlayer.getTexture(), animPlayer.getAnimatedframe(), pos, RED);
	DrawRectangleLinesEx(Cboxes.HurtBox(texture, frameCount, pos), 2, BLUE);
	DrawRectangleLinesEx(Cboxes.nxtFrameBox(Vector2Scale(dir, 10 * speed * GetFrameTime()), (float(texture.width) / float(frameCount)) / 3, float(texture.height) / 5), 2, RED);
	DrawRectangleLinesEx(Cboxes.GetHitBox(Vector2Scale(dir, 10 * speed * GetFrameTime()), (float(texture.height) / 5), (float(texture.width) / float(frameCount)) / 3), 2, RED);
}

/*
void enemyBase::lockon()
{
	Vector2 dir = Vector2Subtract(playerptr->pos, this->pos);
	float distance = Vector2Length(dir);
	if (!Cboxes.Check_Collision(playerptr->Cboxes.HurtBox(playerptr->texture, playerptr->frameCount, playerptr->pos), Cboxes.nxtFrameBox(Vector2Scale(dir, 10 * speed * GetFrameTime()), (float(texture.width) / float(frameCount)) / 3, float(texture.height) / 5)))
	{
		if (distance > 0.0f && distance < 350.0f)
		{
			this->dir = dir;
			this->state = EnemyState::RUNNING;
		}
		else
		{
			this->state = EnemyState::IDLE;
		}

	}
}
*/
void enemyBase::lockon()
{
	Vector2 dir = Vector2Subtract(playerptr->pos, this->pos);
	float distance = Vector2Length(dir);

	if (distance > 0.0f && distance < 350.0f)
	{
		if (distance > 50.0f)   // ? stop 50px away from player
		{
			this->dir = dir;
			if (state != EnemyState::RUNNING)
			{
				state = EnemyState::RUNNING;
				animPlayer.setTexture(runningTexture, 6, 1);
			}
		}
		else
		{
			this->dir = { 0, 0 };
			if (state != EnemyState::ATTACKING)
			{
				state = EnemyState::ATTACKING;
			}
		}
	}
	else
	{
		this->dir = { 0, 0 };
		if (state != EnemyState::IDLE)
		{
			state = EnemyState::IDLE;
			animPlayer.setTexture(idleTexture, frameCount, animTime);
		}
	}
}