/*

#include "header.hpp"
class GameControl{
protected:
   
    
    void processEvents();
    void update();
    void render();
public:
RenderWindow window;
GameControl();
void runGame();

};
GameControl :: GameControl(): window(VideoMode(720, 720), "Adventure Game")
{
Menu menu(window);
}


// function for checking window close events
void GameControl::processEvents()
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

void GameControl :: runGame()
{
    while(window.isOpen()){
        processEvents();
        update();
        render();
    }
}

void GameControl :: update()
{

}

void GameControl :: render()
{

}*/