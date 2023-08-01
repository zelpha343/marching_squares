#include <stdio.h>
#include <raylib.h>

int main(void) {

	const int screenWidth = 960;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Marching Squares");

	SetTargetFPS(60);

	while(!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(BLACK);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
