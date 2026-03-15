#include "player.hpp"
#include "enemyBase.hpp"
#include <string>


int WaveNo=0;
enum class gameState
{
	PlayerAlive,
    TRANSITIONING,
	CONTRACT
};
enum class  TASKS
{
	NONE=0,
    DEALDMG=1,
	NODMG=2,
    PARRYATTACKS=3,
    STAYREGION=4
};
enum class ContractStatus
{
    ON,
    OFF,
    NONE
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
        return("Deal 5K DMG IN 60sec");
        break;
    case TASKS::NODMG:
        return("TAKE NO DMG FOR 30sec");
        break;
    default:
        return "NONE";
        break; 
    }
}
void LOCKIN(TASKS t,float time,Player &player,std::vector<enemyBase> enemy,ContractStatus &status,int &dmg)
{
    switch (t)
    {
    case TASKS::DEALDMG:
    {
        if(!timer(30,time))
        {
            if(player.state==PlayerState::ATTAKING)
            {
                for(enemyBase &e:enemy)
                {
                    if(e.dmgtaken)
                    dmg+=player.attackStrength;
                    if(dmg>=500)
                    {
                        status=ContractStatus::ON;
                    }
                }

            }
        }
        if(dmg>=500)
        {
            status=ContractStatus::ON;
        }
        else
        status=ContractStatus::OFF;
        break;
    }
    case TASKS::NODMG:
        if(!timer(30,time))
        {
            if(player.hp==100)
            {
                status=ContractStatus::ON;
            }
            else
            {
                status=ContractStatus::OFF;
            }
        }
        break;

    default:
        break;
    }
}


