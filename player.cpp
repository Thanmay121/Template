#include "player.hpp"


Player::Player(Texture2D tex, int frameCount, float animTime,Vector2 pos,float speed,Sound s,float hp)
{
	this->texture = tex;
	this->frameCount = frameCount;
	this->animTime = animTime;
	this->state = PlayerState::IDLE;
	this->pos = pos;
	this->speed = speed;
	this->s=s;
	this->hp=hp;
	animPlayer.setTexture(tex, frameCount, animTime);
	SetRandomSeed(int(GetTime()));
}

void Player::update()
{
	// Update player position, velocity, and state
	if (IsKeyDown(KEY_W))
	{
		dir.y = -1;
		animPlayer.Hdir = -1;
	}
	else if (IsKeyDown(KEY_S))
	{
		dir.y = 1;
		animPlayer.Hdir = 1;
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
	if (IsKeyPressed(KEY_RIGHT_SHIFT))
	{
		
		if (attackcooldown <= GetTime() - lastattacktime)
		{
			lastattacktime = GetTime();
			state = PlayerState::ATTAKING;
		}
		
	}
	if(state!=PlayerState::ATTAKING)
	{
		if (Vector2Length(dir) > 0&& isColliding==false)
		{
			state = PlayerState::RUNNING;
			soundsys.playsoundinfi(s, 6);
			base::update();
			//if not attacking and stuff that is 
		}
		else
		{
			state = PlayerState::IDLE;
			if (IsSoundPlaying(s))
			{
				StopSound(s);
			}
		}
	}

	if (this->hp < 0)
	{
		state = PlayerState::INTASK;
	}
	//GETTING HIT
	if(getHit)
	{
		if(hurtcooldown<=GetTime()-lasthurttime)
		{
			takedmg(dmgObtained);
			lasthurttime=GetTime();
		}
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
void Player::updateState()
{
	// Update the player's state based on input and conditions
	// use animPlayer.setTexture(tex) to change the texture and anim of the player
	switch (state)
	{
	case PlayerState::DEAD:
	break;
	case PlayerState::IDLE:
		animPlayer.setTexture(texture, frameCount, animTime);
		break;
	case PlayerState::RUNNING:
		animPlayer.setTexture(runningTexture,6,1);
		break;
	case PlayerState::INTASK:
		break;
	case PlayerState::ATTAKING:
	{
		if (animPlayer.getTexture().id != attackTexture.id && animPlayer.getTexture().id != attackTexture2.id)
		{
			int rand=GetRandomValue(0,1);
			if(rand==1)
			animPlayer.setTexture(attackTexture,4,0.75);
			else
			animPlayer.setTexture(attackTexture2,4,0.75);
		}
		if(0.75<=GetTime()-lastattacktime)
		{
			state = PlayerState::IDLE;
		}
		break;
	}
	default:
		break;
	}
}
void Player::draw()
{
	// Draw the player on the screen
	base::draw();
	DrawTextureRec(animPlayer.getTexture(), animPlayer.getAnimatedframe(), pos, tint);
	DrawRectangleLinesEx(Cboxes.hurtbox,2,BLUE);
	DrawRectangleLinesEx(Cboxes.nxtFrameBox,2,GREEN);
	DrawRectangleLinesEx(Cboxes.hitbox,2,YELLOW);
	DrawText(TextFormat("%f  %f", pos.x, pos.y), pos.x, pos.y, 20, RED);
	//DrawText(TextFormat("%.0f, %.0f", mouse.x, mouse.y), mouse.x + 10, mouse.y, 20, BLACK);
}