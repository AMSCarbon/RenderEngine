#include "Ray.h"





Ray::Ray(const Vec3& o, const Vec3& d)
{
	ori = Vec3(o.e[0], o.e[1], o.e[2]);
	dir = Vec3(d.e[0], d.e[1], d.e[2]);
	
}


Ray::Ray()
{
}

Ray::~Ray()
{
}
