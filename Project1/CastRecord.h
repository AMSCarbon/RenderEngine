#pragma once
#include "Ray.h"
#include "Material.h"
#ifndef MODELOBJECT_H
#define MODELOBJECT_H

class CastRecord
{
	

public:
	int depth = 0;
	float rayLength = 0;
	Ray ray;
	Vec3 hitPoint;
	Vec3 colour;
	Vec3 normal;
	bool modelHit = false;
	Material* mat_ptr;


	CastRecord();
	~CastRecord();
	bool anyHit() { return modelHit; }

	void setColours(int r, int g, int b) { colour = Vec3(r, g, b); }
	void setColours(Vec3& col) { colour = Vec3(col.e[0], col.e[1], col.e[2]); }
	Vec3 getColour() { return colour; }

	float getRayLength() { return rayLength; }
};


#endif // !MODELOBJECT_H

