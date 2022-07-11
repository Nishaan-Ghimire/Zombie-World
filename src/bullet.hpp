#pragma once
#include "header.hpp"

class Bullet;

class Bullets
{
protected:
    vector<Bullet> ammunations;
    // vector<Bullet> enemyammunations;

    Vector2f bulletOrigin;
    //  Vector2f enemyBulletOrigin;
    // int enemyshootTimer = 0;
    int shootTimer = 0;
    friend class Game;
    friend class Bullet;
};




class Bullet
{
protected:
    // Bullet damage rate
    float damage = 20;
    // Bullet speed
    Vector2f speed = Vector2f(10.0f, 10.0f);
    //used or unused flag
    bool fired = false;
        

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
    void changeDirection(Direction,RectangleShape &,Vector2f &);
    Vector2f getPosition();
    friend class Game;
};





Bullet ::Bullet() : bullet(Vector2f(25.0f, 20.0f))
{
    position.x = 200.0f;
    position.y = 200.0f;
    bullet.setPosition(position.x, position.y);
    bulletTexture.loadFromFile(IMG_PATH "/bullet.png");
    bullet.setTexture(&bulletTexture);
}


void Bullet ::changeDirection(Direction playerDirection, RectangleShape & R, Vector2f & s)
{
 
    
        switch (playerDirection)
        {
        case Left:
            s.x = -10.0f;
            s.y = 0.0f;
            R.setRotation(-90);
            break;
        case Up:
            s.x = 0.0f;
            s.y = -10.0f;
            R.setRotation(0);
            break;
        case Down:
            s.x = 0.0f;
            s.y = 10.0f;
            R.setRotation(180);
            break;
        case Right:
            s.x = 10.0f;
            s.y = 0.0f;
            R.setRotation(90);
            break;
        }
   
}



Vector2f Bullet ::getPosition()
{
    return bullet.getPosition();
}
