// Scene

#include <raylib.h>

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
