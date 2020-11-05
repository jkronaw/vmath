#include "quaternion.h"
#include<math.h>

Quaternion::Quaternion(float t, float x, float y, float z) : t(t), x(x), y(y), z(z){ }
//Quaternion::Quaternion(Quaternion& q) {
//	t = q.t;
//	x = q.x;
//	y = q.y;
//	z = q.z;
//}

// quaternion operation
float Quaternion::norm() {
	return sqrt(this->quadrance());
}

Quaternion Quaternion::normalize() {
	float s = 1 / this->norm();
	return this->multiply(s);
}

Quaternion Quaternion::conjugate() {
	Quaternion qconj = { t, -x, -y, -z };
	return qconj;
}

Quaternion Quaternion::inverse() {
	return qmultiply(this->conjugate(), 1.0f/this->quadrance());
}

float Quaternion::quadrance() {
	return t * t + x * x + y * y + z * z;
}

void Quaternion::clean() {
	if (fabs(t) < qThreshold) t = 0.0f;
	if (fabs(x) < qThreshold) x = 0.0f;
	if (fabs(y) < qThreshold) y = 0.0f;
	if (fabs(z) < qThreshold) z = 0.0f;
}

// addition and soustraction
Quaternion Quaternion::operator+(const Quaternion& q1) {
	Quaternion q;
	q.t = t + q1.t;
	q.x = x + q1.x;
	q.y = y + q1.y;
	q.z = z + q1.z;
	return q;
}
//Quaternion Quaternion::operator-(const Quaternion&);

//multiplication
Quaternion Quaternion::multiply(const Quaternion& q1) {
	Quaternion q;
	q.t = t * q1.t - x * q1.x - y * q1.y - z * q1.z;
	q.x = t * q1.x + x * q1.t + y * q1.z - z * q1.y;
	q.y = t * q1.y + y * q1.t + z * q1.x - x * q1.z;
	q.z = t * q1.z + z * q1.t + x * q1.y - y * q1.x;
	return q;
}

Quaternion Quaternion::multiply(float s) {
	Quaternion sq;
	sq.t = s * t;
	sq.x = s * x;
	sq.y = s * y;
	sq.z = s * z;
	return sq;
}


void Quaternion::toAngleAxis(float& theta, Vector4& axis) {
	// return the angla and the axis decribe by the quaternion
	Quaternion qn = this->normalize();
	theta = 2.0f * acos(qn.t) * (float)RADIANS_TO_DEGREES;
	float s = sqrt(1.0f - qn.t * qn.t);
	if (s < qThreshold) {
		axis.x = 1.0f;
		axis.y = 0.0f;
		axis.z = 0.0f;
		axis.w = 1.0f;
	}
	else {
		float sinv = 1 / s;
		axis.x = qn.x * sinv;
		axis.y = qn.y * sinv;
		axis.z = qn.z * sinv;
		axis.w = 1.0f;
	}
}

Matrix4 Quaternion::GLRotationMatrix() {
	Quaternion qn = this->normalize();

	float xx = qn.x * qn.x;
	float xy = qn.x * qn.y;
	float xz = qn.x * qn.z;
	float xt = qn.x * qn.t;
	float yy = qn.y * qn.y;
	float yz = qn.y * qn.z;
	float yt = qn.y * qn.t;
	float zz = qn.z * qn.z;
	float zt = qn.z * qn.t;

	Matrix4 matrix(1.0f - 2.0f * (yy + zz), 2.0f * (xy + zt), 2.0f * (xz - yt), 0.0f,
		2.0f * (xy - zt), 1.0f - 2.0f * (xx + zz), 2.0f * (yz + xt), 0.0f,
		2.0f * (xz + yt), 2.0f * (yz - xt), 1.0f - 2.0f * (xx + yy), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);

	// mClean(matrix);

	return matrix;
}


// equality
bool Quaternion::operator==(Quaternion& q1) {
	return (fabs(t - q1.t) < qThreshold && fabs(x - q1.x) < qThreshold &&
		fabs(y - q1.y) < qThreshold && fabs(z - q1.z) < qThreshold);
}

bool Quaternion::operator!=(Quaternion& q1) {
	return !((*this) == q1);
}

// output
std::ostream& operator<<(std::ostream& os, const Quaternion& q) {
	os << " = (" << q.t << ", " << q.x << ", " << q.y << ", " << q.z << ")" ;
	return os;
}

std::ostream& printAngleAxis(std::ostream& os, Quaternion& q) {
	float thetaf;
	Vector4 axis_f;
	q.toAngleAxis(thetaf, axis_f);
	os << " = [" << "  angle = " << thetaf << "  axis" << axis_f << "]" ;
	return os;
}

Quaternion qFromAngleAxis(float theta, Vector4 axis)
{	
	axis.normalize();
	Vector4 axisn = axis;

	Quaternion q;
	float a = theta * (float)DEGREES_TO_RADIANS;
	q.t = cos(a / 2.0f);
	float s = sin(a / 2.0f);
	q.x = axisn.x * s;
	q.y = axisn.y * s;
	q.z = axisn.z * s;

	//qClean(q);
	return q.normalize();
}

Quaternion qLerp(const Quaternion& q0, const Quaternion& q1, float k)
{
	float cos_angle = q0.x * q1.x + q0.y * q1.y + q0.z * q1.z + q0.t * q1.t;
	float k0 = 1.0f - k;
	float k1 = (cos_angle > 0) ? k : -k;
	Quaternion qi = qmultiply(q0, k0) + qmultiply(q1, k1);
	return qi.normalize();
}

Quaternion qSlerp(const Quaternion& q0, const Quaternion& q1, float k)
{
	float angle = acos(q0.x * q1.x + q0.y * q1.y + q0.z * q1.z + q0.t * q1.t);
	float k0 = sin((1 - k) * angle) / sin(angle);
	float k1 = sin(k * angle) / sin(angle);
	Quaternion qi = qmultiply(q0, k0) + qmultiply(q1, k1);
	return qi.normalize();
}


Quaternion qmultiply(const Quaternion& q0, const Quaternion& q1) {
	Quaternion q;
	q.t = q0.t * q1.t - q0.x * q1.x - q0.y * q1.y - q0.z * q1.z;
	q.x = q0.t * q1.x + q0.x * q1.t + q0.y * q1.z - q0.z * q1.y;
	q.y = q0.t * q1.y + q0.y * q1.t + q0.z * q1.x - q0.x * q1.z;
	q.z = q0.t * q1.z + q0.z * q1.t + q0.x * q1.y - q0.y * q1.x;
	return q;
}

Quaternion qmultiply(const Quaternion& q0, float s) {
	Quaternion sq;
	sq.t = s * q0.t;
	sq.x = s * q0.x;
	sq.y = s * q0.y;
	sq.z = s * q0.z;
	return sq;
}

