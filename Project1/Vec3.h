#pragma once
#include <math.h>
#include <iostream>
class Vec3
{
public:
	float e[3];
	Vec3() { Vec3(0, 0, 0); }
	Vec3(float e0, float e1, float e2) {
		e[0] = e0;
		e[1] = e1;
		e[2] = e2;
	}

	void print() {
		std::cout << "x: " << e[0] << "y: " << e[1] << "z: " << e[2] << std::endl;
	}

	inline Vec3& operator+() { return *this; }
	inline Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
	inline float operator[](int i) const { return e[i]; }
	inline float& operator[](int i) { return e[i]; }

	inline Vec3& operator+=(const Vec3& v);
	inline Vec3& operator-=(const Vec3& v);
	inline Vec3& operator*=(const Vec3& v);
	inline Vec3& operator/=(const Vec3& v);
	inline Vec3& operator*=(const float t);
	inline Vec3& operator/=(const float t);


	inline float length() const {
		return sqrtf(e[0] * e[0] + e[1] * e[1] + +e[2] * e[2]);
	}
	inline float squared_length() const {
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	};
	inline void make_unit_vector();
};

inline Vec3 operator+ (const Vec3& v1, const Vec3& v2) {
	return Vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline Vec3 operator- (const Vec3& v1, const Vec3& v2) {
	return Vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1] , v1.e[2] - v2.e[2]);
}

inline Vec3 operator* (const Vec3& v1, const Vec3& v2) {
	return Vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline Vec3 operator/ (const Vec3& v1, const Vec3& v2) {
	return Vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

inline Vec3 operator* (float t, const Vec3& v1) {
	return Vec3(v1.e[0] * t, v1.e[1] * t, v1.e[2] * t);
}

inline Vec3 operator* (const Vec3& v1, float t) {
	return Vec3(v1.e[0] * t, v1.e[1] * t, v1.e[2] * t);
}


inline Vec3 operator/ (const Vec3& v1, float t) {
	return Vec3(v1.e[0] / t, v1.e[1] / t, v1.e[2] / t);
}

inline void Vec3::make_unit_vector() {
	float k = 1 / sqrtf(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	e[0] *= k; e[1] *= k; e[2] *= k;
}

inline Vec3& Vec3::operator+=(const Vec3& v) {
	e[0] += v.e[0];
	e[1] += v.e[1];
	e[2] += v.e[2];
	return *this;
}
inline Vec3& Vec3::operator-=(const Vec3& v) {
	e[0] -= v.e[0];
	e[1] -= v.e[1];
	e[2] -= v.e[2];
	return *this;
}
inline Vec3& Vec3::operator*=(const Vec3& v) {
	e[0] *= v.e[0];
	e[1] *= v.e[1];
	e[2] *= v.e[2];
	return *this;
}
inline Vec3& Vec3::operator/=(const Vec3& v) {
	e[0] /= v.e[0];
	e[1] /= v.e[1];
	e[2] /= v.e[2];
	return *this;
}

inline Vec3& Vec3::operator*=(const float t) {
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}
inline Vec3& Vec3::operator/=(const float t) {
	e[0] /= t;
	e[1] /= t;
	e[2] /= t;
	return *this;
}


inline float dot(const Vec3& v1, const Vec3& v2) {
	return (v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2]);
}

inline Vec3 cross(const Vec3& v1, const Vec3& v2) {
	return Vec3(v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
		v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0],
		v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]);
}