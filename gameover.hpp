#pragma once

enum class GameOverAction
{
    NONE,
    RETRY,
    QUIT
};

GameOverAction DrawGameOverScreen(int screenWidth, int screenHeight);
