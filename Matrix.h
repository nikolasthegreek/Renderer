#pragma once
#include"Vertex.h"

class Matrix {
	private: float _Mtrx[4][4];//The Matrix data
	
	public:
		//basic characteristics and operations with matrixces
		Matrix();//Basic constructor
		~Matrix();//Destructor
		float GetMtrx(const int row, const int col)const;//Get fucntion to extract data from matrix
		void SetMtrx(const int row, const int col, const float val);//Set fuction to incer data to matrix
		const Matrix operator*(const Matrix& mult);//multiplication fuction of matrixes 

		void Set(const Matrix& copy);//copies another matrix
		void Wipe();//makes all values 0
		void SetIdentity();//sets ones on the main diagonal

		void SetRotX(float deg);//sets the matrix as a rotation matrix for the X axis
		void SetRotY(float deg);//sets the matrix as a rotation matrix for the Y axis
		void SetRotZ(float deg);//sets the matrix as a rotation matrix for the Z axis
		void SetTrans(float X,float Y,float Z);
		void SetScale(float X, float Y, float Z);

		//camera related functions
		void SetViewMatrix(const Vertex& camera_position, const Vertex& view_vector, const Vertex& up_vector);//sets the view matrix
		void SetCamera(float xRotation, float yRotation, float zRotation, float xPosition, float yPosition, float zPosition);//sets the position and rotation of the cammera
		void SetOrtho(float d);
		void SetPerspective(float d, float aspectRatio);
		void SetViewvolume(float left, float right, float bottom, float top, float front, float rear);
		void SetViewport(int left, int right, int top, int bottom);
};