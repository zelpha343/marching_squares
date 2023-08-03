#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>

#define FPS 60 
#define dt 0.01
#define screenWidth 960
#define screenHeight 600
#define RANDOM(min, max) ((min) + rand() % ((max) - (min) + 1))


typedef struct {
	Vector2 Position;
	Vector2 Velocity;
	float Radius;
} Ball;

void collision(Ball *ball);

int main(void) {
	srand(time(NULL));
	   
	InitWindow(screenWidth, screenHeight, "Marching Squares");

	SetTargetFPS(FPS);
	
	const int numberOfBalls = 10;
	Ball *balls = malloc(10* sizeof(Ball));
	for(size_t i = 0; i < numberOfBalls; i++) {
		balls[i].Position.x = RANDOM(0, screenWidth);
	    balls[i].Position.y = RANDOM(0, screenHeight);
		balls[i].Velocity.x = RANDOM(10, 100);
		balls[i].Velocity.y = RANDOM(10, 100);
		balls[i].Radius = RANDOM(20, 50);
	}
	
	while(!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(BLACK);
		for(size_t i = 0; i < numberOfBalls; i++) {
			balls[i].Position.x += balls[i].Velocity.x*dt;
			balls[i].Position.y += balls[i].Velocity.y*dt;
			collision(&balls[i]);
			DrawCircleV(balls[i].Position, balls[i].Radius, PINK);
		}
		EndDrawing();
	}

	CloseWindow();

	return 0;
}

void collision(Ball *ball) {
	if(ball->Position.x+ball->Radius > screenWidth || ball->Position.x-ball->Radius < 0){
		ball->Velocity.x = -ball->Velocity.x;
	}

	if(ball->Position.y+ball->Radius > screenHeight || ball->Position.y-ball->Radius < 0){
		ball->Velocity.y = -ball->Velocity.y;
	}
}
