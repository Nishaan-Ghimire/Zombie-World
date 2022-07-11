#pragma once


class Enemy : public Character
{
protected:
    RectangleShape enemy;
    Texture enemyTexture;

    float posDiffx;
    float posDiffy;
    Vector2f enemySpeed = Vector2f(-1.0f, 0.0f);
    pos enemypositions[5] = {
        {23.0f,66.0f},
        {12.0f,89.0f},
        {333.0f,67.0f},
        {555.0f,444.0f},
        {111.0f,222.0f}
    };

public:
    Enemy();
    void updateEnemyPosition(Vector2f, Vector2f &,RectangleShape &);
    friend class Game;
};

Enemy ::Enemy() : enemy(Vector2f(100.0f, 100.0f))
{
    enemy.setPosition(Vector2f(100.0f, 100.0f));
    enemyTexture.loadFromFile(IMG_PATH "/enemy2Up.png");
    enemy.setTexture(&enemyTexture);
}

void Enemy ::updateEnemyPosition(Vector2f p, Vector2f &s,RectangleShape &e)
{
    posDiffx = e.getPosition().x - p.x;
    posDiffy = e.getPosition().y - p.y;
    // cout << " X Difference : " << posDiffx << endl;
    // cout << " Y Difference : " << posDiffy << endl;

    if (posDiffx >= 50)
    {
        s.x = -1.0f;
        s.y = 0.0f;
        enemyTexture.loadFromFile(IMG_PATH"/enemy2Left.png");
        e.setTexture(&enemyTexture);
    }
    else if (posDiffx <= -50)
    {
        s.x = 1.0f;
        s.y = 0.0f;
        enemyTexture.loadFromFile(IMG_PATH"/enemy2Right.png");
        e.setTexture(&enemyTexture);
    }
    else
    {
        if (posDiffy >= 50)
        {
            s.x = 0.0f;
            s.y = -1.0f;
            enemyTexture.loadFromFile(IMG_PATH"/enemy2Up.png");
            e.setTexture(&enemyTexture);
        }
        else if (posDiffy <= -50)
        {
            s.x = 0.0f;
            s.y = 1.0f;
            enemyTexture.loadFromFile(IMG_PATH"/enemy2Down.png");
            e.setTexture(&enemyTexture);
        }
        else
        {
            s.x = 0.0f;
            s.y = 0.0f;
        }
    }
}

class Enemies
{
protected:
    vector<Enemy> enemyGroup;
    int enemyspawnTimer = 0;
    int enemyShootTimer = 50;
    int enemySpawnNo;
    friend class Game;
    friend class Enemy;
};
