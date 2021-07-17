#include "RenderedImage.h"
#include "Globals.h"
#include <iostream>

RenderedImage::RenderedImage()
{
	RenderedImage(100, 100);
}

RenderedImage::RenderedImage(int x, int y)
{
	x_dim = x;
	y_dim = y;
	img = new float**[x_dim];
	for (int i = 0; i < x_dim; i++) {
		img[i] = new float*[y_dim];
		for (int j = 0; j < y_dim; j++ ) {	
			img[i][j] = new float[3];
		}
	}
	setPixels();
}


RenderedImage::~RenderedImage()
{
}

void RenderedImage::setPixels(){
	for (int i = 0; i < x_dim; i++) {
		for (int j = 0; j < y_dim; j++ ) {	
			img[i][j][0] = 0;
			img[i][j][1] = 0;
			img[i][j][2] = 0;
		}
	}
}

void RenderedImage::updatePixel(int x, int y, Vec3 &colour, int sampleNumber)
{
	if (sampleNumber == 0) {
		img[x][y][0] = colour[0];
		img[x][y][1] = colour[1];
		img[x][y][2] = colour[2];
	}
	else {
		img[x][y][0] = (img[x][y][0] * sampleNumber + colour[0]) / (sampleNumber + 1);
		img[x][y][1] = (img[x][y][1] * sampleNumber + colour[1]) / (sampleNumber + 1);
		img[x][y][2] = (img[x][y][2] * sampleNumber + colour[2]) / (sampleNumber + 1);
	}
}

uint8_t * RenderedImage::imgToPixelArray()
{
	//SFML has 4th channel of alpha. 
	uint8_t* pixelArray = new uint8_t[x_dim*y_dim * 4];

	for (int i = 0; i < x_dim; i++) {
		for (int j = 0; j < y_dim; j++) {
			int index = j*4*X_DIM + i*4 ;
			pixelArray[index] = img[i][j][0] * 255.0f;
			pixelArray[index + 1] = img[i][j][1] * 255.0f;
			pixelArray[index + 2] = img[i][j][2] * 255.0f;
			pixelArray[index + 3] = 255;
		}
	}
	return pixelArray;
}
