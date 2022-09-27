#include "Scaler.h"
#include "Vector.h"


Vector::Vector(const std::array<Scaler, m_Size>& Components)
	: m_Data(Components)
{}

const size_t Vector::size() const { return m_Size; }

Vector Vector::Add(const Vector& other)
{
	Vector V = {};
	
	for (size_t i = 0; i < m_Size; i++)
		V.m_Data[i] = m_Data[i] + other.m_Data[i];

	return V;
}

Vector Vector::operator+(const Vector& other)
{
	Vector V = {};

	for (size_t i = 0; i < m_Size; i++)
		V.m_Data[i] = m_Data[i] + other.m_Data[i];

	return V;
}

Vector Vector::Subtract(const Vector& other)
{
	Vector V = {};

	for (size_t i = 0; i < m_Size; i++)
		V.m_Data[i] = m_Data[i] - other.m_Data[i];

	return V;
}

Vector Vector::operator-(const Vector& other)
{
	Vector V = {};

	for (size_t i = 0; i < m_Size; i++)
		V.m_Data[i] = m_Data[i] - other.m_Data[i];

	return V;
}

Scaler Vector::DotProduct(const Vector& other)
{
	Scaler S = {};

	for (size_t i = 0; i < m_Size; i++)
		S = S + m_Data[i] * other.m_Data[i];

	return S;
}

Vector Vector::CrossProduct(const Vector& other)
{
	Vector V = {};

	if (m_Size == 3)
	{
		V.m_Data[0] = m_Data[1] * other.m_Data[2] - m_Data[2] * other.m_Data[1];
		V.m_Data[1] = m_Data[2] * other.m_Data[0] - m_Data[0] * other.m_Data[2];
		V.m_Data[2] = m_Data[0] * other.m_Data[1] - m_Data[1] * other.m_Data[0];
	}
	
	return V;
}

Vector Vector::operator*(const Vector& other)
{
	Vector V = {};

	if (m_Size == 3)
	{
		V.m_Data[0] = m_Data[1] * other.m_Data[2] - m_Data[2] * other.m_Data[1];
		V.m_Data[1] = m_Data[2] * other.m_Data[0] - m_Data[0] * other.m_Data[2];
		V.m_Data[2] = m_Data[0] * other.m_Data[1] - m_Data[1] * other.m_Data[0];
	}

	return V;
}

Scaler& Vector::operator[](size_t index)
{
	return m_Data[index];
}

const Scaler& Vector::operator[](size_t index) const
{
	return m_Data[index];
}

