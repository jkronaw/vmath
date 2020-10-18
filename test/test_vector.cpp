#include "pch.h"

#include "../vmath/src/vector.h"
#include "../vmath/src/matrix.h"


/* ------ Vector2 ------*/
TEST(TestVector2, TestConstructor) {
	
	Vector2 vec = Vector2();
	EXPECT_FLOAT_EQ(vec.x, 0);
	EXPECT_FLOAT_EQ(vec.y, 0);

	Vector2 vec1 = Vector2(5, 2.1);
	EXPECT_FLOAT_EQ(vec1.x, 5);
	EXPECT_FLOAT_EQ(vec1.y, 2.1);

	Vector2 vec2 = Vector2(vec1);
	EXPECT_FLOAT_EQ(vec2.x, 5);
	EXPECT_FLOAT_EQ(vec2.y, 2.1);
}

TEST(TestVector2, TestAddition) {
	Vector2 vec1 = Vector2(2.1, 2);
	Vector2 vec2 = Vector2(10, 20);
	vec1 = vec1 + vec2;
	EXPECT_FLOAT_EQ(vec1.x, 12.1);
	EXPECT_FLOAT_EQ(vec1.y, 22);
}

TEST(TestVector2, TestSubstraction) {
	Vector2 vec1 = Vector2(2.1, 2);
	Vector2 vec2 = Vector2(10, 20);
	vec1 = vec1 - vec2;
	EXPECT_FLOAT_EQ(vec1.x, -7.9);
	EXPECT_FLOAT_EQ(vec1.y, -18);
}

TEST(TestVector2, TestMultiplication) {
	Vector2 vec = Vector2(2.1, 2.0);
	vec = vec * 2.0;
	EXPECT_FLOAT_EQ(vec.x, 4.2);
	EXPECT_FLOAT_EQ(vec.y, 4.0);
}

TEST(TestVector2, TestDivision) {
	Vector2 vec = Vector2(2.1, 2);
	vec = vec / 2;
	EXPECT_FLOAT_EQ(vec.x, 1.05);
	EXPECT_FLOAT_EQ(vec.y, 1);
}

TEST(TestVector2, TestScalarAddition) {
	Vector2 vec = Vector2(2.1, 2);
	vec = vec + 4;
	EXPECT_FLOAT_EQ(vec.x, 6.1);
	EXPECT_FLOAT_EQ(vec.y, 6);
}

TEST(TestVector2, TestScalarSubstraction) {
	Vector2 vec = Vector2(2.1, 2);
	vec = vec - 0.1;
	EXPECT_FLOAT_EQ(vec.x, 2);
	EXPECT_FLOAT_EQ(vec.y, 1.9);
}

TEST(TestVector2, TestAssignAddition) {
	Vector2 vec1 = Vector2(2.1, 2);
	Vector2 vec2 = Vector2(10, 20);
	vec1 += vec2;
	EXPECT_FLOAT_EQ(vec1.x, 12.1);
	EXPECT_FLOAT_EQ(vec1.y, 22);
}

TEST(TestVector2, TestAssigntSubstraction) {
	Vector2 vec1 = Vector2(2.1, 2);
	Vector2 vec2 = Vector2(10, 20);
	vec1 -= vec2;
	EXPECT_FLOAT_EQ(vec1.x, -7.9);
	EXPECT_FLOAT_EQ(vec1.y, -18);
}

TEST(TestVector2, TestAssignMultiplication) {
	Vector2 vec = Vector2(2.1, 2);
	vec *= 2;
	EXPECT_FLOAT_EQ(vec.x, 4.2);
	EXPECT_FLOAT_EQ(vec.y, 4);
}

TEST(TestVector2, TestAssignDivision) {
	Vector2 vec = Vector2(2.4, 2);
	vec /= 2.0;
	EXPECT_FLOAT_EQ(vec.x, 1.2);
	EXPECT_FLOAT_EQ(vec.y, 1);
}

TEST(TestVector2, TestDotProduct) {
	Vector2 vec1 = Vector2(2.4, 2);
	Vector2 vec2 = Vector2(1, 2);
	float res =  vec1.dotProduct(vec2);
	EXPECT_FLOAT_EQ(res, 6.4);
}

TEST(TestVector2, TestLeftSideMultiplication) {
	Vector2 vec = Vector2(2.1, 2.0);
	vec = 2.0 * vec;
	EXPECT_FLOAT_EQ(vec.x, 4.2);
	EXPECT_FLOAT_EQ(vec.y, 4.0);
}

TEST(TestVector2, TestLeftSideScalarAddition) {
	Vector2 vec = Vector2(2.1, 2);
	vec = 4 + vec;
	EXPECT_FLOAT_EQ(vec.x, 6.1);
	EXPECT_FLOAT_EQ(vec.y, 6);
}

TEST(TestVector2, TestEqual) {
	Vector2 vec1 = Vector2(2.1, 2);
	Vector2 vec2 = Vector2(2.1, 2.0);
	EXPECT_TRUE(vec1 == vec2);
}

TEST(TestVector2, TestDiffrent) {
	Vector2 vec1 = Vector2(2.01, 2);
	Vector2 vec2 = Vector2(2.1, 2.0);
	EXPECT_TRUE(vec1 != vec2);
}

TEST(TestVector2, TestMagnitude) {
	Vector2 vec = Vector2(4, 3);
	float n = vec.magnitude();
	EXPECT_FLOAT_EQ(n, 5);
}

/* ------ Vector3 ------*/
TEST(TestVector3, TestConstructor) {

	Vector3 vec = Vector3();
	EXPECT_FLOAT_EQ(vec.x, 0);
	EXPECT_FLOAT_EQ(vec.y, 0);
	EXPECT_FLOAT_EQ(vec.z, 0);

	Vector3 vec1 = Vector3(5, 2.1, 3.05);
	EXPECT_FLOAT_EQ(vec1.x, 5);
	EXPECT_FLOAT_EQ(vec1.y, 2.1);
	EXPECT_FLOAT_EQ(vec1.z, 3.05);

	Vector3 vec2 = Vector3(vec1);
	EXPECT_FLOAT_EQ(vec2.x, 5);
	EXPECT_FLOAT_EQ(vec2.y, 2.1);
	EXPECT_FLOAT_EQ(vec2.z, 3.05);
}

TEST(TestVector3, TestAddition) {
	Vector3 vec1 = Vector3(2.1, 2, 3);
	Vector3 vec2 = Vector3(10, 20, -1);
	vec1 = vec1 + vec2;
	EXPECT_FLOAT_EQ(vec1.x, 12.1);
	EXPECT_FLOAT_EQ(vec1.y, 22);
	EXPECT_FLOAT_EQ(vec1.z, 2);
}

TEST(TestVector3, TestSubstraction) {
	Vector3 vec1 = Vector3(2.1, 2, 3);
	Vector3 vec2 = Vector3(10, 20, -1);
	vec1 = vec1 - vec2;
	EXPECT_FLOAT_EQ(vec1.x, -7.9);
	EXPECT_FLOAT_EQ(vec1.y, -18);
	EXPECT_FLOAT_EQ(vec1.z, 4);
}

TEST(TestVector3, TestMultiplication) {
	Vector3 vec = Vector3(2.1, 2.0, 3);
	vec = vec * 2.0;
	EXPECT_FLOAT_EQ(vec.x, 4.2);
	EXPECT_FLOAT_EQ(vec.y, 4.0);
	EXPECT_FLOAT_EQ(vec.z, 6.0);
}

TEST(TestVector3, TestDivision) {
	Vector3 vec = Vector3(2.1, 2, 3);
	vec = vec / 2;
	EXPECT_FLOAT_EQ(vec.x, 1.05);
	EXPECT_FLOAT_EQ(vec.y, 1);
	EXPECT_FLOAT_EQ(vec.z, 1.5);

}

TEST(TestVector3, TestScalarAddition) {
	Vector3 vec = Vector3(2.1, 2, 3);
	vec = vec + 4;
	EXPECT_FLOAT_EQ(vec.x, 6.1);
	EXPECT_FLOAT_EQ(vec.y, 6);
	EXPECT_FLOAT_EQ(vec.z, 7);
}

TEST(TestVector3, TestScalarSubstraction) {
	Vector3 vec = Vector3(2.1, 2, 3);
	vec = vec - 0.1;
	EXPECT_FLOAT_EQ(vec.x, 2);
	EXPECT_FLOAT_EQ(vec.y, 1.9);
	EXPECT_FLOAT_EQ(vec.z, 2.9);
}

TEST(TestVector3, TestAssignAddition) {
	Vector3 vec1 = Vector3(2.1, 2, 3);
	Vector3 vec2 = Vector3(10, 20, -1);
	vec1 += vec2;
	EXPECT_FLOAT_EQ(vec1.x, 12.1);
	EXPECT_FLOAT_EQ(vec1.y, 22);
	EXPECT_FLOAT_EQ(vec1.z, 2);
}

TEST(TestVector3, TestAssigntSubstraction) {
	Vector3 vec1 = Vector3(2.1, 2, 3);
	Vector3 vec2 = Vector3(10, 20, -1);
	vec1 -= vec2;
	EXPECT_FLOAT_EQ(vec1.x, -7.9);
	EXPECT_FLOAT_EQ(vec1.y, -18);
	EXPECT_FLOAT_EQ(vec1.z, 4);
}

TEST(TestVector3, TestAssignMultiplication) {
	Vector3 vec = Vector3(2.1, 2, 3);
	vec *= 2;
	EXPECT_FLOAT_EQ(vec.x, 4.2);
	EXPECT_FLOAT_EQ(vec.y, 4);
	EXPECT_FLOAT_EQ(vec.z, 6);
}

TEST(TestVector3, TestAssignDivision) {
	Vector3 vec = Vector3(2.4, 2, 3);
	vec /= 2.0;
	EXPECT_FLOAT_EQ(vec.x, 1.2);
	EXPECT_FLOAT_EQ(vec.y, 1);
	EXPECT_FLOAT_EQ(vec.z, 1.5);
}

TEST(TestVector3, TestDotProduct) {
	Vector3 vec1 = Vector3(2.4, 2, 3);
	Vector3 vec2 = Vector3(1, 2, -1);
	float res = vec1.dotProduct(vec2);
	EXPECT_FLOAT_EQ(res, 3.4);
}

TEST(TestVector3, TestCrossProduct) {
	Vector3 vec1 = Vector3(2.4, 2, 3);
	Vector3 vec2 = Vector3(1, 2, -1);
	vec1 = vec1.crossProduct(vec2);
	EXPECT_FLOAT_EQ(vec1.x, -8);
	EXPECT_FLOAT_EQ(vec1.y, 5.4);
	EXPECT_FLOAT_EQ(vec1.z, 2.8);
}

TEST(TestVector3, TestLeftSideMultiplication) {
	Vector3 vec = Vector3(2.1, 2.0, 3);
	vec = 2.0 * vec;
	EXPECT_FLOAT_EQ(vec.x, 4.2);
	EXPECT_FLOAT_EQ(vec.y, 4.0);
	EXPECT_FLOAT_EQ(vec.z, 6.0);
}

TEST(TestVector3, TestLeftSideScalarAddition) {
	Vector3 vec = Vector3(2.1, 2, 3);
	vec = 4 + vec;
	EXPECT_FLOAT_EQ(vec.x, 6.1);
	EXPECT_FLOAT_EQ(vec.y, 6);
	EXPECT_FLOAT_EQ(vec.z, 7);
}

TEST(TestVector3, TestEqual) {
	Vector3 vec1 = Vector3(2.1, 2, 5.999);
	Vector3 vec2 = Vector3(2.1, 2.0, 5.999);
	EXPECT_TRUE(vec1 == vec2);
}

TEST(TestVector3, TestDiffrent) {
	Vector3 vec1 = Vector3(2.01, 2, 4.9);
	Vector3 vec2 = Vector3(2.1, 2.0, 4.8999);
	EXPECT_TRUE(vec1 != vec2);
}

TEST(TestVector3, TestMagnitude) {
	Vector3 vec = Vector3(4, 3, 2);
	float n = vec.magnitude();
	float res = sqrt(29);
	EXPECT_FLOAT_EQ(n, res);
}

/* ------ Vector4 ------*/
TEST(TestVector4, TestConstructor) {

	Vector4 vec = Vector4();
	EXPECT_FLOAT_EQ(vec.x, 0);
	EXPECT_FLOAT_EQ(vec.y, 0);
	EXPECT_FLOAT_EQ(vec.z, 0);
	EXPECT_FLOAT_EQ(vec.w, 0);

	Vector4 vec1 = Vector4(5, 2.1, 3.05, 1);
	EXPECT_FLOAT_EQ(vec1.x, 5);
	EXPECT_FLOAT_EQ(vec1.y, 2.1);
	EXPECT_FLOAT_EQ(vec1.z, 3.05);
	EXPECT_FLOAT_EQ(vec1.w, 1);

	Vector4 vec2 = Vector4(vec1);
	EXPECT_FLOAT_EQ(vec2.x, 5);
	EXPECT_FLOAT_EQ(vec2.y, 2.1);
	EXPECT_FLOAT_EQ(vec2.z, 3.05);
	EXPECT_FLOAT_EQ(vec2.w, 1);
}

TEST(TestVector4, TestAddition) {
	Vector4 vec1 = Vector4(2.1, 2, 3, 1);
	Vector4 vec2 = Vector4(10, 20, -1, 1);
	vec1 = vec1 + vec2;
	EXPECT_FLOAT_EQ(vec1.x, 12.1);
	EXPECT_FLOAT_EQ(vec1.y, 22);
	EXPECT_FLOAT_EQ(vec1.z, 2);
	EXPECT_FLOAT_EQ(vec1.w, 2);
}

TEST(TestVector4, TestSubstraction) {
	Vector4 vec1 = Vector4(2.1, 2, 3, 1);
	Vector4 vec2 = Vector4(10, 20, -1, 1);
	vec1 = vec1 - vec2;
	EXPECT_FLOAT_EQ(vec1.x, -7.9);
	EXPECT_FLOAT_EQ(vec1.y, -18);
	EXPECT_FLOAT_EQ(vec1.z, 4);
	EXPECT_FLOAT_EQ(vec1.w, 0);
}

TEST(TestVector4, TestMultiplication) {
	Vector4 vec = Vector4(2.1, 2.0, 3, 1);
	vec = vec * 2.0;
	EXPECT_FLOAT_EQ(vec.x, 4.2);
	EXPECT_FLOAT_EQ(vec.y, 4.0);
	EXPECT_FLOAT_EQ(vec.z, 6.0);
	EXPECT_FLOAT_EQ(vec.w, 2);
}

TEST(TestVector4, TestDivision) {
	Vector4 vec = Vector4(2.1, 2, 3, 1);
	vec = vec / 2;
	EXPECT_FLOAT_EQ(vec.x, 1.05);
	EXPECT_FLOAT_EQ(vec.y, 1);
	EXPECT_FLOAT_EQ(vec.z, 1.5);
	EXPECT_FLOAT_EQ(vec.w, 0.5);
}

TEST(TestVector4, TestScalarAddition) {
	Vector4 vec = Vector4(2.1, 2, 3, 1);
	vec = vec + 4;
	EXPECT_FLOAT_EQ(vec.x, 6.1);
	EXPECT_FLOAT_EQ(vec.y, 6);
	EXPECT_FLOAT_EQ(vec.z, 7);
	EXPECT_FLOAT_EQ(vec.w, 5);
}

TEST(TestVector4, TestScalarSubstraction) {
	Vector4 vec = Vector4(2.1, 2, 3, 2.56);
	vec = vec - 0.1;
	EXPECT_FLOAT_EQ(vec.x, 2);
	EXPECT_FLOAT_EQ(vec.y, 1.9);
	EXPECT_FLOAT_EQ(vec.z, 2.9);
	EXPECT_FLOAT_EQ(vec.w, 2.46);
}

TEST(TestVector4, TestAssignAddition) {
	Vector4 vec1 = Vector4(2.1, 2, 3, 1);
	Vector4 vec2 = Vector4(10, 20, -1, 1);
	vec1 += vec2;
	EXPECT_FLOAT_EQ(vec1.x, 12.1);
	EXPECT_FLOAT_EQ(vec1.y, 22);
	EXPECT_FLOAT_EQ(vec1.z, 2);
	EXPECT_FLOAT_EQ(vec1.w, 2);
}

TEST(TestVector4, TestAssigntSubstraction) {
	Vector4 vec1 = Vector4(2.1, 2, 3, 1);
	Vector4 vec2 = Vector4(10, 20, -1, 1);
	vec1 -= vec2;
	EXPECT_FLOAT_EQ(vec1.x, -7.9);
	EXPECT_FLOAT_EQ(vec1.y, -18);
	EXPECT_FLOAT_EQ(vec1.z, 4);
	EXPECT_FLOAT_EQ(vec1.w, 0);
}

TEST(TestVector4, TestAssignMultiplication) {
	Vector4 vec = Vector4(2.1, 2, 3, 1);
	vec *= 2;
	EXPECT_FLOAT_EQ(vec.x, 4.2);
	EXPECT_FLOAT_EQ(vec.y, 4);
	EXPECT_FLOAT_EQ(vec.z, 6);
	EXPECT_FLOAT_EQ(vec.w, 2);
}

TEST(TestVector4, TestAssignDivision) {
	Vector4 vec = Vector4(2.4, 2, 3, 1);
	vec /= 2.0;
	EXPECT_FLOAT_EQ(vec.x, 1.2);
	EXPECT_FLOAT_EQ(vec.y, 1);
	EXPECT_FLOAT_EQ(vec.z, 1.5);
	EXPECT_FLOAT_EQ(vec.w, 0.5);
}

TEST(TestVector4, TestDotProduct) {
	Vector4 vec1 = Vector4(2.4, 2, 3, 0);
	Vector4 vec2 = Vector4(1, 2, -1, 450);
	float res = vec1.dotProduct(vec2);
	EXPECT_FLOAT_EQ(res, 3.4);
}

TEST(TestVector4, TestLeftSideMultiplication) {
	Vector4 vec = Vector4(2.1, 2.0, 3, 1);
	vec = 2 * vec;
	EXPECT_FLOAT_EQ(vec.x, 4.2);
	EXPECT_FLOAT_EQ(vec.y, 4.0);
	EXPECT_FLOAT_EQ(vec.z, 6.0);
	EXPECT_FLOAT_EQ(vec.w, 2);
}

TEST(TestVector4, TestLeftSideScalarAddition) {
	Vector4 vec = Vector4(2.1, 2, 3, 1);
	vec = 4 + vec;
	EXPECT_FLOAT_EQ(vec.x, 6.1);
	EXPECT_FLOAT_EQ(vec.y, 6);
	EXPECT_FLOAT_EQ(vec.z, 7);
	EXPECT_FLOAT_EQ(vec.w, 5);
}

TEST(TestVector4, TestEqual) {
	Vector4 vec1 = Vector4(2.1, 2, 5.999, 0);
	Vector4 vec2 = Vector4(2.1, 2.0, 5.999, 0.0);
	EXPECT_TRUE(vec1 == vec2);
}

TEST(TestVector4, TestDiffrent) {
	Vector4 vec1 = Vector4(2.01, 2, 4.9, 0.001);
	Vector4 vec2 = Vector4(2.1, 2.0, 4.8999, 0.0);
	EXPECT_TRUE(vec1 != vec2);
}

TEST(TestVector4, TestMagnitude) {
	Vector4 vec = Vector4(4, 3, 2, 1);
	float n = vec.magnitude();
	float res = sqrt(30);
	EXPECT_FLOAT_EQ(n, res);
}
