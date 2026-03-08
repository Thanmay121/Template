#pragma once
#include<raylib.h>
float lastplayed = 0;
void playersound(Sound s)
{
    if (lastplayed+6<=GetTime())
	{
        PlaySound(s);
        lastplayed = GetTime();
	}
}
    