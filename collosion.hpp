#pragma once
#include<raylib.h>
#include<vector>


class Player;
class enemyBase;
/*bool Check_Collision(Player* player, std::vector<Enemy>& enemies)
{
	bool iscolliding = false;
	for (Enemy &enemy : enemies)
	{
		if (CheckCollisionRecs(player->nxtFrameBox(), enemy.getHitBox()))
		{
			iscolliding=true;
		}
	}
	return iscolliding;
		 
}
*/

class Collosion
{
private:
	Vector2 pos;
	float height;
	float FrameWidth;
	Vector2 offset;
	Vector2 dir;
	int Hdir;
public:
	Rectangle hitbox;
	Rectangle nxtFrameBox;
	Rectangle hurtbox;
	void HurtBox();
	void NxtFrameBox();
	void HitBox();
	void Update(Vector2 pos,Vector2 dir,float FrameWidth,float height,int Hdir);
	Collosion(Vector2 pos,Vector2 dir,float FrameWidth,float height,Vector2 offset);
	
};
//enemy to player and vice verca, for player use for loop
void E2P(Player &player,enemyBase &enemy);
void P2E(Player &player,enemyBase &enemy);
void PHit(Player &player,enemyBase &enemy);
void EHit(Player &player,enemyBase &enemy);