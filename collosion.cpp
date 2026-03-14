#include "collosion.hpp"


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
Rectangle Collosion::HurtBox(Texture2D texture,int frameCount,Vector2 pos)
{
	int frameWidth = texture.width;
	Rectangle rect;
	rect.x = pos.x + ((texture.width / frameCount) / 3);
	rect.y = pos.y + texture.height / 2;
	rect.width = (float(texture.width) / float(frameCount)) / 3;
	rect.height = float(texture.height) / 5;
	hurtbox = rect;
	return rect;
}
Rectangle Collosion::nxtFrameBox(Vector2 offset,float widith,float height)
{
	Rectangle rect=hurtbox;
	rect.x += offset.x;
	rect.y += offset.y;
	rect.width = widith;
	rect.height = height;
	return rect;
}
Rectangle Collosion::GetHitBox(Vector2 offset, float widith, float height)
{
	Rectangle rect = hurtbox;
	rect.x += offset.x;
	rect.y += offset.y-25;
	rect.width = widith;
	rect.height = height;
	return rect;
}
bool Check_Collision(Rectangle box1, std::vector<Rectangle> boxes)
{
	for (Rectangle& box : boxes)
	{
		if (CheckCollisionRecs(box1, box))
		{
			return true;
		}
	}
	return false;
}

