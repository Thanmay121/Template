#include "enemyBase.hpp"
#include "player.hpp"
#include <raymath.h>
enemyBase::enemyBase(Texture2D tex, int frameCount, float animTime, Vector2 pos, float speed,float hp,Player& playerptr): playerptr(playerptr),
      texture(tex),
      frameCount(frameCount),
      animTime(animTime),
      animPlayer(tex, frameCount, animTime),   
      Cboxes(pos, dir, animPlayer.getWidth(),  
             animPlayer.getTexture().height, {30,30})
{
	this->texture = tex;
	this->hp = hp;
	this->frameCount = frameCount;
	this->animTime = animTime;
	this->state = EnemyState::IDLE;	
	this->pos = pos;
	this->speed = speed;
	animPlayer.setTexture(tex,frameCount,animTime);
	SetRandomSeed(int(GetTime()));
}
void enemyBase::update()
{
	if(hp<0)
	{
		alive =false;
		pos={100000,100000};
	}
	if(alive)
	{
		if(state==EnemyState::ATTACKING)
		{
			dir={0,0};
		}
		else
		lockon();
		base::update();	
		// Update player position, velocity, and state

		//HURT
		if(getHit)
		{
			if(hurtcooldown<=GetTime()-lasthurttime)
			{
				takedmg(playerptr.attackStrength);
				hitTaken=true;
				lasthurttime=GetTime();
			}
			hitTaken=false;
			}
			if (.2f>=GetTime() - lasthurttime)  
    		{
    		    tint = RED;
    		}
    		else
    		{
    		    tint = WHITE;
    		}
			updateState();
			Cboxes.Update(pos,dir,animPlayer.getWidth(),animPlayer.getTexture().height,animPlayer.Hdir);
	}

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
		animPlayer.setTexture(texture, frameCount, animTime);
		break;
	case EnemyState::RUNNING:
		animPlayer.setTexture(runningTexture, 6, 1);
		break;
	case EnemyState::ATTACKING:
		animPlayer.setTexture(attackTexture,4,0.75);
		if(0.75<=GetTime()-lastattacktime)
		{
			state = EnemyState::IDLE;
		}
		break;
	}
}
void enemyBase::draw()
{
	if(alive)
	{
		base::draw();
		DrawTextureRec(animPlayer.getTexture(), animPlayer.getAnimatedframe(), pos, tint);
		//DrawText(TextFormat("Dir: %.2f, %.2f", dir.x,dir.y), playerptr.pos.x,playerptr.pos.y,2, BLACK);
		//DrawRectangleLinesEx(Cboxes.hurtbox,2,BLUE);
		//DrawRectangleLinesEx(Cboxes.nxtFrameBox,2,GREEN);
		//DrawRectangleLinesEx(Cboxes.hitbox,2,RED);
		DrawText(TextFormat("HP: %.0f /100", hp), pos.x,pos.y, 20, RED);
	}
	// Draw the player on the screen

}
void enemyBase::lockon()
{
	Vector2 dir = Vector2Subtract(playerptr.pos, this->pos);
	float distance = Vector2Length(dir);
	if (distance > 0.0f && distance < 350.0f)
	{
		if(isColliding)
		{
			this->dir={0,0};
			this->state=EnemyState::IDLE;
		}
		else
		{
			this->dir=Vector2Normalize(dir);
			this->state = EnemyState::RUNNING;
			this->animPlayer.Hdir=((dir.x <= 0.0f) ? 1.0f : -1.0f)*((dir.y <= 0.0f) ? 1.0f : -1.0f)*((dir.x!=0.0f&&dir.y>0) ? 1.0f :-1.0f);
		
		}
		
	}
	else
	{
		this->dir={0,0};
		this->state = EnemyState::IDLE;

	}

}
