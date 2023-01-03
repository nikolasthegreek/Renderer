#include "Matrix.h"
#include <math.h>

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