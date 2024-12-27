#include <raylib.h>

Camera InitCamera()
{
    Camera3D camera = {0};
    camera.position = (Vector3){10, 10, 10};
    camera.target = (Vector3){0, 0, 0};
    camera.up = (Vector3){0, 0, 1};
    camera.fovy = 45.0;
    camera.projection = CAMERA_PERSPECTIVE;

    return camera;
}