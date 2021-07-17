#pragma once
#include "Vec3.h"
#include "Ray.h"
#include <vector>
class Material
{

public:
	Material() {};
	~Material() {};

	virtual Vec3 colour(Vec3 in) = 0 ;
	virtual Ray child_ray(Ray& o, Vec3& p, Vec3& norm) = 0;

};

