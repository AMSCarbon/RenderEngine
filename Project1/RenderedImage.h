#pragma once
#include <cstdint>
#include "Vec3.h"

class RenderedImage
{
private:
	float*** img;
	int x_dim;
	int y_dim;

public:
	RenderedImage();
	RenderedImage(int x, int y);
	~RenderedImage();
	void setPixels();
	void updatePixel(int x, int y, Vec3 &colour, int sampleNumber);
	//void updatePixel(int x, int y, int channel, float colour);
	uint8_t* imgToPixelArray();

};

