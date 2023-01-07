#include "Matrix.h"
#include <math.h>
#define PI 3.1415926535897932384626433832795

Matrix::Matrix(){
	Wipe();
}

Matrix::~Matrix(){}

float Matrix::GetMtrx(const int row, const int col)const {
	return _Mtrx[row][col];
}

void Matrix::SetMtrx(const int row, const int col, const float val) {
	_Mtrx[row][col] = val;
}

const Matrix Matrix::operator*(const Matrix& mult) {
	Matrix result;
	result.SetMtrx(0, 0, GetMtrx(0, 0) * mult.GetMtrx(0, 0) + GetMtrx(0, 1) * mult.GetMtrx(1, 0) + GetMtrx(0, 2) * mult.GetMtrx(2, 0) + GetMtrx(0, 3) * mult.GetMtrx(3, 0));
	result.SetMtrx(1, 0, GetMtrx(1, 0) * mult.GetMtrx(0, 0) + GetMtrx(1, 1) * mult.GetMtrx(1, 0) + GetMtrx(1, 2) * mult.GetMtrx(2, 0) + GetMtrx(1, 3) * mult.GetMtrx(3, 0));
	result.SetMtrx(2, 0, GetMtrx(2, 0) * mult.GetMtrx(0, 0) + GetMtrx(2, 1) * mult.GetMtrx(1, 0) + GetMtrx(2, 2) * mult.GetMtrx(2, 0) + GetMtrx(2, 3) * mult.GetMtrx(3, 0));
	result.SetMtrx(3, 0, GetMtrx(3, 0) * mult.GetMtrx(0, 0) + GetMtrx(3, 1) * mult.GetMtrx(1, 0) + GetMtrx(3, 2) * mult.GetMtrx(2, 0) + GetMtrx(3, 3) * mult.GetMtrx(3, 0));

	result.SetMtrx(0, 1, GetMtrx(0, 0) * mult.GetMtrx(0, 1) + GetMtrx(0, 1) * mult.GetMtrx(1, 1) + GetMtrx(0, 2) * mult.GetMtrx(2, 1) + GetMtrx(0, 3) * mult.GetMtrx(3, 1));
	result.SetMtrx(1, 1, GetMtrx(1, 0) * mult.GetMtrx(0, 1) + GetMtrx(1, 1) * mult.GetMtrx(1, 1) + GetMtrx(1, 2) * mult.GetMtrx(2, 1) + GetMtrx(1, 3) * mult.GetMtrx(3, 1));
	result.SetMtrx(2, 1, GetMtrx(2, 0) * mult.GetMtrx(0, 1) + GetMtrx(2, 1) * mult.GetMtrx(1, 1) + GetMtrx(2, 2) * mult.GetMtrx(2, 1) + GetMtrx(2, 3) * mult.GetMtrx(3, 1));
	result.SetMtrx(3, 1, GetMtrx(3, 0) * mult.GetMtrx(0, 1) + GetMtrx(3, 1) * mult.GetMtrx(1, 1) + GetMtrx(3, 2) * mult.GetMtrx(2, 1) + GetMtrx(3, 3) * mult.GetMtrx(3, 1));

	result.SetMtrx(0, 2, GetMtrx(0, 0) * mult.GetMtrx(0, 2) + GetMtrx(0, 1) * mult.GetMtrx(1, 2) + GetMtrx(0, 2) * mult.GetMtrx(2, 2) + GetMtrx(0, 3) * mult.GetMtrx(3, 2));
	result.SetMtrx(1, 2, GetMtrx(1, 0) * mult.GetMtrx(0, 2) + GetMtrx(1, 1) * mult.GetMtrx(1, 2) + GetMtrx(1, 2) * mult.GetMtrx(2, 2) + GetMtrx(1, 3) * mult.GetMtrx(3, 2));
	result.SetMtrx(2, 2, GetMtrx(2, 0) * mult.GetMtrx(0, 2) + GetMtrx(2, 1) * mult.GetMtrx(1, 2) + GetMtrx(2, 2) * mult.GetMtrx(2, 2) + GetMtrx(2, 3) * mult.GetMtrx(3, 2));
	result.SetMtrx(3, 2, GetMtrx(3, 0) * mult.GetMtrx(0, 2) + GetMtrx(3, 1) * mult.GetMtrx(1, 2) + GetMtrx(3, 2) * mult.GetMtrx(2, 2) + GetMtrx(3, 3) * mult.GetMtrx(3, 2));

	result.SetMtrx(0, 3, GetMtrx(0, 0) * mult.GetMtrx(0, 3) + GetMtrx(0, 1) * mult.GetMtrx(1, 3) + GetMtrx(0, 2) * mult.GetMtrx(2, 3) + GetMtrx(0, 3) * mult.GetMtrx(3, 3));
	result.SetMtrx(1, 3, GetMtrx(1, 0) * mult.GetMtrx(0, 3) + GetMtrx(1, 1) * mult.GetMtrx(1, 3) + GetMtrx(1, 2) * mult.GetMtrx(2, 3) + GetMtrx(1, 3) * mult.GetMtrx(3, 3));
	result.SetMtrx(2, 3, GetMtrx(2, 0) * mult.GetMtrx(0, 3) + GetMtrx(2, 1) * mult.GetMtrx(1, 3) + GetMtrx(2, 2) * mult.GetMtrx(2, 3) + GetMtrx(2, 3) * mult.GetMtrx(3, 3));
	result.SetMtrx(3, 3, GetMtrx(3, 0) * mult.GetMtrx(0, 3) + GetMtrx(3, 1) * mult.GetMtrx(1, 3) + GetMtrx(3, 2) * mult.GetMtrx(2, 3) + GetMtrx(3, 3) * mult.GetMtrx(3, 3));
	return result;
}

void Matrix::Set(const Matrix& copy) {
	for (int row=0; row<4; row++)
		for (int col=0; col<4; col++)
			_Mtrx[row][col] = copy.GetMtrx(row,col);
}
 
void Matrix::Wipe() {
	for (int row=0; row<4; row++)
		for (int col=0; col<4; col++)
			_Mtrx[row][col] = 0.0f;
}

void Matrix::SetIdentity() {
	Wipe();
	for (int i = 0; i < 4; i++){
		_Mtrx[i][i] = 1.0f;
	}
}

void Matrix::SetRotX(float deg) {
	float rad = deg * PI / 180.0f;
	SetIdentity();
	_Mtrx[0][0] = cos(rad); _Mtrx[0][2] = sin(rad);
	_Mtrx[2][0] = -sin(rad); _Mtrx[2][2] = cos(rad);
}

void Matrix::SetRotY(float deg) {
	float rad = deg * PI / 180.0f;
	SetIdentity();
	_Mtrx[0][0] = cos(rad); _Mtrx[0][2] = sin(rad);
	_Mtrx[2][0] = -sin(rad); _Mtrx[2][2] = cos(rad);
}

void Matrix::SetRotZ(float deg) {
	float rad = deg * PI / 180.0f;
	SetIdentity();
	_Mtrx[0][0] = cos(rad); _Mtrx[0][1] = -sin(rad);
	_Mtrx[1][0] = sin(rad); _Mtrx[1][1] = cos(rad);
}

void Matrix::SetTrans(float X, float Y, float Z) {
	SetIdentity();
	_Mtrx[0][3] = X;
	_Mtrx[1][3] = Y;
	_Mtrx[2][3] = Z;
}

void Matrix::SetScale(float X, float Y, float Z) {
	SetIdentity();
	_Mtrx[0][0] = X;
	_Mtrx[1][1] = Y;
	_Mtrx[2][2] = Z;
}

void Matrix::SetViewMatrix(const Vertex& camera_position, const Vertex& view_vector, const Vertex& up_vector) {
}


void Matrix::SetCamera(float RotX, float RotY, float RotZ, float PosX, float PosY, float PosZ) {
	Matrix Camera, CameraPos, CameraRotX, CameraRotY, CameraRotZ;
	CameraPos.SetTrans(-PosX, -PosY, -PosZ);
	CameraRotX.SetRotX(-RotX);
	CameraRotY.SetRotY(-RotY);
	CameraRotZ.SetRotZ(-RotZ);
	Camera = CameraPos*CameraRotZ;
	Camera = Camera * CameraRotY;
	Camera = Camera * CameraRotX;
	Set(Camera);
}

void Matrix::SetOrtho(float d) {
	Wipe();
	_Mtrx[0][0] = d;
	_Mtrx[1][1] = d;
	_Mtrx[2][2] = d;
	_Mtrx[3][3] = 1.0f;

}

void Matrix::SetPerspective(float d, float Ratio) {
	Wipe();
	_Mtrx[0][0] = -d / Ratio;
	_Mtrx[1][1] = -d;
	_Mtrx[2][2] = -d;
	_Mtrx[3][2] = 1.0f;

}

void Matrix::SetViewvolume(float left, float right, float bottom, float top, float front, float rear) {
	float width = right - left;
	float height = top - bottom;
	float depth = front - rear;
	SetIdentity();
	_Mtrx[0][0] = 1.0f / width;
	_Mtrx[1][1] = 1.0f / height;
	_Mtrx[2][2] = 1.0f / depth;
}

void Matrix::SetViewport(int left, int right, int top, int bottom) {
	int width = right - left;
	int height = bottom - top;
	SetIdentity();
	_Mtrx[0][0] = width;
	_Mtrx[1][1] = -height;
	_Mtrx[2][2] = 1.0f; //for keeping depth
	_Mtrx[0][3] = left + width / 2.0f;
	_Mtrx[1][3] = top + height / 2.0f;
	_Mtrx[2][3] = 0.0f; //depth buffer
}