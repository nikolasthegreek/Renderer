#pragma once

class Vertex {
public:
	Vertex();//default constructor
	Vertex(float X, float Y, float Z);//constructor with pos
	~Vertex();//destructor

	void Dehomogenise();
	void Normalise();
	float Length();

	float GetX() const;//returns X
	void SetX(const float x);//sets X
	float GetY() const;//returns Y
	void SetY(const float y);//Sets Y
	float GetZ() const;//returns Z
	void SetZ(const float z);//Sets Z
	float GetW() const;//returns W
	void SetW(const float w);//Sets W
	void Set(const Vertex& Copy);// copies a vertex

	bool operator== (const Vertex& Vert);//return if they are the same

	const Vertex operator+ (const Vertex& Vert) const;//adds all components
	const Vertex operator- (const Vertex& Vert) const;//subracts all components

	float DotProduct(const Vertex& Vert) const;//returns dot product
	Vertex CrossProduct(const Vertex& Vert) const;//returns cross product

private://vertex data
	float _X;
	float _Y;
	float _Z;
	float _W;
};