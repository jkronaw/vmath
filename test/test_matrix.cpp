#include "pch.h"

#include "../vmath/src/vector.h"
#include "../vmath/src/matrix.h"

TEST(TestMatrix2, determinant) {
	Matrix2 mat(1.0, -2.0, 3, 7);
	float result = mat.determinant();
	ASSERT_FLOAT_EQ(result, 13.0);
}

TEST(TestMatrix3, determinant) {
	Matrix3 mat(1, 2, 3, 0, 1, 4, 5, 6, 0);
	float result = mat.determinant();
	ASSERT_FLOAT_EQ(result, 1.0);
}

TEST(TestMatrix2, inversed) {
	Matrix2 mat(1.0, -2.0, 3, 7);
	Matrix2 inv = mat.inversed();
	Matrix2 expected = Matrix2(7, 2, -3, 1) / 13.0;
	ASSERT_TRUE(inv == expected);
}

TEST(TestMatrix3, inversed) {
	Matrix3 mat(1, 2, 3, 0, 1, 4, 5, 6, 0);
	Matrix3 inv = mat.inversed();
	Matrix3 expected = Matrix3(-24, 18, 5, 20, -15, -4, -5, 4, 1);
	ASSERT_TRUE(inv == expected);
}

TEST(TestMatrix3, inverse) {
	Matrix3 mat(1, 2, 3, 0, 1, 4, 5, 6, 0);
	mat.inverse();
	Matrix3 expected = Matrix3(-24, 18, 5, 20, -15, -4, -5, 4, 1);
	ASSERT_TRUE(mat == expected);
}

TEST(TestMatrix3, dualmatrix) {
	Vector3 a(1.0, 1.0, 1.0);
	Vector3 b(1.0, 0.0, 2.0);
	ASSERT_TRUE(a.crossProduct(b) == Matrix3::DualMatrix(a).multiply(b));
}

TEST(TestMatrix2, ConvertToOpenGL) {
	Matrix2 mat(1.0, -2.0, 3, 7);
	float res[4];
	mat.convertToOpenGL(res);
	ASSERT_FLOAT_EQ(res[0], 1.0);
	ASSERT_FLOAT_EQ(res[1], 3);
	ASSERT_FLOAT_EQ(res[2], -2.0);
	ASSERT_FLOAT_EQ(res[3], 7);
}


