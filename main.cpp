#include "raylib.h"
#include <X11/Xlib.h>

typedef struct Pet {
	Texture sprite;
	Vector2 velocity;
} Pet;

int main(void)
{
	SetConfigFlags(FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_TOPMOST);
    InitWindow(64, 64, nullptr);
	Pet petSlime = (Pet){
		.sprite = LoadTexture("slimetemp.png"),
	};

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLANK);
			DrawTexture(petSlime.sprite, 0, 0, RAYWHITE);
        EndDrawing();

		SetWindowPosition(GetWindowPosition().x, GetWindowPosition().y + 1000 * GetFrameTime());

		if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			SetWindowPosition(GetMouseX() * (GetMonitorWidth(GetCurrentMonitor()) + GetWindowPosition().x), GetMouseY() * (GetMonitorHeight(GetCurrentMonitor()) + GetWindowPosition().y));
		}
    }

    CloseWindow();

    return 0;
}
