#include "Engine.h"
#include <boost/numeric/ublas/vector.hpp>
#include "Display.h"
#include "Model.h"
#include "Renderer.h"
#include "RenderedImage.h"
#include "Globals.h"
#include <thread>

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::start()
{
}

void Engine::run()
{
	Display display;
	Model model;
	Renderer renderer;
	model.buildModel();
	// load the model into the render. Start rendering on a new thread.
	renderer.loadModel(model);
	renderer.render();
	//Display the results of rendering in real time 
	display.initialize(renderer.getImageAsPixelArray());
	while (!display.shouldClose()) {
		display.update(renderer.getImageAsPixelArray());
	}
	renderer.close();
	display.close();
}

using namespace boost::numeric;

int main() {
	ublas::vector<float> v (3);

	Engine e = Engine();

	e.start();
	e.run();
	
	return 0;
}