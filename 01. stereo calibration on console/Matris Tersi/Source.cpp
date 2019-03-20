#include <iostream>
#include <fstream>
#include <Eigen/Dense>
#include <Eigen/src/SVD/JacobiSVD.h>

using namespace std;
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
		A << x1*p1[8] - p1[0], x1*p1[9] - p1[1], x1*p1[10] - p1[2],
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
		//cout << solution << endl;
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

	//cout << D << endl;
	//cout << R << endl;

	VectorXf solution(11);
	JacobiSVD<MatrixXf> svd(D, ComputeFullU | ComputeFullV);
	solution = svd.solve(R);
	//cout << solution << endl;

	for (int i = 0; i < 11; i++) {
		A[i] = solution(i);
	}
	A[11] = 1;
}

void initFiles(int point_count, const char* left_path, const char* right_path, const char* world_path, float* C_1, float* C_2, float* w) {
	std::ifstream left;
	left.open(left_path);
	std::ifstream right;
	right.open(right_path);
	std::ifstream world;
	world.open(world_path);

	for (int i = 0; i < point_count; i++) {
		 left >> C_1[i * 2 + 0] >> C_1[i * 2 + 1];
		right >> C_2[i * 2 + 0] >> C_2[i * 2 + 1];
		world >> w[i * 3 + 0] >> w[i * 3 + 1] >> w[i * 3 + 2];
	}

	left.close();
	right.close();
	world.close();

	//for (int i = 0; i < point_count * 2; i++) {
	//	std::cout << C_1[i] << " ";
	//}
	//std::cout << std::endl;
	//for (int i = 0; i < point_count * 2; i++) {
	//	std::cout << C_2[i] << " ";
	//}
	//std::cout << std::endl;
	//for (int i = 0; i < point_count * 3; i++) {
	//	std::cout << w[i] << " ";
	//}
	//std::cout << std::endl;
}

int main() {
	/******************************************************************
	calibration
	*******************************************************************/
	const char* left = "image points left.txt";
	const char* right = "image points right.txt";
	const char* world = "world points.txt";
	int N = 19;
	float* c1 = new float[N * 2];
	float* c2 = new float[N * 2];
	float* w = new float[N * 3];
	initFiles(N, left, right, world, c1, c2, w);

	float* P1 = new float[12];
	float* P2 = new float[12];
	Compute_Projection_Matrix(N, w, c1, P1);	//computes projection matrix for first camera
	Compute_Projection_Matrix(N, w, c2, P2);	//computes projection matrix for second camera

	/*******************************************************************
	reconstruction
	********************************************************************/
	int test_count = 4;
	float* rw = new float[test_count * 3];
	float* t1 = new float[test_count * 2];
	float* t2 = new float[test_count * 2];
	
	ifstream test1;
	test1.open("test left.txt");
	ifstream test2;
	test2.open("test right.txt");
	
	for (int i = 0; i < test_count; i++) {
		test1 >> t1[i * 2] >> t1[i * 2 + 1];
		test2 >> t2[i * 2] >> t2[i * 2 + 1];
	}

	Reconstruct(test_count, t1, t2, P1, P2, rw);	//recovers the 3d positions from two camera and their projection matrices

	for (int i = 0; i < test_count; i++) {
		cout << rw[i * 3] << "     " << rw[i * 3 + 1] << "     " << rw[i * 3 + 2] << endl;
	}
	
	std::cin.get();
}