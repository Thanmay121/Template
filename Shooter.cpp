#pragma once
#include "enemyBase.hpp"
#include "player.hpp"
#include <raymath.h>
#include "Shooter.hpp"
void Shooter::lockon(Player &player)
{
	Vector2 dir = Vector2Subtract(player.pos, this->pos);
	float distance = Vector2Length(dir);
	if (distance >350.0f && distance< 1000.0f)
	{
		this->dir=dir;
        this->state = EnemyState::RUNNING;
	}
	else
    {
        this->state = EnemyState::IDLE;
    }

}