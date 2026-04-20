#pragma once
#include "enemyBase.hpp"
class Shooter: public enemyBase 
{
public:

    Shooter(Texture2D tex, int frameCount, float animTime, Vector2 pos, float speed);
    void lockon(Player &player); 
};