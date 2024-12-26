#include "./scene.h"
#include "./camera.h"
#include <raylib.h>

#define WINDOWS_HEIGHT 360
#define WINDOWS_WIDTH  640

#define WINDOWS_TITLE "Project 8"

int main(int argc, char ** argv)
{
	InitWindow(WINDOWS_WIDTH, WINDOWS_HEIGHT, WINDOWS_TITLE);

	Camera3D camera = InitCamera();
	SetTargetFPS(60);

	while(!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode3D(camera);
			DrawScene();
		EndMode3D();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
