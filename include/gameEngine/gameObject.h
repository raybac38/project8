#include <raylib.h>

typedef struct GameObjectHandler * GameObject;

GameObject GameObjectInit(void);
void GameObjectExit(GameObject go);

void GameObjectSetMesh(GameObject go, Mesh new_mesh);
void GameObjectSetMaterial(GameObject go, Material new_material);
void GameObjectSetPosition(GameObject go, Vector3 new_position);
void GameObjectSetRotation(GameObject go, Vector3 new_rotation);
void GameObjectSetScale(GameObject go, Vector3 new_scale);

Mesh GameObjectGetMesh(GameObject go);
Material GameObjectGetMaterial(GameObject go);
Vector3 GameObjectGetPosition(GameObject go);
Vector3 GameObjectGetRotation(GameObject go);
Vector3 GameObjectGetScale(GameObject go);

Matrix GameObjectGetTransformeMatrix(GameObject ob);