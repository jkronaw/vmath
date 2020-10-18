#pragma once

#include <iostream>
#include "vector.h"

struct Matrix2;
struct Matrix3;
struct Matrix4;

/* ------ Matrix2 ------ */
struct Matrix2 {
	Matrix2() = default;
	Matrix2(float, float, float, float);
	Matrix2(const Vector2&, const Vector2&);
	Matrix2(const Matrix2&) = default; // copy constructor
	~Matrix2() = default;

	// scalar operators
	Matrix2 operator+(const float) const;
	Matrix2 operator-(const float) const;
	Matrix2 operator*(const float) const;
	Matrix2 operator/(const float) const;

	// assignment operators
	Matrix2& operator=(const Matrix2&) = default;
	Matrix2& operator+=(const Matrix2&);
	Matrix2& operator-=(const Matrix2&);
	Matrix2& operator+=(const float);
	Matrix2& operator-=(const float);
	Matrix2& operator*=(const float);
	Matrix2& operator/=(const float);

	// comparison operators
	bool operator==(const Matrix2&) const;
	bool operator!=(const Matrix2&) const;

	// matrix operations
	Matrix2 operator+(const Matrix2&) const;
	Matrix2 operator-(const Matrix2&) const;
	Matrix2 multiply(const Matrix2&) const; // matrix multiplication
	Vector2 multiply(const Vector2&) const; // matrix multiplication
	float determinant() const;
	Matrix2 inversed() const;
	void inverse();
	Matrix2 transposed() const;
	void transpose();

	// OpenGL
	void convertToOpenGL(float*);

	// special matrices
	static Matrix2 IdentityMatrix();

	// fields
	Vector2 rows[2];
};

// left side scalar operators
Matrix2 operator+(const float, const Matrix2&);
Matrix2 operator-(const float, const Matrix2&);
Matrix2 operator*(const float, const Matrix2&);
Matrix2 operator/(const float, const Matrix2&);

// IO
std::istream& operator>>(std::istream&, Matrix2&);
std::ostream& operator<<(std::ostream&, const Matrix2&);


/* ------ Matrix3 ------*/
struct Matrix3 {
	Matrix3() = default;
	Matrix3(float, float, float,
			float, float, float,
			float, float, float);
	Matrix3(const Vector3&, const Vector3&, const Vector3&);
	Matrix3(const Matrix4&);
	Matrix3(const Matrix3&) = default; // copy constructor
	~Matrix3() = default;

	// scalar operators
	Matrix3 operator+(const float) const;
	Matrix3 operator-(const float) const;
	Matrix3 operator*(const float) const;
	Matrix3 operator/(const float) const;

	// assignment operators
	Matrix3& operator=(const Matrix3&) = default;
	Matrix3& operator+=(const Matrix3&);
	Matrix3& operator-=(const Matrix3&);
	Matrix3& operator+=(const float);
	Matrix3& operator-=(const float);
	Matrix3& operator*=(const float);
	Matrix3& operator/=(const float);

	// comparison operators
	bool operator==(const Matrix3&) const;
	bool operator!=(const Matrix3&) const;

	// matrix operations
	Matrix3 operator+(const Matrix3&) const;
	Matrix3 operator-(const Matrix3&) const;
	Matrix3 multiply(const Matrix3&) const; // matrix multiplication
	Vector3 multiply(const Vector3&) const; // matrix multiplication
	float determinant() const;
	Matrix3 inversed() const;
	void inverse();
	Matrix3 transposed() const;
	void transpose();

	// OpenGL
	void convertToOpenGL(float*);

	// special matrices
	static Matrix3 IdentityMatrix();
	static Matrix3 DualMatrix(const Vector3&);

	// fields
	Vector3 rows[3];
};

// left side scalar operators
Matrix3 operator+(const float, const Matrix3&);
Matrix3 operator-(const float, const Matrix3&);
Matrix3 operator*(const float, const Matrix3&);
Matrix3 operator/(const float, const Matrix3&);

// IO
std::istream& operator>>(std::istream&, Matrix3&);
std::ostream& operator<<(std::ostream&, const Matrix3&);


/* ------ Matrix4 ------*/
struct Matrix4 {
	Matrix4() = default;
	Matrix4(float, float, float, float,
			float, float, float, float,
			float, float, float, float,
			float, float, float, float);
	Matrix4(const Vector4&, const Vector4&, const Vector4&, const Vector4&);
	Matrix4(const Matrix4&) = default; // copy constructor
	~Matrix4() = default;

	// scalar operators
	Matrix4 operator+(const float) const;
	Matrix4 operator-(const float) const;
	Matrix4 operator*(const float) const;
	Matrix4 operator/(const float) const;

	// assignment operators
	Matrix4& operator=(const Matrix4&) = default;
	Matrix4& operator+=(const Matrix4&);
	Matrix4& operator-=(const Matrix4&);
	Matrix4& operator+=(const float);
	Matrix4& operator-=(const float);
	Matrix4& operator*=(const float);
	Matrix4& operator/=(const float);

	// comparison operators
	bool operator==(const Matrix4&) const;
	bool operator!=(const Matrix4&) const;

	// matrix operations
	Matrix4 operator+(const Matrix4&) const;
	Matrix4 operator-(const Matrix4&) const;
	Matrix4 multiply(const Matrix4&) const; // matrix multiplication
	Vector4 multiply(const Vector4&) const; // matrix multiplication
	Matrix4 transposed() const;
	void transpose();

	// OpenGL
	void convertToOpenGL(float*);

	// special matrices
	static Matrix4 IdentityMatrix();
	static Matrix4 ScalingMatrix(float, float, float);
	static Matrix4 TranslationMatrix(float, float, float);
	static Matrix4 CreateRotationX(float);
	static Matrix4 CreateRotationY(float);
	static Matrix4 CreateRotationZ(float);

	// fields
	Vector4 rows[4];
};

// left side scalar operators
Matrix4 operator+(const float, const Matrix4&);
Matrix4 operator-(const float, const Matrix4&);
Matrix4 operator*(const float, const Matrix4&);
Matrix4 operator/(const float, const Matrix4&);

// IO
std::istream& operator>>(std::istream&, Matrix4&);
std::ostream& operator<<(std::ostream&, const Matrix4&);