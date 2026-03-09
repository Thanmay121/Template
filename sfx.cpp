#include "sfx.hpp"

void SOUND::playsoundinfi(Sound s , int duration)
{
    if (!IsSoundPlaying(s))
    {
        PlaySound(s);
    }   
}
void SOUND::playsoundfi(Sound s , int duration)
{
    if (!IsSoundPlaying(s))
    {
        PlaySound(s);;
    }
}
void SOUND::stopsound(Sound s)
{
    StopSound(s);
}
    