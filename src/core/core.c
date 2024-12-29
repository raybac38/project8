#include <stdio.h>

#include "gameEngine/eventManager.h"
#include "gameEngine/sceneManager.h"
#include "gameEngine/scene.h"
#include "gameEngine/gameObject.h"

// Entry point of the game

void CoreUpdate(void);
void StateUpdate(int state);

GameObject go;
Material mat;
Scene scene;

void CoreInit()
{   
    go = GameObjectInit();
    scene = SceneInit();
    SceneManagerSetScene(scene);

    GameObjectSetMesh(go, GenMeshCube(1, 1, 1));
    GameObjectSetMaterial(go, LoadMaterialDefault());
    StateUpdate(0);
    SceneAdd(scene, go);

    EventManagerAddTask(CoreUpdate);
}

void StateUpdate(int state)
{
    switch (state)
    {
    case 0:
        GameObjectSetPosition(go, (Vector3){1, 0, 0});
        break;
    case 1:
        GameObjectSetPosition(go, (Vector3){1, 1, 0});
        break;
    case 2:
        GameObjectSetPosition(go, (Vector3){0, 1, 0});
        break;
    case 3:
        GameObjectSetPosition(go, (Vector3){0, 0, 0});
        break;
    default:
        break;
    }
}

static int state = 0;
static int state_max = 3;
static int count = 0;
static int count_max = 20;

void CoreUpdate()
{
    count ++;
    if(count > count_max)
    {
        count = 0;
        state++;
        if(state > state_max)
        {
            state = 0;
        }
        StateUpdate(state);

    }
    EventManagerAddTask(CoreUpdate);
}