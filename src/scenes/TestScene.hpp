#pragma once
#include <SFML/Graphics.hpp>
#include "engine/Scene.hpp"
class TestScene : public Scene{
    public:
        void update(float deltaTime) override;
        void render(sf::RenderWindow& window) override;
        void handleEvent(const sf::Event& event) override;
        void onEnter() override;
        void onExit() override;
        sf::RenderWindow& window;
        TestScene(sf::RenderWindow& window);
        virtual ~TestScene();
        sf::Vector2f Pos={400.f,300.f};
};
