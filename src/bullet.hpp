#pragma once
#include "header.hpp"

class Bullet
{
protected:
    // Bullet damage rate
    float damage = 20;
    // Bullet speed
    Vector2f speed = Vector2f(10.0f, 10.0f);

    // Bullet position
    struct bulletPos
    {
        float x;
        float y;
    } position;

    RectangleShape bullet;
    Texture bulletTexture;

public:
    Bullet();
    void changeDirection(Direction);
    Vector2f getPosition();
    friend class Game;
};

Bullet ::Bullet() : bullet(Vector2f(40.0f, 30.0f))
{
    position.x = 200.0f;
    position.y = 200.0f;
    bullet.setPosition(position.x, position.y);
    bulletTexture.loadFromFile(IMG_PATH "/bullet.png");
    bullet.setTexture(&bulletTexture);
}

void Bullet ::changeDirection(Direction playerDirection)
{
    
    switch (playerDirection)
    {
    case Left:
    speed.x = -10.0f;
    speed.y = 0.0f;
    bullet.setRotation(-90);
        break;
    case Up:
    speed.x = 0.0f;
    speed.y = -10.0f;
    bullet.setRotation(0);
        break;
    case Down:
    speed.x = 0.0f;
    speed.y = 10.0f;
    bullet.setRotation(180);
        break;
    case Right:
    speed.x = 10.0f;
    speed.y = 0.0f;
    bullet.setRotation(90);
        break;
    }
}

Vector2f Bullet ::getPosition()
{
    return bullet.getPosition();
}

class Bullets
{
protected:
    vector<RectangleShape> ammunations;

    Vector2f bulletOrigin;
    int shootTimer = 0;
    friend class Game;
};