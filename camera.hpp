#pragma once
#include<raylib.h>
#include"player.hpp"
class CAMERA
{
	public:
	float camx = 840;
	float camy= 450;
	int i =0;
	void defaultcam(Camera2D &camera,Player &entity);
	void lockOnEntity(Camera2D &camera,Player &entity);
	void ShakeOn(Camera2D &camera,Player &entity,double shaketime, int intensity,double time);
	void Yoffset(Camera2D &camera, Player &entity, int intensity, int direction);
	void Xoffset(Camera2D &camera, Player &entity, int offsetdist, int direction,int intensity);
};
