#include "TestScene.hpp"
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
    
}
void TestScene::onEnter(){
    //on enter
}
void TestScene::onExit(){
    //on exit
    
}