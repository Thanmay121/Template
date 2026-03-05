#include "animPlayer.hpp"


AnimPlayer::AnimPlayer(Texture2D tex, int framecount, float animtime)
{
	this->texture = tex;
	this->frameCount = framecount;
	this->animTime = animtime;
}
void AnimPlayer::setTexture(Texture2D tex, int framecount, float animtime)
{
	this->texture = tex;
	this->frameCount = framecount;
	this->animTime = animtime;
	//-----------------------
	this->currentTime = 0;
	this->currentFrame = 0;

}
Rectangle AnimPlayer::getAnimatedframe()
{
	Rectangle frameRec;
	this->currentTime += GetFrameTime();
	if (this->currentTime >= this->animTime / this->frameCount)
	{
		currentFrame += 1;
		if (currentFrame > frameCount)
		{
			currentFrame = 1;
		}
		this->currentTime = 0.0f;
	}
	frameRec.x = (float)(currentFrame - 1) * (float)this->texture.width / (float)this->frameCount;
	frameRec.y = 0.0f;
	frameRec.width = Hdir * (float)this->texture.width / (float)this->frameCount;
	frameRec.height = (float)this->texture.height;
	return frameRec;
}
bool AnimPlayer::isAnimComplete()
{
	return (currentFrame == frameCount);
}

/*
	HOW TO USE:
	-pass default animTex on the constructor.
	-get the rest using setupAnimTex() function.
	IMP:
	-pass time in sec for the anim to complete one loop
	-ALWAYS MAKE SURE setTexture() is called before getAnimatedframe() isComplete() shd be the last one.
*/