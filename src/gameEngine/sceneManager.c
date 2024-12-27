#include <stdio.h>
#include <raylib.h>
#include "./gameEngine/scene.h"
#include "./gameEngine/eventManager.h"
#include "./gameEngine/camera.h"

Camera camera;

void SceneManagerUpdate()
{
    BeginDrawing();
	ClearBackground(RAYWHITE);
	BeginMode3D(camera);
		DrawScene();
	EndMode3D();
	EndDrawing();
	EventManagerAddTask(SceneManagerUpdate);
}


void SceneManagerExit(void)
{
    //  Exit
}

void SceneManagerInit(void)
{
    EventManagerAddTask(SceneManagerUpdate);
    EventManagerAddExitTask(SceneManagerExit);
    camera = InitCamera();
    SetTargetFPS(60);
}
