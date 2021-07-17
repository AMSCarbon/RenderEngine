#include "Model.h"
#include <iostream>
#include "Sphere.h"
#include "Lambert.h"
#include "Metal.h"
Model::Model()
{
}


Model::~Model()
{
}

void Model::buildModel() {
	Vec3 up= Vec3(0, 20, -5);
	Sphere* s = new Sphere(up, 20);
	Lambert* l = new Lambert();
	l->albedeo = Vec3(0.4, 0.6, 0.45);
	s->mat_ptr = l;
	objects.push_back(s);
	
	up = Vec3(2,-0.5 , -2);
	s = new Sphere(up, 0.5);
	Metal* m = new Metal();
	m->albedeo = Vec3(0.9, 0.6, 0.6);
	s->mat_ptr = m;
	objects.push_back(s);

	up = Vec3(-2, -0.5, -2);
	s = new Sphere(up, 0.5);
	m = new Metal();
	m->albedeo = Vec3(0.9, 0.6, 0.9);
	s->mat_ptr = m;
	objects.push_back(s);

	Vec3 ground = Vec3(0, -0.5, -2);
	objects.push_back(new Sphere(ground, 0.8));
}

Vec3 Model::Cast(Ray& r, CastRecord& rec, float min_len, float max_len, int depth)
{
	if (depth == 50) return Vec3(0, 0, 0);
	CastRecord temp;
	bool hit = false;
	for (ModelObject* o : objects) {
		//Test intersection, if this intersection is the shortest, update the hit record.
		if (o->testIntersection(r, temp, 0.0000001, 100)) {
			//this is the first hit.
			if (!rec.anyHit()) {
				rec = temp;
			}
			else if (temp.getRayLength() < rec.getRayLength()) {
			//for any other hit, compare the length of the vector to see if it'd occur closer
				rec = temp;
			}
		}
	}

	if (rec.anyHit()) {
		
		Ray n_r = rec.mat_ptr->child_ray(r, rec.hitPoint, rec.normal);
		CastRecord newRec; 
		Cast(n_r, newRec, min_len, max_len, depth+1);
		rec.colour = rec.mat_ptr->colour(newRec.colour);
		
	}
	else {
		//no hit, skybox
		//if (depth > 0)std::cout << depth << std::endl;
		Vec3 col;
		skyBox(r, col);
		rec.setColours(col);
	}

	return rec.colour;
}

ModelObject* Model::findFirstHit(Ray r)
{
	return NULL;
}

void Model::skyBox(Ray r, Vec3& colour)
{

	Vec3 r_y = r.dir;
	r_y.make_unit_vector();
	float t = 0.5 * (-1*r_y.e[1] + 1.0);
	Vec3 col = ((1.0-t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0));
	colour.e[0] = col.e[0];
	colour.e[1] = col.e[1];
	colour.e[2] = col.e[2];
}

void Model::sample(float x, float y, Vec3& colour)
{

}
