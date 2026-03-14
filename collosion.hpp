#pragma once
#include<raylib.h>
#include<vector>
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
public:
	Rectangle hitbox;
	Rectangle hurtbox;
	Rectangle HurtBox(Texture2D texture, int frameCount, Vector2 pos);
	Rectangle nxtFrameBox(Vector2 offset, float widith, float height);
	bool Check_Collision(Rectangle box1, Rectangle box2)
	{
		return CheckCollisionRecs(box1, box2);
	}
	bool Check_Collision(Rectangle box1, std::vector<Rectangle> boxes);
	Rectangle GetHitBox(Vector2 pos, float width, float height);

	
};