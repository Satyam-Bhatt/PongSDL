#pragma once
#include "Paddle.h"
#include "Ball.h"

class AI_Paddle :
    public Paddle
{
    public:
        AI_Paddle() = default;
        AI_Paddle(int _posX, int _posY, int _width, int _height);

        void Update();
        void GetBallDirection(Ball* ball);


    private:

};

