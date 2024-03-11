#include "Player.h"

Player::Player(float x, float y, int width, int height, Color color)
        : x(x), y(y), width(width), height(height), color(color) {}

void Player::Draw() {
    DrawRectangle(x, y, width, height, color);
}

float Player::getX() const {
    return x;
}

void Player::setX(float newX) {
    x = newX;
}

float Player::getY() const {
    return y;
}

void Player::setY(float newY) {
    y = newY;
}
