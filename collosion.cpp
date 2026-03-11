#include "collosion.hpp"


Rectangle collosionBox(Vector2 direction,Vector2 pos,int speed, Rectangle collider, int offsecx,int offsety)
{
    collider.x= pos.x +offsecx;
    collider.y=pos.y+offsety;//actuall center of the player
    return collider;
}

void checkCollosion(Rectangle r1,Rectangle r2, Vector2 pos)
{
    if(CheckCollisionRecs(r1,r2))
    {
        //if collided
        
    }
}

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