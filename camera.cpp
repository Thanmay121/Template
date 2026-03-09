#pragma once
#include"camera.hpp"
void CAMERA::defaultcam(Camera2D &camera,Player &entity)
{
	camera.offset = {camx,camy};
}
void CAMERA::lockOnEntity(Camera2D &camera,Player &entity)
	{
		camera.target = entity.pos;
		camera.rotation = 0.0f;
		camera.zoom=1.0f;
    }
void CAMERA::ShakeOn(Camera2D &camera,Player &entity,double shaketime, int intensity,double time)
{
	double c = GetTime();
	if(shaketime+time>c)
	{
	int a =  intensity*GetRandomValue(-15,15);
	int b =  intensity*GetRandomValue(-15,15);
	camera.offset = {(float)(camx)+(float)a,(float)(camy)+(float)b};
	i=1;
	}
	else if (i!=1)
	{
	camera.offset= {camx,camy};
	i++;
	}}
void CAMERA::Yoffset(Camera2D &camera, Player &entity, int intensity, int direction)
{
    float targetX = camx;
    float targetY = (camy) + (intensity * direction);
    float t = GetFrameTime();
    camera.offset.x += (targetX - camera.offset.x)  *  t;
    camera.offset.y += (targetY - camera.offset.y)  * t;
}
void CAMERA::Xoffset(Camera2D &camera, Player &entity, int offsetdist, int direction,int intensity)
{
    float targetX = camx + (offsetdist * direction);
    float targetY = (camy);
    float t = GetFrameTime();
    camera.offset.x += (targetX - camera.offset.x)  *  t * intensity;
    camera.offset.y += (targetY - camera.offset.y)  * t * intensity;
}

