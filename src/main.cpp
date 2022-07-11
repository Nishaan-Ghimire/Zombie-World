#include "header.hpp"
#include "player.hpp"
#include "bullet.hpp"
#include "Enemy.hpp"
#include "menu.hpp"



class Game
{
private:
    int tilePosX = 0;
    int tilePosY = 0;
    // Creating a sturucture array for storing positions of obstacles
    struct obstacle
    {
        float x;
        float y;
    } obstaclePos[5] = {
        {20, 20},
        {336, 442},
        {20, 20},
        {20, 20},
        {20, 20}};
    // Iitializing the required objects
    RenderWindow window;
    RectangleShape background;
    RectangleShape Rock;
    RectangleShape Bush; 
    Texture backgroundTexture;
    Texture rockTexture;
    Texture bushTexture;  
    Player player;
    Enemy enemies;
    Bullet bulletObj;
    Bullets BulletPack;
    Enemies allEnemies;
    Clock clock;
    Time sec;  
    Menu menu;
    int seconds;
    int enemyspawnTimeInterval = 20;
    bool mainMenu = true;
    // Declaring the required game rendering and updating functions
    void processEvents();
    void update();
    void render();

public:
    Game();
    void run();
};

// Initializing Game object with neccessary texture and setting up their size and position
Game::Game() : window(VideoMode(720, 720), "Adventure Game"), background(Vector2f(40.0f, 40.0f)),
               Rock(Vector2f(200.0f, 200.0f)), Bush(Vector2f(250.0f, 200.0f))

{

    backgroundTexture.loadFromFile(IMG_PATH "/greengrass.jpg");
    background.setTexture(&backgroundTexture);
    rockTexture.loadFromFile(IMG_PATH "/rock.png");
    Rock.setTexture(&rockTexture);
    Rock.setPosition(Vector2f(1.0f * obstaclePos[0].x, 1.0f * obstaclePos[0].y));
    bushTexture.loadFromFile(IMG_PATH "/bush.png");
    Bush.setTexture(&bushTexture);
    Bush.setPosition(Vector2f(1.0f * obstaclePos[1].x, 1.0f * obstaclePos[1].y));
    allEnemies.enemySpawnNo = 5;
};

// function for starting all action
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

// function for checking window close events
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
// Game update function
void Game::update()
{


// For starting Game
if(Mouse::isButtonPressed(Mouse::Left))
{

    if( Mouse::getPosition(window).x >= menu.playBtn.getPosition().x  && Mouse::getPosition(window).x <= (menu.playBtn.getPosition().x+menu.playBtn.getSize().x)
 && Mouse::getPosition(window).x >= menu.playBtn.getPosition().y  && Mouse::getPosition(window).y <= (menu.playBtn.getPosition().y+menu.playBtn.getSize().y))
    {
        mainMenu = false;
      
    }
}

   
    sec = clock.getElapsedTime();
    seconds = sec.asSeconds();
    
    // Enemies
   
        if(allEnemies.enemySpawnNo > 0){
        switch (allEnemies.enemySpawnNo)
        {
        case 5:
            enemies.enemy.setPosition(Vector2f(enemies.enemypositions[4].x, enemies.enemypositions[4].y));
            break;
        case 4:
            enemies.enemy.setPosition(Vector2f(enemies.enemypositions[3].x, enemies.enemypositions[3].y));
            break;
        case 3:
            enemies.enemy.setPosition(Vector2f(enemies.enemypositions[2].x, enemies.enemypositions[2].y));
            break;
        case 2:
            enemies.enemy.setPosition(Vector2f(enemies.enemypositions[1].x, enemies.enemypositions[1].y));
            break;
        case 1:
            enemies.enemy.setPosition(Vector2f(enemies.enemypositions[0].x, enemies.enemypositions[0].y));
            break;
        }

        enemies.enemy.setTexture(&enemies.enemyTexture);
        allEnemies.enemyGroup.push_back(enemies);
        allEnemies.enemySpawnNo--;
            
        // allEnemies.enemyspawnTimer = 0;
    // }
    }
    player.updatePlayerposition();

    // Setting bullet origin position
    BulletPack.bulletOrigin = Vector2f(player.dave.getPosition().x + (player.dave.getSize().x / 2) + 10.0f, player.dave.getPosition().y + (player.dave.getSize().y / 2) + 10.0f);
    
    
 

   
    // Player Bullet timer 
    if (BulletPack.shootTimer < 10)
        BulletPack.shootTimer++;


        //Bullet initialization, movement and Direction control 
    if ((Keyboard::isKeyPressed(Keyboard::LControl) || Keyboard::isKeyPressed(Keyboard::RControl)) || Mouse::isButtonPressed(Mouse::Left) )
    {
        if( BulletPack.shootTimer >= 10){
        // For every Rectangleshape bullet object which is to added to its vector structure is given origin as center of player
        bulletObj.bullet.setPosition(BulletPack.bulletOrigin);
        // Setting texture for every Rectangleshape bullet object
        bulletObj.bullet.setTexture(&bulletObj.bulletTexture);
        // For changing bullet moving and texture direction by passing player direction enum as argument

        bulletObj.changeDirection(player.playerDirection, bulletObj.bullet, bulletObj.speed);

        // Loading ready Rectangleshape bullet object to ammunations vector
        BulletPack.ammunations.push_back(bulletObj);

        // resetting shoottimer to zero
        BulletPack.shootTimer = 0;
    }

}

 


    // For enemies movement
    for (size_t i = 0; i < allEnemies.enemyGroup.size(); i++)
    {
        // For following the player
        allEnemies.enemyGroup[i].updateEnemyPosition(Vector2f(player.dave.getPosition().x, player.dave.getPosition().y), allEnemies.enemyGroup[i].enemySpeed, allEnemies.enemyGroup[i].enemy);

        // Making the every enemy move by changing position of all enemy inside vector
        allEnemies.enemyGroup[i].enemy.move(allEnemies.enemyGroup[i].enemySpeed);
    }

    // For bullet movement and removing bullet
    for (size_t i = 0; i < BulletPack.ammunations.size(); i++)
    {
        // Making the every bullet move by changing position of all bullet inside vector
        BulletPack.ammunations[i].bullet.move(BulletPack.ammunations[i].speed);

        // condition for erasing bullet if the cross the screen
        if (BulletPack.ammunations[i].getPosition().y < 0 || BulletPack.ammunations[i].getPosition().y >= window.getSize().y ||
            BulletPack.ammunations[i].getPosition().x < 0 || BulletPack.ammunations[i].getPosition().x >= window.getSize().x)
            BulletPack.ammunations.erase(BulletPack.ammunations.begin() + i);
    }


// For Enemy and Bullet collision

for (size_t i = 0; i < BulletPack.ammunations.size(); i++)
{
    
    for (size_t j = 0; j < allEnemies.enemyGroup.size(); j++)
    {
        if(BulletPack.ammunations[i].bullet.getGlobalBounds().intersects(allEnemies.enemyGroup[j].enemy.getGlobalBounds()))
        {
            BulletPack.ammunations.erase(BulletPack.ammunations.begin() + i);
            allEnemies.enemyGroup.erase(allEnemies.enemyGroup.begin() + j);
        }
    }
    
}


// For Player and Enemy Collision

for (size_t i = 0; i < allEnemies.enemyGroup.size(); i++)
{
    if(player.dave.getGlobalBounds().intersects(allEnemies.enemyGroup[i].enemy.getGlobalBounds()))
    {
     
        player.daveLifesize -= 25;
        player.dave.setPosition(player.originalPos.x, player.originalPos.y);
        player.davelife.setPosition(Vector2f(player.dave.getPosition().x,player.dave.getPosition().y-player.davelife.getSize().y));
        player.davelife.setSize(Vector2f(player.davelife.getSize().x - 25,player.davelife.getSize().y));
        if(player.davelife.getSize().x <= 0)
        {

        }
    }
}



}


// Game rendering function
void Game::render()
{
    window.clear();
   
    if(mainMenu)
    {
       window.draw(menu.menuBackground);
       window.draw(menu.playBtn);
       window.draw(menu.soundBtn);
       window.draw(menu.exitBtn);
       window.draw(menu.logo);
    }else{
    
    


    // Drawing background from grass Texture
    for (int i = 0; i < 18; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            tilePosX = i;
            tilePosY = j;
            background.setPosition(Vector2f(40.0f * tilePosX, 40.0f * tilePosY));
            window.draw(background);
        }
    }

    // Adding Rocks in the backgrounds
    window.draw(Rock);

    // Adding Bushes in the backgrounds
    window.draw(Bush);

    // Adding player in the game
    window.draw(player.dave);
    window.draw(player.davelife);

    //    Adding Enemies
    for (size_t i = 0; i < allEnemies.enemyGroup.size(); i++)
    {
   
  
        window.draw(allEnemies.enemyGroup[i].enemy);

    }
    for (size_t i = 0; i < BulletPack.ammunations.size(); i++)
    {
        window.draw(BulletPack.ammunations[i].bullet);
    }
     

}
window.display();


  
      

}




int main()
{

Game game;
game.run();
return 0;
}