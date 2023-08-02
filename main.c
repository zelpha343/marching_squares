#include <stdio.h>
#include <raylib.h>

#define FPS 60 
#define dt 0.01
#define screenWidth 960
#define screenHeight 600


Vector2 nextPosition(Vector2 currentPosition, Vector2 Velocity);
void collide(Vector2 ballPosition, Vector2 *Velocity);

int main(void) {
	   
	InitWindow(screenWidth, screenHeight, "Marching Squares");

	SetTargetFPS(FPS);

	Vector2 ballPosition = { (float) screenWidth/2, (float) screenHeight/2 };
	Vector2 Velocity = { 100, 0 };
	while(!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(BLACK);
		DrawCircleV(ballPosition, 50, PINK);
		collide(ballPosition, &Velocity);
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


void collide(Vector2 ballPosition, Vector2 *Velocity) {
	if (ballPosition.x > screenWidth) {
		Velocity->x = -Velocity->x;
	}
}


