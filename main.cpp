#include "raylib.h"
#include "Player.h"
#include "GameTimer.h"
#include <cmath>

struct vector2 {
    float x;
    float y;
};

// Function to calculate the magnitude of a Vector2
float magnitude(const vector2& vec) {
    return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}

// Function to normalize a Vector2
vector2 normalize(const vector2& vec) {
    float mag = magnitude(vec);
    // Check if the magnitude is not zero to avoid division by zero
    if (mag != 0.0f) {
        return {vec.x / mag, vec.y / mag};
    } else {
        // If the magnitude is zero, return a zero vector or handle it as appropriate for your use case
        return {0.0f, 0.0f};
    }
}

float lerp(float a, float b, float t) {
    return (1.0f - t) * a + t * b;
}

inline float clamp(float value, float minVal, float maxVal) {
    if (value < minVal) {
        return minVal;
    } else if (value > maxVal) {
        return maxVal;
    } else {
        return value;
    }
}

int main(void) {

    const float screenWidth = 1920;
    const float screenHeight = 1080;
    const float playerMoveSpeed = 300.0f;

    InitWindow(screenWidth, screenHeight, "Player Class Example");
//     SetWindowState(FLAG_FULLSCREEN_MODE);

    Player player(screenWidth / 2 - 25, screenHeight / 2 - 25, 50, 50, BLUE);
    Camera2D camera = { 0 };
    camera.target = { screenWidth / 2 - 25, screenHeight / 2 - 25 };
    camera.offset = (Vector2){ screenWidth / 2, screenHeight / 2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    GameTimer gameTimer;
//    SetTargetFPS(144);

    while (!WindowShouldClose()) {
        float deltaTime = gameTimer.run();
        vector2 playerPos = { 0, 0 };

        if (IsKeyDown(KEY_A)) playerPos.x -= 1.0f;
        if (IsKeyDown(KEY_D)) playerPos.x += 1.0f;
        if (IsKeyDown(KEY_W)) playerPos.y -= 1.0f;
        if (IsKeyDown(KEY_S)) playerPos.y += 1.0f;


        playerPos = normalize(playerPos);

        // Update player position based on input
        player.setX(player.getX() + playerPos.x * playerMoveSpeed * deltaTime);
        player.setY(player.getY() + playerPos.y * playerMoveSpeed * deltaTime);


            camera.target.x = int(player.getX());
            camera.target.y = int(player.getY());
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode2D(camera);
        DrawText(TextFormat("Delta time: %f", deltaTime), 10, 10, 20, LIGHTGRAY);
        DrawText(TextFormat("FPS: %i", gameTimer.fps), 10, 40, 20, LIGHTGRAY);
        // Draw game objects
        player.Draw();
        EndMode2D();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}


