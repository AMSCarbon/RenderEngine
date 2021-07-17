#pragma once
#include "Material.h"


class Metal: public Material
{
public:

	Vec3 colour(Vec3 in) {
		return albedeo*in;
	}

	Vec3 reflect(const Vec3& v,const Vec3& n) {
		return v - 2 * dot(v, n) * n;
	}

	Ray child_ray(Ray& o, Vec3& p, Vec3& norm) {
		Vec3 newTarget = reflect(o.dir, norm);//p+ norm + random_in_unit_sphere();
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

