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
    Pos.x+=deltaTime*20.f;
    //update
}
void TestScene::render(sf::RenderWindow& window){
    //render
    sf::CircleShape shape( 100.f );
    shape.setFillColor( sf::Color::Green );
    shape.setPosition(Pos);
    window.draw(shape);
}
void TestScene::handleEvent(const sf::Event& event){
    //handle event
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        switch (keyPressed->scancode)
        {
            case sf::Keyboard::Scancode::W:
                Pos.y -= 10.f;
                break;
            case sf::Keyboard::Scancode::S:
                Pos.y += 10.f;
                break;
            case sf::Keyboard::Scancode::A:
                Pos.x -= 10.f;
                break;
            case sf::Keyboard::Scancode::D:
                Pos.x += 10.f;
                break;
            default:
                break;
        }
    
    }
    
}
void TestScene::onEnter(){
    //on enter
}
void TestScene::onExit(){
    //on exit
}