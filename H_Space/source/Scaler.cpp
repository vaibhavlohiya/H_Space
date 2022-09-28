#include "Scaler.h"

// Class Constructors

Scaler::Scaler(const float& DataPoint) : m_Value(DataPoint) {}

// Class Methods

const int Scaler::Data() const { return m_Value; }

Scaler Scaler::Addition(const Scaler& other) { return Scaler(m_Value + other.m_Value); }
Scaler Scaler::Subtract(const Scaler& other) { return Scaler(m_Value - other.m_Value); }
Scaler Scaler::Multiply(const Scaler& other) { return Scaler(m_Value * other.m_Value); }
Scaler Scaler::Divide(const Scaler& other) { return Scaler(m_Value / other.m_Value); }

// Class Operator Overloads

Scaler Scaler::operator+(const Scaler& other) { return Addition(other); }
Scaler Scaler::operator-(const Scaler& other) { return Subtract(other); }
Scaler Scaler::operator*(const Scaler& other) { return Multiply(other); }
Scaler Scaler::operator/(const Scaler& other) { return Divide(other); }

bool Scaler::operator==(const Scaler& other)
{
	if (m_Value == other.Data())
		return true;
	else
		return false;
}

Scaler Scaler::operator+=(const Scaler& other)
{
	this->m_Value += other.Data();

	return *this;
}

Scaler Scaler::operator-=(const Scaler& other)
{
	this->m_Value -= other.Data();

	return *this;
}

Scaler Scaler::operator*=(const Scaler& other)
{
	this->m_Value *= other.Data();

	return *this;
}