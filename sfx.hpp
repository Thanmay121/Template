#pragma once
#include<raylib.h>


class SOUND{
    public: 
        float lastplayed = -100;
        void playsoundinfi(Sound s,int duration);
        void playsoundfi(Sound s,int duration);
        void stopsound(Sound s);
};

