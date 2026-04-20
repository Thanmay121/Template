#include "collosion.hpp"
#include "player.hpp"
#include "enemybase.hpp"


/*
	if(direction.x==0&&direction.y!=0)
	{
		return { pos.x + ((texture.width / frameWidth) / 3), pos.y + (-direction.x * 10 * speed*GetFrameTime()) + texture.height / 2, (float(texture.width) / float(frameWidth)) / 3, float(texture.height) / 5 };
	}
	if (direction.y == 0 && direction.x != 0)
	{
		return{ pos.x + (Hdir * 10 * speed * GetFrameTime()) + ((texture.width / frameWidth) / 3), pos.y  + texture.height / 2, (float(texture.width) / float(frameWidth)) / 4, float(texture.height) / 5 };
	}
	
	return { pos.x+(Hdir*10*speed*GetFrameTime()) + ((texture.width / frameWidth) / 3), pos.y + (-direction.x * direction.y * 10 * speed * GetFrameTime()) + texture.height / 2, (float(texture.width) / float(frameWidth)) / 4, float(texture.height) / 5 };
*/
Collosion::Collosion(Vector2 pos,Vector2 dir,float FrameWidth,float height,Vector2 offset)
{
	this->pos=pos;
	this->FrameWidth=FrameWidth;
	this->height=height;
	this->offset=offset;
	this->dir=dir;
}
void Collosion::Update(Vector2 pos,Vector2 dir,float FrameWidth,float height,int Hdir)
{
	this->pos=pos;
	this->FrameWidth=FrameWidth;
	this->height=height;
	this->dir=dir;
	this->Hdir=Hdir;
	HurtBox();
	NxtFrameBox();
	HitBox();
}
void Collosion::HurtBox()
{
	Rectangle rect;
	rect.x = pos.x + ((FrameWidth) / 3);
	rect.y = pos.y + height / 2;
	rect.width = FrameWidth /3;
	rect.height = float(height) / 5;
	this->hurtbox = rect;
}
void Collosion::NxtFrameBox()
{
	Rectangle rect=hurtbox;
	rect.x += offset.x*dir.x;
	rect.y += offset.y*dir.y;
	this->nxtFrameBox=rect;
}
void Collosion::HitBox()
{
	Rectangle rightrec= { pos.x + ((FrameWidth) / 1.5f),pos.y + (height / 4), (height) / 5 , ((FrameWidth) / 2) };
	Rectangle leftrec= { pos.x + ((FrameWidth) / 7),pos.y + (height / 4), float(height) / 5 , (FrameWidth / 2) };
	Rectangle bottomrec = { pos.x + ((FrameWidth) / 4),pos.y + (height / 1.5), (FrameWidth / 2) , (height) / 5 };
    if (dir.y > 0)
        this->hitbox = bottomrec;
    else if (Hdir < 0)
        this->hitbox = leftrec;
    else
        this->hitbox = rightrec;
}


void E2P(Player &player,enemyBase &enemy)
{
	if(CheckCollisionRecs(player.Cboxes.nxtFrameBox , enemy.Cboxes.hurtbox))
	{
		player.isColliding=true;
		//enemy shd be able to hit here 
	}
	else 
	player.isColliding=false;
}
void P2E(Player &player,enemyBase &enemy)
{
	if(CheckCollisionRecs(enemy.Cboxes.nxtFrameBox , player.Cboxes.hurtbox))
	{
		if(enemy.collideCooldown<=GetTime()-enemy.lastCollideTime)
		{
			enemy.isColliding=true;
			enemy.lastCollideTime=GetTime();
		}
		//enemy shd be able to hit here 
	}
	else 
	{
		
		enemy.isColliding=false;
	}
}
void PHit(Player &player,enemyBase &enemy)
{
	if(CheckCollisionRecs(player.Cboxes.hitbox, enemy.Cboxes.hurtbox))
	{
		if(player.state==PlayerState::ATTAKING)
		enemy.getHit=true;
		else
		enemy.getHit=false;
	}
	else
	enemy.getHit=false;
}
void EHit(Player &player,enemyBase &enemy)
{
	if(CheckCollisionRecs(enemy.Cboxes.hitbox, player.Cboxes.hurtbox))
	{
		enemy.state=EnemyState::ATTACKING;
		player.getHit=true;
		player.dmgObtained=enemy.attackStrength;
	}
	else
	{
		player.getHit=false;
	}
}

