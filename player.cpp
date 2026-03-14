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
	if (IsKeyPressed(KEY_RIGHT_SHIFT))
	{
		
		if (attackcooldown <= GetTime() - lastattacktime)
		{
			lastattacktime = GetTime();
			state = PlayerState::ATTAKING;
		}
		
	}
	if (state != PlayerState::ATTAKING)
	{
		if (Vector2Length(dir) > 0)
		{
			state = PlayerState::RUNNING;
			soundsys.playsoundinfi(s, 6);

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
		state = PlayerState::CONTRACT;
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
	case PlayerState::DEAD:
	break;
	case PlayerState::IDLE:
		animPlayer.setTexture(texture, frameCount, animTime);
		break;
	case PlayerState::RUNNING:
		animPlayer.setTexture(runningTexture,6,1);
		break;
	case PlayerState::CONTRACT:
		break;
	case PlayerState::ATTAKING:
		animPlayer.setTexture(attackTexture, 4, .75);
		if(animPlayer.isAnimComplete())
		{
			state = PlayerState::IDLE;
		}
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
	DrawRectangleLinesEx(Cboxes.HurtBox(texture,frameCount,pos), 2, BLUE);
	DrawRectangleLinesEx(Cboxes.nxtFrameBox(Vector2Scale(dir, 10 * speed * GetFrameTime()), (float(texture.width) / float(frameCount)) / 3, float(texture.height) / 5), 2, RED);
	DrawText(((state==PlayerState::ATTAKING) ?"ATTACKING":"Other"), pos.x, pos.y - 20, 20, BLACK);
	DrawText(("LastAttackTime: " + std::to_string((int)lastattacktime)).c_str(), pos.x, pos.y - 40, 20, BLACK);
	DrawText(("HP: " + std::to_string((int)hp)).c_str(), pos.x, pos.y - 60, 20, BLACK);
	DrawRectangleLinesEx(Cboxes.GetHitBox(Vector2Scale(dir, 10 * speed * GetFrameTime()),( float(texture.height) / 5), (float(texture.width) / float(frameCount)) / 3), 2, RED);
}