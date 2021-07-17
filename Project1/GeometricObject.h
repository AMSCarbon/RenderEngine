#pragma once
#include "ModelObject.h"
#include "Material.h"
#include <iostream>


class GeometricObject : public ModelObject
{
private:
public: 
	GeometricObject() {};
	virtual bool testIntersection(const Ray& ray, CastRecord& cr, float min_len, float max_len) { std::cout << "geometric obj"; return false; }
	 
};

