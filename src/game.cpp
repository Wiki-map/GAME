#include "game.hpp"
#include "raylib.h"
#include <print>

void Game::Init() {
	InitWindow(WindowWidth, WindowHeight, Title);
	tickTime = 0;

	target = LoadRenderTexture(RenderWidth, RenderHeight);

	player = Player(100, 100);
}

void Game::Tick() {
	player.Update();
}

void Game::Draw() {
	ClearBackground(SKYBLUE);
	player.Draw();
}

void Game::Update(float dt) {
	tickTime += dt;
	if (tickTime > 1 / (float)TicksPerSeconds) {
		tickTime -= 1 / (float)TicksPerSeconds;
		Tick();
	}

	if (IsKeyPressed(KEY_F11)) {
		if (IsWindowFullscreen())
		{
			SetWindowSize(WindowWidth, WindowHeight);
		}
		else
		{
			SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
		}
		ToggleFullscreen();
	}
}

static Vector3 GetRenderTextureRenderInfo(Vector2 window, Vector2 target) {
	float scale;
	Vector2 position;

	if (window.x < window.y) {
		scale = window.x / target.x;
		position = { 0, window.y / 2 - target.y * scale / 2 };
	}
	else {
		scale = window.y / target.y;
		position = { window.x / 2 - target.x * scale / 2, 0 };
	}

	return { position.x, position.y, scale };
}

void Game::run() {
	Init();
	while (!WindowShouldClose()) {
		Update(GetFrameTime());


		BeginTextureMode(target);
		{
			Draw();
		}
		EndTextureMode();

		BeginDrawing();
		{
			ClearBackground(BLACK);
			Vector3 RenderInfo = GetRenderTextureRenderInfo({ (float)GetScreenWidth(),(float)GetScreenHeight() }, { (float)RenderWidth,(float)RenderHeight });
			DrawTexturePro(target.texture, { 0,0,256,144*-1 }, {RenderInfo.x,RenderInfo.y,256*RenderInfo.z + RenderInfo.x, 144*RenderInfo.z + RenderInfo.y},{0,0},0, WHITE);
		}
		EndDrawing();
	}
}