#pragma once

#include <cstdint>
#include "raylib.h"

class Player {
public:
	Player() = default;
	Player(int32_t x, int32_t y);
	void Update();
	void Draw();
private:
	Vector2 position;
	Vector2 velocity;
};