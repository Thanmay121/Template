#include "player.hpp"
#include "enemyBase.hpp"
#include <string>

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
	NODMG=2
};

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
        return "sad";
        break;
    }
}
void LOCKIN(TASKS t)
{
    switch (t)
    {
    case TASKS::DEALDMG:
        /* code */
        break;
    case TASKS::NODMG:
        break;

    default:
        break;
    }
}

