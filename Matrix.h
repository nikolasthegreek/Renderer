#pragma once
class Matrix {
	private: float _Mtrx[4][4];//The Matrix data
	
	public:
		//basic characteristics and operations with matrixces
		Matrix();//Basic constructor
		~Matrix();//Destructor
		float GetMtrx(const int row, const int col);//Get fucntion to extract data from matrix
		void SetMtrx(const int row, const int col);//Set fuction to incer data to matrix
		const Matrix operator*(const Matrix& other);//multiplication fuction of matrixces 

		void Set(const Matrix& Copy);//copies another matrix
		void Wipe();//makes all values 0
		void SetIdentity();//sets ones on the main diagonal

		void SetRotX(float deg);//sets the matrix as a rotation matrix for the X axis
		void SetRotY(float deg);//sets the matrix as a rotation matrix for the Y axis
		void SetRotZ(float deg);//sets the matrix as a rotation matrix for the Z axis
		void SetTrans(float X,float Y,float Z);
		void SetScale(float X, float Y, float Z);
};