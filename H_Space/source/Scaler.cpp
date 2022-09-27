#include <iostream>

#include "Scaler.h"

Scaler::Scaler(const float& DataPoint) : m_Value(DataPoint) {}

const float Scaler::Data() const { return m_Value; }

Scaler Scaler::Addition(const Scaler& other)
{
	return Scaler(m_Value + other.m_Value);
}

Scaler Scaler::operator+(const Scaler& other)
{
	return Scaler(m_Value + other.m_Value);
}

Scaler Scaler::Subtract(const Scaler& other)
{
	return Scaler(m_Value - other.m_Value);
}

Scaler Scaler::operator-(const Scaler& other)
{
	return Scaler(m_Value - other.m_Value);
}

Scaler Scaler::Multiply(const Scaler& other)
{
	return Scaler(m_Value * other.m_Value);
}

Scaler Scaler::operator*(const Scaler& other)
{
	return Scaler(m_Value * other.m_Value);
}

Scaler Scaler::Divide(const Scaler& other)
{
	return Scaler(m_Value / other.m_Value);
}

Scaler Scaler::operator/(const Scaler& other)
{
	return Scaler(m_Value / other.m_Value);
}

Scaler::~Scaler() {}