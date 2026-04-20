#include "gameover.hpp"
#include <raylib.h>

bool DrawCenteredButton(Rectangle bounds, const char* text)
{
    Vector2 mouse = GetMousePosition();
    bool hovered = CheckCollisionPointRec(mouse, bounds);
    bool clicked = hovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

    DrawRectangleRec(bounds, hovered ? DARKGRAY : GRAY);
    DrawRectangleLinesEx(bounds, 2, hovered ? WHITE : LIGHTGRAY);

    int fontSize = 30;
    int textWidth = MeasureText(text, fontSize);
    DrawText(text,(int)(bounds.x + (bounds.width - textWidth) / 2),
    (int)(bounds.y + (bounds.height - fontSize) / 2),fontSize,WHITE);

    return clicked;
}

GameOverAction DrawGameOverScreen(int screenWidth, int screenHeight)
{
    DrawText("GAME OVER",       
             screenWidth / 2 - MeasureText("GAME OVER", 90) / 2,
             100,
             90,
             RED);

    DrawText("Choose what to do next",
             screenWidth / 2 - MeasureText("Choose what to do next", 30) / 2,
             220,
             30,
             LIGHTGRAY);

    Rectangle retryBtn = {(float)screenWidth / 2 - 260, (float)screenHeight / 2 - 40, 520, 90};
    Rectangle quitBtn = {(float)screenWidth / 2 - 260, (float)screenHeight / 2 + 70, 520, 90};

    if (DrawCenteredButton(retryBtn, "RETRY"))
    {
        return GameOverAction::RETRY;
    }
    if (DrawCenteredButton(quitBtn, "QUIT"))
    {
        return GameOverAction::QUIT;
    }

    return GameOverAction::NONE;
}
