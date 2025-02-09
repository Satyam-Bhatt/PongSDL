#pragma once
#include "Paddle.h"

class OtherPlayerPaddle :
    public Paddle
{
public:
    OtherPlayerPaddle(int _posX = 0, int _posY = 0, int _width = 0, int _height = 0);
    void HandleEvents(SDL_Event e) override;
};

