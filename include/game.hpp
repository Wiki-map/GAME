#pragma once

#include <cstdint>
#include "raylib.h"
#include "entities/player.hpp"

class Game {
public:
	void run();
private:

	const int32_t WindowHeight = 720;
	const int32_t WindowWidth = 1280;
	const char* Title = "hi";
	const int32_t TicksPerSeconds = 60;
	
	const int32_t RenderHeight = 144;
	const int32_t RenderWidth = 256;

	float tickTime;

	RenderTexture2D target;

	Player player;

	void Init();
	void Update(float dt);
	void Tick();
	void Draw();
};