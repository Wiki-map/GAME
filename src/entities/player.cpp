#include "entities/player.hpp"
#include <print>

Player::Player(int32_t x, int32_t y) {
	position = { 0 };
	velocity = { 0 };
}

void Player::Update() {
    position.x += velocity.x;
    position.y += velocity.y;

    float GRAVITY = 0.7;
    velocity.y += GRAVITY;

    if (position.y + 16 > 144) {
        position.y = 144 - 16;
        velocity.y = 0;
    }

    float SPEED = 1.7;

    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        velocity.x += SPEED;
    }

    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        velocity.x -= SPEED;
    }

    float dragconstant = 0.3;
    velocity.x -= velocity.x * dragconstant;

    float jumpForce = 10;

    if (IsKeyPressed(KEY_SPACE)) {
        velocity.y -= jumpForce;
    }

    std::println("[{},{}]", velocity.x, velocity.y);
}

void Player::Draw() {
	DrawRectangleV(position, { 16.0,16.0 }, WHITE);
}