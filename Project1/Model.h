#pragma once
#include "CastRecord.h"
#include "Globals.h"
#include "ModelObject.h"
#include <vector>

class Model
{
private:
	std::vector<ModelObject*> objects;
public:
	Model();
	~Model();

	void buildModel();

	Vec3 Cast(Ray& r, CastRecord& rec, float min_len, float max_len, int depth);
	ModelObject* findFirstHit(Ray r);
	void skyBox(Ray r, Vec3& colour);
	void sample(float x, float y, Vec3& colour);
};

