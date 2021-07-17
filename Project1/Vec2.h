#pragma once
#include <math.h>
class Vec2 
{
public:

	float e[2];
	Vec2() { Vec2(0,0); }
	Vec2(float e0, float e1) {
		e[0] = e0;
		e[1] = e1;
	}
	inline Vec2& operator+() { return *this; }
	inline Vec2 operator-() const { return Vec2(-e[0], -e[1]); }
	inline float operator[](int i) const { return e[i]; }
	inline float& operator[](int i) { return e[i]; }

	inline Vec2& operator+=(const Vec2& v);
	inline Vec2& operator-=(const Vec2& v);
	inline Vec2& operator*=(const Vec2& v);
	inline Vec2& operator/=(const Vec2& v);
	inline Vec2& operator*=(const float t);
	inline Vec2& operator/=(const float t);

	
	inline float length() const {
		return sqrtf(e[0]*e[0] + e[1]*e[1]);
	}
	inline float squared_length() const {
		return e[0] * e[0] + e[1] * e[1];
	};
	inline void make_unit_vector();
};

inline Vec2 operator+ (const Vec2& v1, const Vec2& v2) {
	return Vec2(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1]);
}

inline Vec2 operator- (const Vec2& v1, const Vec2& v2) {
	return Vec2(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1]);
}

inline Vec2 operator* (const Vec2& v1, const Vec2& v2) {
	return Vec2(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1]);
}

inline Vec2 operator/ (const Vec2& v1, const Vec2& v2) {
	return Vec2(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1]);
}

inline Vec2 operator* (float t , const Vec2& v1) {
	return Vec2(v1.e[0]* t, v1.e[1] * t);
}

inline Vec2 operator* ( const Vec2& v1, float t) {
	return Vec2(v1.e[0] * t, v1.e[1] * t);
}


inline Vec2 operator/ (const Vec2& v1, float t) {
	return Vec2(v1.e[0] / t, v1.e[1] / t);
}

inline void Vec2::make_unit_vector() {
		float k = 1 / sqrtf(e[0] * e[0] + e[1] * e[1]);
		e[0] *= k; e[1] *= k;
}

inline Vec2& Vec2::operator+=(const Vec2& v) {
	e[0] += v.e[0];
	e[1] += v.e[1];
	return *this;
}
inline Vec2& Vec2::operator-=(const Vec2& v) {
	e[0] -= v.e[0];
	e[1] -= v.e[1];
	return *this;
}
inline Vec2& Vec2::operator*=(const Vec2& v) {
	e[0] *= v.e[0];
	e[1] *= v.e[1];
	return *this;
}
inline Vec2& Vec2::operator/=(const Vec2& v) {
	e[0] /= v.e[0];
	e[1] /= v.e[1];
	return *this;
}

inline Vec2& Vec2::operator*=(const float t) {
	e[0] *= t;
	e[1] *= t;
	return *this;
}
inline Vec2& Vec2::operator/=(const float t) {
	e[0] /= t;
	e[1] /= t;
	return *this;
}
