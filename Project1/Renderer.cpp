#include "Renderer.h"
#include "Ray.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <random>
#include <memory>
#include <functional>
#include <vector>
#include <cstdlib>
#include <cstdio>

Renderer::Renderer()
{
	img = RenderedImage(X_DIM, Y_DIM);


	lower_left_corner = Vec3(-2.0, -1.0, -1.0);
	horizontal = Vec3(4.0, 0, 0);
	vertical = Vec3(0, 2.0, 0);
	origin = Vec3(0,0,0);
}

Renderer::~Renderer()
{
}

void Renderer::render()
{
	int x_chunkLength = X_DIM / chunks;
	int y_chunkLength = Y_DIM / chunks;
	const int totalChunks = chunks * chunks;
	std::vector<sf::Thread*> chunkList;
	for (int i = 0; i < chunks; i++) {
		for (int j = 0; j < chunks; j++) {
			sf::Thread *renderThread = new sf::Thread(std::bind(&Renderer::renderChunk, this,i*x_chunkLength, (i + 1)* x_chunkLength, j * y_chunkLength, (j + 1) * y_chunkLength)) ;
			chunkList.push_back(renderThread);
		}
	}	
	for (int i = 0; i < totalChunks; i++) {
		chunkList[i]->launch();
	}
}


Vec3 random_in_unit_circle() {
	Vec3 p;
	do {
		p = 2.0 * Vec3((double)rand() / RAND_MAX , (double)rand() / RAND_MAX, 0) - Vec3(1, 1, 0);
	} while (p.squared_length() >= 1.0);
	return p;

}
void Renderer::renderChunk(int x_start, int x_end, int y_start, int y_end ) {
	
	Vec3 u_v = Vec3(0, 0.1, 0);
	Vec3 u_h = Vec3(0.1, 0, 0);
	Vec3 col = Vec3();

	for (int k = 0; k < samples; k++) {
		for (int i = x_start; i < x_end; i++) {
			for (int j = y_start; j < y_end; j++) {
				//The threads would keep running after closing everything else, which cause exceptions. just return early. 
				if (shouldExit) return; 
				Vec3 rand = random_in_unit_circle();
				float u = (float(i + rand.e[0]) ) / float(X_DIM);
				float v = (float(j + rand.e[1]) ) / float(Y_DIM);
				Ray r = Ray(origin, lower_left_corner + u * horizontal + v * vertical  );
				CastRecord cr;
				col = model.Cast(r, cr, 0, 100, 0);
				img.updatePixel(i, j, col, k);
			}
		}
	}
	std::cout << "done" << std::endl;
}
