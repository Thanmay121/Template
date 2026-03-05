#include "base.hpp"

void base::update()
{
	// Base class update logic (if any)
	dir = Vector2Normalize(dir);
	vel.y += gravity * GetFrameTime();
	vel = Vector2Scale(dir, speed);
	pos = Vector2Add(pos, Vector2Scale(vel, GetFrameTime()));
}

void base::draw()
{
	// Base class draw logic (if any)
}
