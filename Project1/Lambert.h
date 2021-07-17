#pragma once
#include "Material.h"


class Lambert:
	public Material 
{
public:


	Vec3 colour(Vec3 in) {
		
		return albedeo*in;
	}

	Ray child_ray(Ray& o, Vec3& p, Vec3& norm) {
		Vec3 newTarget = p+ norm + random_in_unit_sphere();
		Ray n_r;
		n_r.ori =p;
		n_r.dir = newTarget;
		return n_r;
	}
	   
	Vec3 random_in_unit_sphere() {
		Vec3 p;
		do {
			p = 2.0 * Vec3((double)rand() / RAND_MAX, (double)rand() / RAND_MAX, (double)rand() / RAND_MAX) - Vec3(1, 1, 1);
		} while (p.squared_length() >= 1.0);
		return p;

	}
	Vec3 albedeo = Vec3(0.5,0.5,0.5);
};

