#pragma once
#include <raylib.h>
#include <raymath.h>
#include "animPlayer.hpp"
#include "sfx.hpp"

class base
{
public:
	Vector2 pos = { 0,0 };
	Vector2 vel = { 0,0 };
	Vector2 dir = { 0,0 }; // member can be max 1,min -1 (no checks)
	float speed = 0;
	float gravity = 0;
public:
	virtual void update() = 0;
	virtual void draw() = 0;
};


