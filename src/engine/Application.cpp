#include "Application.hpp"
Application::Application(sf::Vector2u windowSize, const std::string& title)
    : window(sf::VideoMode(windowSize), title), currentScene(nullptr) {
}
Application::~Application() {
    if (currentScene) {
        currentScene->onExit();
    }
}
void Application::setScene(Scene* newScene){
    if(currentScene){
        currentScene->onExit();
        currentScene=newScene;
        currentScene->onEnter();
    }else{
        currentScene=newScene;
        currentScene->onEnter();
    }
}
void Application::run()
{
    sf::Clock clock;
    while(window.isOpen())
    {
        processEvents();
        float deltaTime=1/60.f;
        fixedUpdate(deltaTime);
        render();
    }
}
void Application::processEvents(){
    while(const std::optional event =window.pollEvent()){
        if(event->is<sf::Event::Closed>()){
            window.close();
        }else if(const auto keyPress=event->getIf<sf::Event::KeyPressed>()){
            if(keyPress->scancode==sf::Keyboard::Scancode::Escape){
                window.close();
            }
        }
        if(currentScene){
            currentScene->handleEvent(*event);
        }
    }
}
void Application::fixedUpdate(float deltaTime){
    if(currentScene){
        currentScene->update(deltaTime);
    }
}
void Application::render(){
    window.clear();
    if(currentScene){
        currentScene->render(window);
    }
    window.display();
}