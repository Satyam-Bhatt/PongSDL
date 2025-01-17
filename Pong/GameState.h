#pragma once
class GameState
{
public: 
	virtual void start() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void handleInput() = 0;
	virtual void exit() = 0;
};

