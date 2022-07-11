#pragma once
#include "header.hpp"

class Player : public Character
{
protected:
    // Required variables & objects
const pos originalPos = {0,580};
    pos davePos = {0, 580};
// player life
   int playerlife = 100;
    float daveLifesize = 100.0f;
    // player required object
    RectangleShape dave;
    RectangleShape davelife;
    Texture daveTexture;
    Direction playerDirection = Right;

public:
    // constructor and functions
    Player();
    void updatePlayerposition();

    friend class Game;
};

// Initializing player object and loading player texture and setting player position in constructor
Player::Player() : dave(Vector2f(100.0f, 100.0f)), davelife(Vector2f(daveLifesize,10.0f))
{
    dave.setPosition(Vector2f(1.0f * davePos.x, 1.0f * davePos.y));
    davelife.setPosition(Vector2f(dave.getPosition().x,dave.getPosition().y-davelife.getSize().y));
    davelife.setFillColor(Color::Red);
    daveTexture.loadFromFile(IMG_PATH "/dave.png");
    dave.setTexture(&daveTexture);
}

// function for managing and updating player position and rotation
void Player::updatePlayerposition()
{
    if (Keyboard::isKeyPressed(Keyboard::Key::A) || Keyboard::isKeyPressed(Keyboard::Left))
    {

        if ((dave.getPosition().x <= 0))
        {
            dave.move(0.0f, 0.0f);
            davelife.move(0.0f, 0.0f);
        }
        else
        {
            dave.move(-playerspeed, 0.f);
            davelife.move(-playerspeed, 0.f);
        }
        // dave.setRotation(-90);
        daveTexture.loadFromFile(IMG_PATH "/daveLeft.png");
        playerDirection = Left;
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::D)  || Keyboard::isKeyPressed(Keyboard::Right))
    {
        if ((dave.getPosition().x >= 720 - dave.getSize().x))
        {
            dave.move(0.0f, 0.0f);
            davelife.move(0.0f, 0.0f);
        }
        else
        {

            dave.move(playerspeed, 0.f);
            davelife.move(playerspeed, 0.f);
        }
        // dave.setRotation(90);
        daveTexture.loadFromFile(IMG_PATH "/dave.png");
        playerDirection = Right;
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::W) || Keyboard::isKeyPressed(Keyboard::Up))
    {
        if ((dave.getPosition().y <= 0))
        {
            dave.move(0.0f, 0.0f);
            davelife.move(0.0f, 0.0f);
        }
        else
        {
            dave.move(0.f, -playerspeed);
            davelife.move(0.f, -playerspeed);
        }

        // dave.setRotation(0);
        daveTexture.loadFromFile(IMG_PATH "/daveUp.png");
        playerDirection = Up;
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::S) || Keyboard::isKeyPressed(Keyboard::Down))
    {
        if ((dave.getPosition().y >= 720 - dave.getSize().y))
        {
            dave.move(0.0f, 0.0f);
            davelife.move(0.0f, 0.0f);
        }
        else
        {
            dave.move(0.f, playerspeed);
            davelife.move(0.f, playerspeed);
        }
        // dave.setRotation(180);
        daveTexture.loadFromFile(IMG_PATH "/daveDown.png");
        playerDirection = Down;
    }
}