#pragma once
#include "Paddle.h"

class OtherPlayerPaddle :
    public Paddle
{
public:
    void HandleEvents(SDL_Event e) override;
};

