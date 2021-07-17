#pragma once
#include "RenderedImage.h"
#include "Model.h"
#include "Globals.h"
#include "Vec3.h"

class Renderer
{
private:
	int x = 1200;
	int y = 600;
	int r_samples = 2;
	RenderedImage img;
	Model model;
	Vec3 lower_left_corner;
	Vec3 horizontal;
	Vec3 vertical;
	Vec3 origin;
	bool shouldExit;


public:
	Renderer();
	~Renderer();
	void close() { shouldExit = true; }
	void test() { printf("hewwo"); }
	void loadModel(Model m) { model = m; }
	void render();
	void renderChunk(int x_start, int x_end, int y_start, int y_end);
	uint8_t* getImageAsPixelArray() { return img.imgToPixelArray(); }
};

