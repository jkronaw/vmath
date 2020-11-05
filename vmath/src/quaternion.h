#pragma once

#include "vector.h"
#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>

#define DEGREES_TO_RADIANS 0.01745329251994329547
#define RADIANS_TO_DEGREES 57.29577951308232185913

const float qThreshold = (float)1.0e-5;

struct Quaternion
{
	Quaternion() = default;
	Quaternion(float, float, float, float);
	Quaternion(const Quaternion&) = default;
	~Quaternion() = default;

	// quaternion operation
	float norm();
	Quaternion normalize();
	Quaternion conjugate();
	Quaternion inverse();
	float quadrance();
	void clean();

	// addition and soustraction
	Quaternion operator+(const Quaternion&);
	//Quaternion operator-(const Quaternion&);

	//multiplication
	Quaternion multiply(const Quaternion&);
	Quaternion multiply(float);

	// equality
	bool operator==(Quaternion&);
	bool operator!=(Quaternion&);

	void toAngleAxis(float&, Vector4&);
	Matrix4 GLRotationMatrix();



	// fields
	float t = 0.0;
	float x = 0.0;
	float y = 0.0;
	float z = 0.0;
};

// output
std::ostream& operator<<(std::ostream&, const Quaternion&);
std::ostream& printAngleAxis(std::ostream&, Quaternion&);

Quaternion qFromAngleAxis(float theta, Vector4 axis);

Quaternion qLerp(const Quaternion& q0, const Quaternion& q1, float k);
Quaternion qSlerp(const Quaternion& q0, const Quaternion& q1, float k);

Quaternion qmultiply(const Quaternion&, const Quaternion&);
Quaternion qmultiply(const Quaternion&, float);
