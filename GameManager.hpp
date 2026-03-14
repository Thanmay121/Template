#include "player.hpp"
#include "enemyBase.hpp"

enum gameState
{
	PlayerAlive,
	CONTRACT
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

