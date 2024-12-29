// Scene
#include <raylib.h>
#include <stdlib.h>

#include "gameEngine/scene.h"

#define SCENE_MAX_GAMEOBJECT 1024

struct Scene
{
	GameObject * gameObjects;
	GameObject * last_gameObject;
	int gameObject_count;
};

int SceneNumberOfGameObject(Scene scene)
{
	return scene->gameObject_count;
}

Scene SceneInit()
{
	struct Scene * scene = malloc(sizeof(struct Scene));
	scene->gameObjects = malloc(sizeof(GameObject) * SCENE_MAX_GAMEOBJECT);
	scene->last_gameObject = scene->gameObjects;
	scene->gameObject_count = 0;
	return scene;
}

void SceneExit(Scene scene)
{
	int countdown = scene->last_gameObject - scene->gameObjects;
	while(countdown)
	{
		GameObjectExit(*scene->last_gameObject--);
		free(scene);
	}
}

void SceneAdd(Scene scene, GameObject ob)
{
	*(scene->last_gameObject)++ = ob;
	scene->gameObject_count++;
}

void SceneRemove(Scene scene, GameObject ob)
{
	GameObject * ob_ptr = scene->gameObjects;
	while(*ob_ptr != ob)
	{
		ob_ptr++;
	}
	if(*ob_ptr != *scene->last_gameObject)
	{
		*ob_ptr = *scene->last_gameObject;
	}
	scene->last_gameObject--;
	scene->gameObject_count--;
}

void SceneDrawGameObjects(Scene scene)
{
	for (int i = 0; i < SceneNumberOfGameObject(scene); i++)
	{
		GameObject go = scene->gameObjects[i];
		Matrix transform = GameObjectGetTransformeMatrix(go);
		Material material = GameObjectGetMaterial(go);
		Mesh mesh = GameObjectGetMesh(go);
		DrawMesh(mesh, material, transform);
	}
}

//deplacated
void DrawScene()
{
	int radius = 5;
	for(int i = -radius; i <= radius; i++)
	{
		for(int j = -radius; j <= radius; j++)
		{
			Vector3 position = {i, j, 0};
			Vector2 size = {0.5, 0.5};
			Color color = LIGHTGRAY;
			DrawPlane(position, size, color);
		}

	}
}
