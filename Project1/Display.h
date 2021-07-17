#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"
class Display
{
private:
	bool windowCloseRequested = false;
	sf::RenderWindow window;
	sf::Image textureImage;
	sf::Texture	texture;
	sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(X_DIM, Y_DIM));
	sf::Sprite sprite;

public:
	Display();
	~Display();
	void close() { window.close();  }
	bool shouldClose() { return windowCloseRequested; }
	void initialize(uint8_t * pixels);
	void update(uint8_t* img);
};

