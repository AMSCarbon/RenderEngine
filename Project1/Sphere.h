#pragma once
#include "GeometricObject.h"
#include <iostream>
#include "Lambert.h"
class Sphere : public GeometricObject
{

private: 
	float r;
	Vec3 center;
public:
	Sphere () {
		r = 1.0;
		center = Vec3(0,0, -2);
	}
	Sphere(Vec3& origin, float rad) {
		r = rad;
		center = origin;
		mat_ptr = new Lambert();
	}
	bool testIntersection(const Ray& ray, CastRecord& cr, float min_len, float max_len) override {
		Vec3 oc = ray.ori - center;
		//oc.print();
		//ray.print();
		float a = dot(ray.dir, ray.dir);
		float b = dot(oc, ray.dir);
		float c = dot(oc, oc) - r*r;
		float discriminant = b * b - a * c;
	
	
		if (discriminant > 0) {
			cr.modelHit = true;
			cr.mat_ptr = mat_ptr;
			float temp = (-b - sqrtf(b * b - a * c)) / a;

			if (temp <max_len && temp > min_len) {
				cr.rayLength = temp;
				cr.hitPoint = ray.point_at_parameter(temp);
				cr.normal = (cr.hitPoint - center) / r;
						
				return true;
			}
			temp = (-b + sqrtf(b * b - a * c)) / a;
			if (temp <max_len && temp > min_len) {
				cr.rayLength = temp;
				cr.hitPoint = ray.point_at_parameter(temp);
				cr.normal = (cr.hitPoint - center) / r;
			
				return true;
			}
		}
		return false;
	
		
	};
};

