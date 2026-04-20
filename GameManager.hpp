#pragma once
#include "player.hpp"
#include "enemyBase.hpp"
#include <string>

enum class gameState
{
	PlayerAlive,
    TRANSITIONING,
    CONTRACT,
    GAME_OVER
};
enum class  TASKS
{
	NONE=0,
    DEALDMG=1,
	NODMG=2
};
enum class ContractStatus
{
    ON,
    OFF,
    NONE,
    FAILED
};
enum class BUFFS
{
    NONE=0,

};
bool timer(float x, float start)
{
    return GetTime() - start >= x;
}
bool GameButton(Rectangle bounds, const char* text)
{
    Vector2 mouse = GetMousePosition();
    bool hovered = CheckCollisionPointRec(mouse, bounds);
    bool clicked = hovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

    // Background
    DrawRectangleRec(bounds, hovered ? DARKGRAY : GRAY);

    // Border
    DrawRectangleLinesEx(bounds, 2, hovered ? WHITE : LIGHTGRAY);

    // Centered text
    int fontSize = 20;
    int textWidth = MeasureText(text, fontSize);
    DrawText(text,
        bounds.x + (bounds.width - textWidth) / 2,
        bounds.y + (bounds.height - fontSize) / 2,
        fontSize, WHITE);

    return clicked;
}

std::string toText(TASKS t)
{
    switch (t)
    {
    case TASKS::DEALDMG:
        return("Deal 500 DMG in 60 seconds");
        break;
    case TASKS::NODMG:
        return("TAKE NO DMG for 30 seconds");
        break;
    default:
        return "NONE";
        break; 
    }
}
bool buffapplied=false;
int dmg=0;
TASKS activeTask = TASKS::NONE;
float hpAtTaskStart = 0.0f;
void LOCKIN(TASKS t,float time,Player &player,ContractStatus &status,enemyBase &enemy)
{
    if (t == TASKS::NONE)
    {
        activeTask = TASKS::NONE;
        dmg = 0;
        buffapplied = false;
        status = ContractStatus::NONE;
        return;
    }
    else if (t != activeTask)   
    {
        activeTask = t;
        dmg = 0;
        hpAtTaskStart = player.hp;
        buffapplied = false;
        status = ContractStatus::ON;
    }

    switch (t)
    {
    case TASKS::DEALDMG:
    {
        const float duration = 60.0f;
        if (!timer(duration, time))
        {
            if (player.state == PlayerState::ATTAKING && enemy.hitTaken)
            {
                dmg += static_cast<int>(player.attackStrength);
            }

            status = (dmg >= 500) ? ContractStatus::ON : ContractStatus::ON;
        }
        else
        {
            status = (dmg >= 500) ? ContractStatus::NONE : ContractStatus::FAILED;
            if(status == ContractStatus::NONE && buffapplied==false)
            {
                player.attackStrength *= 1.2f;
                buffapplied=true;
            }
        }
        break;
    }
    case TASKS::NODMG:
            if (player.hp < hpAtTaskStart)
            {
                status = ContractStatus::FAILED;
            }
            else if (timer(30.0f, time))
            {
                status = ContractStatus::NONE;
                if(buffapplied==false)
                {
                    player.hp *= 1.2f;
                    buffapplied=true;
                }
            }
            else
            {
                status = ContractStatus::ON;
            }
            break;

    default:
        break;
    }
}


