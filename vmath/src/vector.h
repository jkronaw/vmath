#pragma once

#include <iostream>

const float EPSILON = 0.00001f;

struct Vector2;
struct Vector3;
struct Vector4;

/* ------ Vector2 ------ */
struct Vector2 {
	Vector2() = default;
	Vector2(float, float);
	Vector2(const Vector2&) = default; // copy constructor
	~Vector2() = default;

	// scalar operators
	Vector2 operator*(const float) const;
	Vector2 operator/(const float) const;
	Vector2 operator+(const float) const;
	Vector2 operator-(const float) const;

	// assignment operators
	Vector2& operator=(const Vector2&) = default;
	Vector2& operator+=(const Vector2&);
	Vector2& operator-=(const Vector2&);
	Vector2& operator+=(const float);
	Vector2& operator-=(const float);
	Vector2& operator*=(const float);
	Vector2& operator/=(const float);

	// comparison operators
	bool operator==(const Vector2&) const;
	bool operator!=(const Vector2&) const;

	// vector operations
	Vector2 operator+(const Vector2&) const;
	Vector2 operator-(const Vector2&) const;
	float magnitude() const;
	float dotProduct(const Vector2&) const;
	Vector2 normalized() const;
	void normalize();
	void cleanToZero();

	// fields
	union {
		float x, u = 0.0;
	};
	union {
		float y, v = 0.0;
	};
};

// left side scalar operators
Vector2 operator+(const float, const Vector2&);
Vector2 operator-(const float, const Vector2&);
Vector2 operator*(const float, const Vector2&);
Vector2 operator/(const float, const Vector2&);

// IO
std::istream& operator>>(std::istream&, Vector2&);
std::ostream& operator<<(std::ostream&, const Vector2&);

/* ------ Vector3 ------ */
struct Vector3  {
	Vector3() = default;
	Vector3(float, float, float);
	Vector3(const Vector4&);
	Vector3(const Vector3&) = default; // copy constructor
	~Vector3() = default;

	// scalar operators
	Vector3 operator*(const float) const;
	Vector3 operator/(const float) const;
	Vector3 operator+(const float) const;
	Vector3 operator-(const float) const;

	// assignment operators
	Vector3& operator=(const Vector3&) = default;
	Vector3& operator+=(const Vector3&);
	Vector3& operator-=(const Vector3&);
	Vector3& operator+=(const float);
	Vector3& operator-=(const float);
	Vector3& operator*=(const float);
	Vector3& operator/=(const float);

	// comparison operators
	bool operator==(const Vector3&) const;
	bool operator!=(const Vector3&) const;

	// vector operations
	Vector3 operator+(const Vector3&) const;
	Vector3 operator-(const Vector3&) const;
	float magnitude() const;
	float dotProduct(const Vector3&) const;
	Vector3 crossProduct(const Vector3&) const;
	Vector3 normalized() const;
	void normalize();
	void cleanToZero();

	// special vectors
	static Vector3 up();

	// fields
	union {
		float x, r = 0.0;
	};
	union {
		float y, g = 0.0;
	};
	union {
		float z, b = 0.0;
	};
};

// left side scalar operators
Vector3 operator+(const float, const Vector3&);
Vector3 operator-(const float, const Vector3&);
Vector3 operator*(const float, const Vector3&);
Vector3 operator/(const float, const Vector3&);

// IO
std::istream& operator>>(std::istream&, Vector3&);
std::ostream& operator<<(std::ostream&, const Vector3&);

/* ------ Vector4 ------ */
struct Vector4 {
	Vector4() = default;
	Vector4(float, float, float, float);
	Vector4(const Vector3&);
	Vector4(const Vector3&, float);
	Vector4(const Vector4&) = default; // copy constructor
	~Vector4() = default;

	// scalar operators
	Vector4 operator*(const float) const;
	Vector4 operator/(const float) const;
	Vector4 operator+(const float) const;
	Vector4 operator-(const float) const;

	// assignment operators
	Vector4& operator=(const Vector4&) = default;
	Vector4& operator+=(const Vector4&);
	Vector4& operator-=(const Vector4&);
	Vector4& operator+=(const float);
	Vector4& operator-=(const float);
	Vector4& operator*=(const float);
	Vector4& operator/=(const float);

	// comparison operators
	bool operator==(const Vector4&) const;
	bool operator!=(const Vector4&) const;

	// vector operations
	Vector4 operator+(const Vector4&) const;
	Vector4 operator-(const Vector4&) const;
	float magnitude() const;
	float dotProduct(const Vector4&) const;
	Vector4 normalized() const;
	void normalize();
	void cleanToZero();

	// fields
	union {
		float x, r = 0.0;
	};
	union {
		float y, g = 0.0;
	};
	union {
		float z, b = 0.0;
	};
	union {
		float w, a = 0.0;
	};
};

// left side scalar operators
Vector4 operator+(const float, const Vector4&);
Vector4 operator-(const float, const Vector4&);
Vector4 operator*(const float, const Vector4&);
Vector4 operator/(const float, const Vector4&);

// IO
std::istream& operator>>(std::istream&, Vector4&);
std::ostream& operator<<(std::ostream&, const Vector4&);

// interpolation
Vector3 vLerp(const Vector3&, const Vector3&, float);