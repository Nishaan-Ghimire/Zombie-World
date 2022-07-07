#include "header.hpp"
#include "player.hpp"
#include "bullet.hpp"
class Game
{
private:  
    int tilePosX = 0;
    int tilePosY = 0;
    // Creating a sturucture array for storing positions of obstacles
    struct obstacle{
        float x;
        float y;
    } obstaclePos[5] = {
        {20,20},
        {336,442},
        {20,20},
        {20,20},
        {20,20}};
    // Iitializing the required objects
    RenderWindow window;
    RectangleShape background;
    RectangleShape Rock;
    RectangleShape Bush;
    Texture backgroundTexture;
    Texture rockTexture;
    Texture bushTexture;
    Player player;
    Bullet bulletObj;
    Bullets BulletPack;
  
//Declaring the required game rendering and updating functions   
    void processEvents();
    void update();
    void render();

public:
    Game();
    void run();
};


// Initializing Game object with neccessary texture and setting up their size and position
Game::Game() : window(VideoMode(720, 720), "Adventure Game"), background(Vector2f(20.0f, 20.0f)),
               Rock(Vector2f(200.0f, 200.0f)),Bush(Vector2f(250.0f,200.0f))

{
 
    backgroundTexture.loadFromFile(IMG_PATH"/grassold.jpg");
    background.setTexture(&backgroundTexture);
    rockTexture.loadFromFile(IMG_PATH"/rock.png");
    Rock.setTexture(&rockTexture);
    Rock.setPosition(Vector2f(1.0f*obstaclePos[0].x, 1.0f*obstaclePos[0].y));
    bushTexture.loadFromFile(IMG_PATH"/bush.png");
    Bush.setTexture(&bushTexture);
    Bush.setPosition(Vector2f(1.0f*obstaclePos[1].x, 1.0f*obstaclePos[1].y));
};

//function for starting all action
void Game::run()
{
    while (window.isOpen())
    {
window.setFramerateLimit(60);
        processEvents();
        render();
        update();
    }
}

//function for checking window close events
void Game::processEvents()
{
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            window.close();
        }
    }
}
//Game update function
void Game::update()
{   
player.updatePlayerposition();
// Setting bullet origin position
BulletPack.bulletOrigin = Vector2f(player.dave.getPosition().x+(player.dave.getSize().x/2)-(bulletObj.bullet.getSize().x/2),player.dave.getPosition().y+(player.dave.getSize().y/2)-(bulletObj.bullet.getSize().y/2)); 


if(BulletPack.shootTimer < 10)
BulletPack.shootTimer++;

if(Keyboard::isKeyPressed(Keyboard::LControl) && BulletPack.shootTimer >= 10)
{

//For every Rectangleshape bullet object which is to added to its vector structure is given origin as center of player
   bulletObj.bullet.setPosition(BulletPack.bulletOrigin);
// Setting texture for every Rectangleshape bullet object 
   bulletObj.bullet.setTexture(&bulletObj.bulletTexture);
// For changing bullet moving and texture direction by passing player direction enum as argument   
   bulletObj.changeDirection(player.playerDirection);
// Loading ready Rectangleshape bullet object to ammunations vector   
   BulletPack.ammunations.push_back(bulletObj.bullet); 
// resetting shoottimer to zero
   BulletPack.shootTimer = 0;
}

for (size_t i = 0; i < BulletPack.ammunations.size(); i++)
{
    //Making the every bullet move by changing position of all bullet inside vector
    if(BulletPack.ammunations[i].getPosition().x  )
    BulletPack.ammunations[i].move(bulletObj.speed);
    //condition for erasing bullet if the cross the screen
      if(BulletPack.ammunations[i].getPosition().y < 0 || BulletPack.ammunations[i].getPosition().y >= window.getSize().y ||
        BulletPack.ammunations[i].getPosition().x < 0 || BulletPack.ammunations[i].getPosition().x >= window.getSize().x
      )
          BulletPack.ammunations.erase(BulletPack.ammunations.begin()+i);

      

}


}


// Game rendering function
void Game::render()
{
    window.clear();

    // Drawing background from grass Texture
    for (int i = 0; i < 36; i++)
    {
        for (int j = 0; j < 36; j++)
        {
            tilePosX = i;
            tilePosY = j;
            background.setPosition(Vector2f(20.0f * tilePosX, 20.0f * tilePosY));
            window.draw(background);
        }
    }

    // Adding Rocks in the backgrounds
    window.draw(Rock);

    // Adding Bushes in the backgrounds
    window.draw(Bush);

    // Adding player in the game
    window.draw(player.dave);
    // window.draw(bulletObj.bullet);

    for (size_t i = 0; i < BulletPack.ammunations.size(); i++)
    {
        window.draw(BulletPack.ammunations[i]);
    }
  window.display();
}

// Our main function
int main()
{
    Game game;
    game.run();
    return 0;
}