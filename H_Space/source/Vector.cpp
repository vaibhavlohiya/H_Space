#include "Scaler.h"
#include "Vector.h"


// Class Constructors

Vector::Vector(const std::array<Scaler, m_Size>& Components)
	: m_VectorArray(Components)
{}

// Class Methods 

const size_t Vector::size() const { return m_Size; }

Vector Vector::Add(const Vector& other)
{	
	for (size_t i = 0; i < m_Size; i++)
		this->m_VectorArray[i] += other.m_VectorArray[i];

	return *this;
}

Vector Vector::Subtract(const Vector& other)
{
	for (size_t i = 0; i < m_Size; i++)
		this->m_VectorArray[i] -= other.m_VectorArray[i];

	return *this;
}

Scaler Vector::DotProduct(const Vector& other)
{
	Scaler S = {};

	for (size_t i = 0; i < m_Size; i++)
		S += m_VectorArray[i]*other.m_VectorArray[i];

	return S;
}

Vector Vector::CrossProduct(const Vector& other)
{
	Vector V = {};

	if (m_Size == 3)
	{
		V.m_VectorArray[0] = m_VectorArray[1] * other.m_VectorArray[2] - m_VectorArray[2] * other.m_VectorArray[1];
		V.m_VectorArray[1] = m_VectorArray[2] * other.m_VectorArray[0] - m_VectorArray[0] * other.m_VectorArray[2];
		V.m_VectorArray[2] = m_VectorArray[0] * other.m_VectorArray[1] - m_VectorArray[1] * other.m_VectorArray[0];
	}

	return V;
}

// Class Operator Overloads

Vector Vector::operator+(const Vector& other) { return Add(other); }
Vector Vector::operator-(const Vector& other) { return Subtract(other); }
Vector Vector::operator*(const Vector& other) { return CrossProduct(other); }

Scaler& Vector::operator[](size_t index) { return m_VectorArray[index]; }
const Scaler& Vector::operator[](size_t index) const { return m_VectorArray[index]; }

