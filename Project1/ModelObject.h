#pragma once

#ifndef CASTRECORD_H
#define CASTRECORD_H
#endif 

#include "CastRecord.h"
#include <iostream>
#include "Material.h";

class ModelObject
{



public:
	ModelObject() {};
	~ModelObject();
	Material* mat_ptr;
	virtual bool testIntersection(const Ray& ray, CastRecord &rec, float min_len, float max_len) { std::cout << "model obj"; return false; }
	
};

