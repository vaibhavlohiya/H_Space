#include <iostream>

#include "Scaler.h"

// Class Constructors

Scaler::Scaler(const double& DataPoint) : m_Value(DataPoint) {}

// Class Methods

double Scaler::Data() { return m_Value; }
const double Scaler::Data() const { return m_Value; }

Scaler Scaler::addition(const Scaler& other) { return Scaler(m_Value + other.m_Value); }
Scaler Scaler::subtract(const Scaler& other) { return Scaler(m_Value - other.m_Value); }
Scaler Scaler::multiply(const Scaler& other) { return Scaler(m_Value * other.m_Value); }
Scaler Scaler::divide(const Scaler& other) { return Scaler(m_Value / other.m_Value); }

// Class Operator Overloads

Scaler Scaler::operator+(const Scaler& other) { return addition(other); }
Scaler Scaler::operator-(const Scaler& other) { return subtract(other); }
Scaler Scaler::operator*(const Scaler& other) { return multiply(other); }
Scaler Scaler::operator/(const Scaler& other) { return divide(other); }

bool Scaler::operator==(const Scaler& other)
{
	if (m_Value == other.Data())
		return true;
	else
		return false;

	//m_Value == other.Data() ? true : false;
}

Scaler Scaler::operator+=(const Scaler& other) { return Scaler(m_Value += other.m_Value); }
Scaler Scaler::operator-=(const Scaler& other) { return Scaler(m_Value -= other.m_Value); }
Scaler Scaler::operator*=(const Scaler& other) { return Scaler(m_Value *= other.m_Value); }

std::ostream& operator<<(std::ostream& stream, const Scaler& S_out)
{
	stream << S_out.Data();

	return stream;
}
