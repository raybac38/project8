#include <stdio.h>
#include <raylib.h>
#include "gameEngine/sceneManager.h"
#include "gameEngine/gameObject.h"
#include "gameEngine/eventManager.h"
#include "gameEngine/camera.h"

static Scene current_scene;
static Camera camera;

void SceneManagerSetScene(Scene scene)
{
    current_scene = scene;
}

void SceneManagerUpdate()
{
    BeginDrawing();
	ClearBackground(DARKGRAY);
	BeginMode3D(camera);
        SceneDrawGameObjects(current_scene);
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
    current_scene = SceneInit();
    camera = InitCamera();
    SetTargetFPS(60);

    EventManagerAddTask(SceneManagerUpdate);
    EventManagerAddExitTask(SceneManagerExit);
}
