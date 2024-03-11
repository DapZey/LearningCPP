#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player {
public:
    Player(float x, float y, int width, int height, Color color);

    void Draw();

    // Getters and setters
    float getX() const;
    void setX(float newX);
    float getY() const;
    void setY(float newY);

private:
    float x;
    float y;
    int width;
    int height;
    Color color;
};

#endif // PLAYER_H
