#include "gameEngine/gameObject.h"

typedef struct Scene * Scene;

Scene SceneInit(void);
void SceneExit(Scene scene);

void SceneAdd(Scene scene,GameObject ob);
void SceneRemove(Scene scene, GameObject ob);
int SceneNumberOfGameObject(Scene scene);

void SceneDrawGameObjects(Scene scene);

//depracated
void DrawScene(void);