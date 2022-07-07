#pragma once
#include "header.hpp"



class Player:public Character{
    protected:
    // Required variables & objects  
 
    pos davePos = {0,580};


    // player direction
  
    //player required object
     RectangleShape dave;
     Texture daveTexture;
     Direction playerDirection = Right;
    
    public:

    //constructor and functions
    Player();
    void updatePlayerposition();

    friend class Game;
};

// Initializing player object and loading player texture and setting player position in constructor
Player::Player() : dave(Vector2f(70.0f,70.0f))
{
dave.setPosition(Vector2f(1.0f*davePos.x,1.0f*davePos.y));
daveTexture.loadFromFile(IMG_PATH"/dave.png");
dave.setTexture(&daveTexture);
}

// function for managing and updating player position and rotation
void Player:: updatePlayerposition(){
    if(Keyboard::isKeyPressed(Keyboard::Key::A))
{
dave.move(-playerspeed,0.f);
dave.setRotation(-90);
playerDirection = Left;

}
if(Keyboard::isKeyPressed(Keyboard::Key::D))
{
dave.move(playerspeed,0.f);
dave.setRotation(90);
playerDirection = Right;
}
if(Keyboard::isKeyPressed(Keyboard::Key::W))
{
dave.move(0.f,-playerspeed);
dave.setRotation(0);
playerDirection = Up;

}
if(Keyboard::isKeyPressed(Keyboard::Key::S))
{
    
dave.move(0.f,playerspeed);
dave.setRotation(180);
playerDirection = Down;
  
}

}