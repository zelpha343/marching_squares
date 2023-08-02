#include <stdio.h>
#include <raylib.h>

#define FPS 60 
#define dt 0.01

Vector2 nextPosition(Vector2 currentPosition, Vector2 Velocity);
void collide(Vector2 ballPosition, Vector2 Velocity);

int main(void) {
	   
	const int screenWidth = 960;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Marching Squares");

	SetTargetFPS(FPS);

	Vector2 ballPosition = { (float) screenWidth/2, (float) screenHeight/2 };
	Vector2 Velocity = { 100, 100 };
	while(!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(BLACK);
		DrawCircleV(ballPosition, 50, PINK);
		ballPosition = nextPosition(ballPosition, Velocity);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}


Vector2 nextPosition(Vector2 currentPosition, Vector2 Velocity) {
		Vector2 nextPos = { (float) (currentPosition.x += Velocity.x * dt) , (float) (currentPosition.y += Velocity.y * dt) };
		return nextPos;
}


void collide(Vector2 ballPosition, Vector2 Velocity) {
	
}


