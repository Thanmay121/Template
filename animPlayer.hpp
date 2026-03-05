#pragma once
#include <raylib.h>

class AnimPlayer
{
private:
	Texture2D texture;
	int frameCount=0;
	float animTime=0;
	float currentTime=0;
	int currentFrame = 0;
public:
	AnimPlayer(Texture2D tex,int framecount,float animtime);
	Rectangle getAnimatedframe();
	void setTexture(Texture2D tex, int framecount, float animtime);
	bool isAnimComplete();
	Texture2D getTexture() { return this->texture; }
	int Hdir = 1;
};


