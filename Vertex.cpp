#include "Vertex.h"
#include <math.h>

Vertex::Vertex()
{
	_X = 0.0f;
	_Y = 0.0f;
	_Z = 0.0f;
	_W = 1.0f;
}

Vertex::Vertex(float x, float y, float z)
{
	_X = x;
	_Y = y;
	_Z = z;
	_W = 1.0f;
}

Vertex::Vertex(const Vertex& v) {
	_X = v.GetX();
	_Y = v.GetY();
	_Z = v.GetZ();
	_W = v.GetW();
}

Vertex::~Vertex() {}

void Vertex::Dehomogenise() {
	_X = _X / _W;
	_Y = _Y / _W;
	_Z = _Z / _W;
	_W = 1.0f;
}

float Vertex::Length() {
	Dehomogenise();
	return sqrt(_X * _X + _Y * _Y + _Z * _Z);
}

void Vertex::Normalise() {
	Dehomogenise();
	float len = Length();
	_X = _X / len;
	_Y = _Y / len;
	_Z = _Z / len;
	_W = 1.0f;
}


float Vertex::GetX() const {
	return _X;
}

void Vertex::SetX(const float x) {
	_X = x;
}

float Vertex::GetY() const {
	return _Y;
}

void Vertex::SetY(const float y) {
	_Y = y;
}

float Vertex::GetZ() const {
	return _Z;
}

void Vertex::SetZ(const float z) {
	_Z = z;
}

float Vertex::GetW() const {
	return _W;
}

void Vertex::SetW(const float w) {
	_W = w;
}
bool Vertex::operator==(const Vertex& Vect) const
{
	//They have to be dehomogenised before the comparison
	return ((_Z == Vect.GetX()) && (_Y == Vect.GetY()) && (_Z == Vect.GetZ()));
}

const Vertex Vertex::operator+(const Vertex& Vert) const {
	return Vertex(_X + Vert.GetX(), _Y + Vert.GetY(), _Z + Vert.GetZ());
}

const Vertex Vertex::operator-(const Vertex& Vert) const {
	return Vertex(_X - Vert.GetX(), _Y - Vert.GetY(), _Z - Vert.GetZ());
}

float Vertex::DotProduct(const Vertex& Vert) const {
	return _X * Vert.GetX() + _Y * Vert.GetY() + _Z * Vert.GetZ();
}

Vertex Vertex::CrossProduct(const Vertex& Vert) const {
	
	return Vertex(_Y * Vert.GetZ() - _Z * Vert.GetY(), _Z * Vert.GetX() - _X * Vert.GetZ(), _X * Vert.GetY() - _Y * Vert.GetX());
}
