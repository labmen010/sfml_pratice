#include <SFML/Graphics.hpp>
#include "engine/Application.hpp"
#include "scenes/TestScene.hpp"
#include <optional>
#include <memory>
int main()
{
	sf::Vector2u windowSize(800,600);
	Application app(windowSize,"SFML Practice");
	std::unique_ptr<TestScene> testScene = std::make_unique<TestScene>(app.getWindow());
	app.setScene(static_cast<Scene*>(testScene.get()));
	app.run();
}
