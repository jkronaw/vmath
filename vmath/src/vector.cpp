#include "vector.h"

/* ------ helper ------ */
bool floatEquals(float f1, float f2) {
	return fabs(f1 - f2) < EPSILON;
}

/* ------ constructors ------ */
Vector2::Vector2(float x, float y) : x(x), y(y) { }
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) { }
Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }

Vector3::Vector3(const Vector4& vector) {
	if (floatEquals(vector.z, 0.0))
	{
		y = vector.y;
		x = vector.x;
		z = vector.z;
	}
	else
	{
		y = vector.y / vector.w;
		x = vector.x / vector.w;
		z = vector.z / vector.w;
	}
}
Vector4::Vector4(const Vector3& vector) {
	x = vector.x;
	y = vector.y;
	z = vector.z;
	w = 1.0;
}
Vector4::Vector4(const Vector3& vector, const float scalar) {
	x = vector.x;
	y = vector.y;
	z = vector.z;
	w = scalar;
}

/* ------ scalar operators ------ */
Vector2 Vector2::operator*(const float scalar) const {
	return Vector2(x * scalar, y * scalar);
}
Vector2 Vector2::operator/(const float scalar) const {
	return Vector2(x / scalar, y / scalar);
}
Vector2 Vector2::operator+(const float scalar) const {
	return Vector2(x + scalar, y + scalar);
}
Vector2 Vector2::operator-(const float scalar) const {
	return Vector2(x - scalar, y - scalar);
}

Vector3 Vector3::operator*(const float scalar) const {
	return Vector3(x * scalar, y * scalar, z * scalar);
}
Vector3 Vector3::operator/(const float scalar) const {
	return Vector3(x / scalar, y / scalar, z / scalar);
}
Vector3 Vector3::operator+(const float scalar) const {
	return Vector3(x + scalar, y + scalar, z + scalar);
}
Vector3 Vector3::operator-(const float scalar) const {
	return Vector3(x - scalar, y - scalar, z - scalar);
}

Vector4 Vector4::operator*(const float scalar) const {
	return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
}
Vector4 Vector4::operator/(const float scalar) const {
	return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
}
Vector4 Vector4::operator+(const float scalar) const {
	return Vector4(x + scalar, y + scalar, z + scalar, w + scalar);
}
Vector4 Vector4::operator-(const float scalar) const {
	return Vector4(x - scalar, y - scalar, z - scalar, w - scalar);
}

Vector2 operator+(const float scalar, const Vector2& vector) { return vector + scalar; }
Vector2 operator-(const float scalar, const Vector2& vector) { return vector - scalar; }
Vector2 operator*(const float scalar, const Vector2& vector) { return vector * scalar; }
Vector2 operator/(const float scalar, const Vector2& vector) { return vector / scalar; }

Vector3 operator+(const float scalar, const Vector3& vector) { return vector + scalar; }
Vector3 operator-(const float scalar, const Vector3& vector) { return vector - scalar; }
Vector3 operator*(const float scalar, const Vector3& vector) { return vector * scalar; }
Vector3 operator/(const float scalar, const Vector3& vector) { return vector / scalar; }

Vector4 operator+(const float scalar, const Vector4& vector) { return vector + scalar; }
Vector4 operator-(const float scalar, const Vector4& vector) { return vector - scalar; }
Vector4 operator*(const float scalar, const Vector4& vector) { return vector * scalar; }
Vector4 operator/(const float scalar, const Vector4& vector) { return vector / scalar; }

/* ------ assignment operators ------ */
Vector2& Vector2::operator+=(const Vector2& vector) {
	x += vector.x;
	y += vector.y;
	return *this;
}
Vector2& Vector2::operator-=(const Vector2& vector) {
	x -= vector.x;
	y -= vector.y;
	return *this;
}
Vector2& Vector2::operator+=(const float scalar) {
	x += scalar;
	y += scalar;
	return *this;
}
Vector2& Vector2::operator-=(const float scalar) {
	x -= scalar;
	y -= scalar;
	return *this;
}
Vector2& Vector2::operator*=(const float scalar) {
	x *= scalar;
	y *= scalar;
	return *this;
}
Vector2& Vector2::operator/=(const float scalar) {
	x /= scalar;
	y /= scalar;
	return *this;
}

Vector3& Vector3::operator+=(const Vector3& vector) {
	x += vector.x;
	y += vector.y;
	z += vector.z;
	return *this;
}
Vector3& Vector3::operator-=(const Vector3& vector) {
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	return *this;
}
Vector3& Vector3::operator+=(const float scalar) {
	x += scalar;
	y += scalar;
	z += scalar;
	return *this;
}
Vector3& Vector3::operator-=(const float scalar) {
	x -= scalar;
	y -= scalar;
	z -= scalar;
	return *this;
}
Vector3& Vector3::operator*=(const float scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}
Vector3& Vector3::operator/=(const float scalar) {
	x /= scalar;
	y /= scalar;
	z /= scalar;
	return *this;
}

Vector4& Vector4::operator+=(const Vector4& vector) {
	x += vector.x;
	y += vector.y;
	z += vector.z;
	w += vector.w;
	return *this;
}
Vector4& Vector4::operator-=(const Vector4& vector) {
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	w -= vector.w;
	return *this;
}
Vector4& Vector4::operator+=(const float scalar) {
	x += scalar;
	y += scalar;
	z += scalar;
	w += scalar;
	return *this;
}
Vector4& Vector4::operator-=(const float scalar) {
	x -= scalar;
	y -= scalar;
	z -= scalar;
	w -= scalar;
	return *this;
}
Vector4& Vector4::operator*=(const float scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;
	return *this;
}
Vector4& Vector4::operator/=(const float scalar) {
	x /= scalar;
	y /= scalar;
	z /= scalar;
	w /= scalar;
	return *this;
}

/* ------ comparison operators ------ */
bool Vector2::operator==(const Vector2& vector) const {
	return floatEquals(x, vector.x) && floatEquals(y, vector.y);
}
bool Vector2::operator!=(const Vector2& vector) const {
	return !(*this == vector);
}

bool Vector3::operator==(const Vector3& vector) const {
	return floatEquals(x, vector.x) && floatEquals(y, vector.y) && floatEquals(z, vector.z);
}
bool Vector3::operator!=(const Vector3& vector) const {
	return !(*this == vector);
}

bool Vector4::operator==(const Vector4& vector) const {
	return floatEquals(x, vector.x) && floatEquals(y, vector.y) && floatEquals(z, vector.z) && floatEquals(w, vector.w);
}
bool Vector4::operator!=(const Vector4& vector) const {
	return !(*this == vector);
}

/* ------ vector operations ------ */
Vector2 Vector2::operator+(const Vector2& vector) const {
	return Vector2(x + vector.x, y + vector.y);
}
Vector2 Vector2::operator-(const Vector2& vector) const {
	return Vector2(x - vector.x, y - vector.y);
}

Vector3 Vector3::operator+(const Vector3& vector) const {
	return Vector3(x + vector.x, y + vector.y, z + vector.z);
}
Vector3 Vector3::operator-(const Vector3& vector) const {
	return Vector3(x - vector.x, y - vector.y, z - vector.z);
}

Vector4 Vector4::operator+(const Vector4& vector) const {
	return Vector4(x + vector.x, y + vector.y, z + vector.z, w + vector.w);
}
Vector4 Vector4::operator-(const Vector4& vector) const {
	return Vector4(x - vector.x, y - vector.y, z - vector.z, w - vector.w);
}

float Vector2::magnitude() const { return sqrt(x * x + y * y); }
float Vector3::magnitude() const { return sqrt(x * x + y * y + z * z); }
float Vector4::magnitude() const { return sqrt(x * x + y * y + z * z + w * w); }

float Vector2::dotProduct(const Vector2& vector) const {
	return x * vector.x + y * vector.y;
}
float Vector3::dotProduct(const Vector3& vector) const {
	return x * vector.x + y * vector.y + z * vector.z;
}
float Vector4::dotProduct(const Vector4& vector) const {
	return x * vector.x + y * vector.y + z * vector.z + w * vector.w;
}

Vector3 Vector3::crossProduct(const Vector3& vector) const {
	return Vector3(
		y * vector.z - z * vector.y,
		z * vector.x - x * vector.z,
		x * vector.y - y * vector.x
	);
}

Vector2 Vector2::normalized() const { return (*this) / magnitude(); }
Vector3 Vector3::normalized() const { return (*this) / magnitude(); }
Vector4 Vector4::normalized() const { return (*this) / magnitude(); }

void Vector2::normalize() { (*this) = (*this) / magnitude(); }
void Vector3::normalize() { (*this) = (*this) / magnitude(); }
void Vector4::normalize() { (*this) = (*this) / magnitude(); }

void Vector2::cleanToZero() {
	if (floatEquals(x, 0.0)) {
		x = 0.0;
	}

	if (floatEquals(y, 0.0)) {
		y = 0.0;
	}
}
void Vector3::cleanToZero() {
	if (floatEquals(x, 0.0)) {
		x = 0.0;
	}

	if (floatEquals(y, 0.0)) {
		y = 0.0;
	}

	if (floatEquals(z, 0.0)) {
		z = 0.0;
	}
}
void Vector4::cleanToZero() {
	if (floatEquals(x, 0.0)) {
		x = 0.0;
	}

	if (floatEquals(y, 0.0)) {
		y = 0.0;
	}

	if (floatEquals(z, 0.0)) {
		z = 0.0;
	}

	if (floatEquals(w, 0.0)) {
		w = 0.0;
	}
}

/* ------ special vectors ------ */
Vector3 Vector3::up() {
	return Vector3(0, 1, 0);
}

/* ------ IO ------ */
std::istream& operator>>(std::istream& is, Vector2& vector)
{
	is >> vector.x;
	is >> vector.y;
	return is;
}
std::istream& operator>>(std::istream& is, Vector3& vector)
{
	is >> vector.x;
	is >> vector.y;
	is >> vector.z;
	return is;
}
std::istream& operator>>(std::istream& is, Vector4& vector)
{
	is >> vector.x;
	is >> vector.y;
	is >> vector.z;
	is >> vector.w;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Vector2& vector)
{
	os << "[" << vector.x << ", " << vector.y << "]";
	return os;
}
std::ostream& operator<<(std::ostream& os, const Vector3& vector)
{
	os << "[" << vector.x << ", " << vector.y << ", " << vector.z << "]";
	return os;
}
std::ostream& operator<<(std::ostream& os, const Vector4& vector)
{
	os << "[" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << "]";
	return os;
}

/* ------ interpolation ------ */
Vector3 vLerp(const Vector3& v1, const Vector3& v2, float k)
{
	return v1 * (1 - k) + v2 * k;
}
