#pragma once

#include <Eigen/Dense>
#include <Eigen/src/SVD/JacobiSVD.h>

using namespace Eigen;

void Reconstruct(int point_count, float* test1, float* test2, float* p1, float* p2, float* w) {
	MatrixXf A(4, 3);
	Vector4f B;
	float x1, x2, y1, y2;
	for (int i = 0; i < point_count; i++) {
		x1 = test1[i * 2];
		y1 = test1[i * 2 + 1];
		x2 = test2[i * 2];
		y2 = test2[i * 2 + 1];
		A << x1 * p1[8] - p1[0], x1*p1[9] - p1[1], x1*p1[10] - p1[2],
			y1*p1[8] - p1[4], y1*p1[9] - p1[5], y1*p1[10] - p1[6],
			x2*p2[8] - p2[0], x2*p2[9] - p2[1], x2*p2[10] - p2[2],
			y2*p2[8] - p2[4], y2*p2[9] - p2[5], y2*p2[10] - p2[6];
		B << p1[3] - x1 * p1[11],
			p1[7] - y1 * p1[11],
			p2[3] - x2 * p2[11],
			p2[7] - y2 * p2[11];
		Vector3f solution;
		JacobiSVD<MatrixXf> svd(A, ComputeFullU | ComputeFullV);
		solution = svd.solve(B);
		w[i * 3 + 0] = solution(0);
		w[i * 3 + 1] = solution(1);
		w[i * 3 + 2] = solution(2);
	}
}

void Compute_Projection_Matrix(int point_count, float* world_points, float* image_points, float* A) {
	MatrixXf D(point_count * 2, 11);
	VectorXf R(point_count * 2);
	float X, Y, Z, x, y;
	for (int i = 0; i < point_count; i++) {
		X = world_points[i * 3];
		Y = world_points[i * 3 + 1];
		Z = world_points[i * 3 + 2];
		x = image_points[i * 2];
		y = image_points[i * 2 + 1];
		R(i * 2) = x;
		R(i * 2 + 1) = y;
		float current_point_data[22] = { X,Y,Z,1,0,0,0,0,-X * x,-Y * x,-Z * x,
			0,0,0,0,X,Y,Z,1,-X * y,-Y * y,-Z * y };
		for (int j = 0; j < 11; j++) {
			D(i * 2, j) = current_point_data[j];
			D(i * 2 + 1, j) = current_point_data[11 + j];
		}
	}

	VectorXf solution(11);
	JacobiSVD<MatrixXf> svd(D, ComputeFullU | ComputeFullV);
	solution = svd.solve(R);

	for (int i = 0; i < 11; i++) {
		A[i] = solution(i);
	}
	A[11] = 1;
}