#pragma once
#include <raylib.h>

void dia(const char* text, float offset, float duration, int typespeed, int &charCount, int &textTimer, bool &isDialogueActive)
{
    int textLength = TextLength(text);

    // 1. The Typewriter Math
    if (charCount < textLength) 
    {
        textTimer++;
        if (textTimer >= typespeed)
        {
            charCount++;
            textTimer = 0;  
        }
    }
    if (IsKeyPressed(KEY_ENTER))
    {
        if (charCount < textLength)
        {
            // Skip to end
            charCount = textLength; 
        }
        else
        {
            // Close the box
            isDialogueActive = false; 
        }
    }
}