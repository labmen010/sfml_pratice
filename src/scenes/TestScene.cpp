#include "TestScene.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
TestScene::TestScene(sf::RenderWindow& window)
    : window(window) {
    //ctor
}
TestScene::~TestScene(){
    //dtor
}
void TestScene::
update(float deltaTime){
    this->deltaTime=deltaTime;
    Pos.x+=deltaTime*20.f;
    //update
}
void TestScene::render(sf::RenderWindow& window){
    //render
    float FPS=1/deltaTime;
    sf::Font font("src/assets/accid.ttf");
    sf::Text text(font,"",24);
    text.setString("FPS: "+std::to_string(FPS));
    sf::CircleShape shape( 100.f );
    shape.setFillColor( sf::Color::Green );
    shape.setPosition(Pos);
    window.draw(shape);
    window.draw(text);
}
void TestScene::handleEvent(const sf::Event& event){
    //handle event
    if(const auto KeyPressed=event.getIf<sf::Event::KeyPressed>())
    {
        if(KeyPressed->scancode==sf::Keyboard::Scancode::W)
        {
            Pos.y-=10.f;
        }
        if(KeyPressed->scancode==sf::Keyboard::Scancode::S)
        {
            Pos.y+=10.f;
        }
        if(KeyPressed->scancode==sf::Keyboard::Scancode::A)
        {
            Pos.x-=10.f;
        }
        if(KeyPressed->scancode==sf::Keyboard::Scancode::D)
        {
            Pos.x+=10.f;
        }
    }
    {

    }
    
}
void TestScene::onEnter(){
    //on enter
}
void TestScene::onExit(){
    //on exit
    
}