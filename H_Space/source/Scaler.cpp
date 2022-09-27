#include <iostream>

#include "Scaler.h"

Scaler::Scaler(const float& DataPoint) : m_Data(DataPoint) {}

const float Scaler::Data() const { return m_Data; }

Scaler Scaler::Addition(const Scaler& other)
{
	return Scaler(m_Data + other.m_Data);
}

Scaler Scaler::operator+(const Scaler& other)
{
	return Scaler(m_Data + other.m_Data);
}

Scaler Scaler::Subtract(const Scaler& other)
{
	return Scaler(m_Data - other.m_Data);
}

Scaler Scaler::operator-(const Scaler& other)
{
	return Scaler(m_Data - other.m_Data);
}

Scaler Scaler::Multiply(const Scaler& other)
{
	return Scaler(m_Data * other.m_Data);
}

Scaler Scaler::operator*(const Scaler& other)
{
	return Scaler(m_Data * other.m_Data);
}

Scaler Scaler::Divide(const Scaler& other)
{
	return Scaler(m_Data / other.m_Data);
}

Scaler Scaler::operator/(const Scaler& other)
{
	return Scaler(m_Data / other.m_Data);
}

Scaler::~Scaler() {}