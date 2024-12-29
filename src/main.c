#include "./gameEngine/eventManager.h"
#include "./gameEngine/sceneManager.h"
#include "core/core.h"
#include <raylib.h>
#include <stdio.h>

#define WINDOWS_HEIGHT 360
#define WINDOWS_WIDTH  640

#define WINDOWS_TITLE "Project 8"

void CheckExit()
{
	if(WindowShouldClose())
	{
		CloseWindow();
		EventManagerExit();
	}
	EventManagerAddTask(CheckExit);
}

int main(int argc, char ** argv)
{
	InitWindow(WINDOWS_WIDTH, WINDOWS_HEIGHT, WINDOWS_TITLE);

	EventManagerInit();
	SceneManagerInit();

	EventManagerAddTask(CheckExit);
	EventManagerAddTask(CoreInit);

	EventManagerRuntime();

	return 0;
}
