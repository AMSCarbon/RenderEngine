#include "Display.h"
#include "Globals.h"

Display::Display()
{
	window.create(sf::VideoMode(X_DIM, Y_DIM), "Render Test");
}


Display::~Display()
{
}

void Display::initialize(uint8_t * pixels)
{
	textureImage.create(X_DIM, Y_DIM, pixels);
	texture.loadFromImage(textureImage);
	sprite.setTexture(texture);

	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) windowCloseRequested = true;
	}
	window.clear();
	window.draw(sprite);
	window.display();
}

void Display::update(uint8_t * pixels)
{
	sf::Event event;
	while (window.pollEvent(event))	{
		if (event.type == sf::Event::Closed) windowCloseRequested = true;
	}

	texture.update(pixels);
	sprite.setTexture(texture);

	window.clear();
	window.draw(sprite);
	window.display();
	free(pixels);
}

