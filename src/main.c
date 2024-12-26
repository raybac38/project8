#include "./scene.h"
#include "./eventManager.h"
#include "./camera.h"
#include <raylib.h>
#include <stdio.h>

#define WINDOWS_HEIGHT 360
#define WINDOWS_WIDTH  640

#define WINDOWS_TITLE "Project 8"

Camera3D camera;

void CheckExit()
{
	if(WindowShouldClose())
	{
		printf("Windows should close\n");	
		CloseWindow();
		EventManagerExit();
	}
	EventManagerAddTask(CheckExit);
}

void UpdateWindow(void)
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	BeginMode3D(camera);
		DrawScene();
	EndMode3D();
	EndDrawing();
	EventManagerAddTask(UpdateWindow);
}

int main(int argc, char ** argv)
{
	InitWindow(WINDOWS_WIDTH, WINDOWS_HEIGHT, WINDOWS_TITLE);

	camera = InitCamera();
//	SetTargetFPS(60);

	EventManagerInit();

	EventManagerAddTask(UpdateWindow);
	EventManagerAddTask(CheckExit);

	EventManagerRuntime();

	return 0;
}
