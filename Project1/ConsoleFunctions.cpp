#include "ConsoleFunctions.h"
#include "Display.h"
#include "Renderer.h"

class RenderScene: ConsoleFunction
{
	std::string name = "renderScene";
	int expectedArgLen = 1;
public:
	virtual int execute(Display display, Model model, Renderer renderer, std::vector<std::string> argV) {
		sf::Thread renderThread(&Renderer::render, &renderer);
		renderThread.launch();
		return 0; 
	}
};

class QuitProgram : ConsoleFunction
{
	std::string name = "quit";
	int expectedArgLen = 1;
public:
	virtual int execute(Display display, Model model, Renderer renderer, std::vector<std::string> argV) { 
		display.shouldClose = true;
		return -1; }

};