#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>

#include "gameEngine/gameObject.h"

struct GameObjectHandler
{
    Mesh mesh;
    Material material;
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
};

GameObject GameObjectInit(void)
{
    struct GameObjectHandler * gameObject = malloc(sizeof(struct GameObjectHandler));
    gameObject->position = (Vector3){0,0,0};
    gameObject->rotation = (Vector3){0,0,0};
    gameObject->scale = (Vector3){1,1,1};
    return gameObject;
}

void GameObjectExit(GameObject go)
{
    UnloadMaterial(go->material);
    UnloadMesh(go->mesh);
    free(go);
}

void GameObjectSetMesh(GameObject go, Mesh new_mesh)
{
    go->mesh = new_mesh;
    UploadMesh(&(go->mesh), false); 
}
void GameObjectSetMaterial(GameObject go, Material new_material)
{
    go->material = new_material;
}
void GameObjectSetPosition(GameObject go, Vector3 new_position)
{
    go->position = new_position;
}
void GameObjectSetRotation(GameObject go, Vector3 new_rotation)
{
    go->rotation = new_rotation;
}
void GameObjectSetScale(GameObject go, Vector3 new_scale)
{
    go->scale = new_scale;
}


Mesh GameObjectGetMesh(GameObject go)
{
   return go->mesh; 
}
Material GameObjectGetMaterial(GameObject go)
{
    return go->material;
}
Vector3 GameObjectGetPosition(GameObject go)
{
    return go->position;
}
Vector3 GameObjectGetRotation(GameObject go)
{
    return go->rotation;
}
Vector3 GameObjectGetScale(GameObject go)
{
    return go->scale;
}

Matrix GameObjectGetTransformeMatrix(GameObject ob)
{
    Matrix translation = MatrixTranslate(ob->position.x, ob->position.y, ob->position.z);

    Matrix rotationX = MatrixRotateX(ob->rotation.x); 
    Matrix rotationY = MatrixRotateY(ob->rotation.y); 
    Matrix rotationZ = MatrixRotateZ(ob->rotation.z); 

    Matrix rotationMatrix = MatrixMultiply(MatrixMultiply(rotationZ, rotationY), rotationX);

    Matrix scaling = MatrixScale(ob->scale.x, ob->scale.y, ob->scale.z);

    Matrix transform = MatrixMultiply(MatrixMultiply(scaling, rotationMatrix), translation);
    return transform;    
}
