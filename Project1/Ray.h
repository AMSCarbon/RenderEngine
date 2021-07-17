#pragma once
#include "Vec3.h"
#include <iostream>

class Ray
{
public:
	Vec3 ori;
	Vec3 dir;

	Ray(const Vec3& o, const Vec3& d);
	Ray();
	~Ray();
	Vec3 point_at_parameter(float t) const { return ori + t * dir; }

	void print() const {
		std::cout << "ori x: " << ori.e[0] << "y: " << ori.e[1] << "z: " << ori.e[2] << std::endl;
		std::cout << "dir x: " << dir.e[0] << "y: " << dir.e[1] << "z: " << dir.e[2] << std::endl;
	
	}
 };

