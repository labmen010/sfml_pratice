#pragma once
#include <SFML/Graphics.hpp>
#include "engine/Scene.hpp"
class Application{
public:
    Application(sf::Vector2u windowSize, const std::string& title);
    ~Application();
    void setScene(Scene* newScene);
    void run();
    sf::RenderWindow& getWindow() { return window; }
private:
    sf::RenderWindow window;
    Scene* currentScene;
    void processEvents();
    void fixedUpdate(float deltaTime);
    void render();

};