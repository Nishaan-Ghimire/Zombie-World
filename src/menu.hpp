#include "GameControl.hpp"
#define IMG_PATH "/home/nishan/Desktop/adventure_beta/images"
class Menu 
{
protected:
    RectangleShape menuBackground;
    RectangleShape playBtn;
    RectangleShape soundBtn;
    RectangleShape exitBtn;
    RectangleShape logo;
    RectangleShape MissionComplete;
    RectangleShape youLose;
    Texture menuBackgroundTexture;
    Texture playbtnTexture;
    Texture soundbtnTexture;
    Texture exitBtnTexture;
    Texture logoTexture;
    Texture MissionCompletedTexture;
    
public:
    Menu();
     friend class Game;
};

Menu :: Menu() : menuBackground(Vector2f(720.0f, 720.0f)) , playBtn(Vector2f(250.0f,70.0f)),soundBtn(Vector2f(250.0f,70.0f)),exitBtn(Vector2f(250.0f,70.0f)),logo(Vector2f(500.0f,250.0f)),MissionComplete(Vector2f(720.0f, 720.0f))
{
    menuBackground.setPosition(Vector2f(0.0f, 0.0f));
    menuBackgroundTexture.loadFromFile(IMG_PATH"/menubackground.png");
    menuBackground.setTexture(&menuBackgroundTexture);
    playBtn.setPosition(Vector2f(200.0f,300.0f));
    playbtnTexture.loadFromFile(IMG_PATH"/play.png");
    playBtn.setTexture(&playbtnTexture);
    soundBtn.setPosition(Vector2f(190.0f,375.0f));
    soundbtnTexture.loadFromFile(IMG_PATH"/sound.png");
    soundBtn.setTexture(&soundbtnTexture);
    exitBtn.setPosition(Vector2f(190.0f,450.0f));
    exitBtnTexture.loadFromFile(IMG_PATH"/exit.png");
    exitBtn.setTexture(&exitBtnTexture);
    logo.setPosition(Vector2f(100.0f,50.0f));
    logoTexture.loadFromFile(IMG_PATH"/logo.png");
    logo.setTexture(&logoTexture);
    MissionComplete.setPosition(Vector2f(100.0f,50.0f));
    MissionCompletedTexture.loadFromFile(IMG_PATH"/completed.png");
    MissionComplete.setTexture(&logoTexture);
    
}





