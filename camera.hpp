#pragma once
#include<raylib.h>
#include"player.hpp"
void lockOnEntity(Camera2D &camera,Player &entity)
	{
		camera.target = entity.pos;
		camera.offset = {1450/2,700/2};
		camera.rotation = 0.0f;
		camera.zoom=1.0f;
    }
void ShakeOn(Camera2D &camera,Player &entity,double shaketime, int intensity, double time)
{
	double c = GetTime();
	if(shaketime>c-time)
	{
	int a =  intensity*GetRandomValue(0,15);
	int b =  intensity*GetRandomValue(0,15);
	camera.offset = {(float)(1450/2)+(float)a,(float)(700/2)+(float)b};
	}

    
}

